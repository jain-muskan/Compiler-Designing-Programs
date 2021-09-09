#include<stdio.h>
#include<conio.h>
#include<string.h>

char s[100],w[20],a[2];

char keywords[32][10]={"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char",
	"extern","return","union","const","float","short","unsigned","continue","for","signed","void","default",
	"goto","sizeof","voltile","do","if","static","while"} ;

void main()
{
       //	FILE *fp;
       int i=0;
	clrscr();

       printf("Enter a sentence");
	//scanf("%s",s);
	gets(s);
	while(strlen(s)>i)
	{
		while(s[i]!=' ' && i<strlen(s))
		{
			a[0]=s[i];
			strcat(w,a);
			i++;
		}
		if(isalpha(w[0])!=0 || w[0]=='_')
		{

		if(iskey()==0)
		printf("\n%s is KEYWORD",w);
		else if(isiden()==0)
		printf("\n%s is IDENTIFIER",w);
		else
		printf("\n%s is NOTHING",w);
		}
		else
		{
			printf("\n%s is nothing",w);
		}
		i++;
		strcpy(w,"");
	}



	getch();
}

int isiden()
{
int i=1;
		while(strlen(w)!=i)
		{
			if(isalnum(w[i])==0 && w[i]!='_')
			{
				return 1;
			}
			i++ ;
		}
	return 0;
}

int iskey()
{
int i;
	for(i=0;i<32;i++)
	{

		  if(strcmp(w,keywords[i])==0)
		  {
		       return 0;
		  }
	}
return 1;
}
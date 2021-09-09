#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main()

{
	char keywords[32][10]={"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char",
	"extern","return","union","const","float","short","unsigned","continue","for","signed","void","default",
	"goto","sizeof","voltile","do","if","static","while"} ;
	char fs[10],ch,istring[10]="",s[10]="";

	int nk=0,i;
	FILE *fp;

	 clrscr();

	fp=fopen("key.txt","r");

	while((ch=fgetc(fp))!=EOF)
	{

	       if(ch==' ' || ch=='\n'){
    //	       printf("\n%c",ch);

		for(i=0;i<32;i++)
		 {



		       if(strcmp(istring,keywords[i])==0)
		       {
		       nk++;
		       }
		}
		strcpy(istring,"");
		}




		else
		{
		printf("\n%c",ch);
		s[0]=ch;
		strcat(istring,s);
	     //	printf("\n%c",ch);
		}
	       //	string="";

	}
	fclose(fp);
	printf("\nNo. of keywords in a file:%d",nk);

	getch();

}

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct prod
{
	char l,r[5];
}p[10];
void FIND_FIRST(char );
int IsNt(char ch);
int EXISTS(int v,char ch);
int IsNullPresent(int ini,int fin);
void EnterFirsts(int v);
char first[15][10],NT[20],T[20],temp_first[15];
int np,t,n,tff,tf;

void main()
{
	int i,j,k,flag=0;
	clrscr();
	printf("Number Of Productions:");
	scanf("%d",&np);
	printf("\nProductions:\n");
	for(i=0;i<np;i++)
	{
		fflush(stdin);
		scanf("%c",&p[i].l);
		printf("->");
		scanf("%s",p[i].r);
	}
	clrscr();
	for(i=0;i<np;i++)
	{
		printf("%c->%s\n",p[i].l,p[i].r);
		for(k=0;k<n;k++)
		{
			if(NT[k]==p[i].l)
			flag=1;
		}
		if(flag!=1)
		{
			NT[n]=p[i].l;
			n++;
		}
		flag=0;
		for(j=0;j<strlen(p[i].r);j++)
		{
			if(isupper(p[i].r[j])==0)
			{
				for(k=0;k<t;k++)
				{
					if(T[k]==p[i].r[j])
					flag=1;
				}
				if(flag!=1)
				{
					T[t]=p[i].r[j];
					t++;
				}
				flag=0;
			}
		}

	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		tf=0;
		tff=0;
		strcpy(temp_first,"\0");
		printf("%c\t",NT[i]);
		FIND_FIRST(NT[i]);
		EnterFirsts(i);
		printf("\nFIRST");
		for(j=0;j<strlen(first[i]);j++)
		printf("%c\t",first[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<t;i++)
	{
		printf("%c",T[i]);
	}
	getch();
}

void FIND_FIRST(char cur_nt)
{
	int i=0,c,ss,s;

	while(i<np)
	{
		if(p[i].l==cur_nt)
		{
			printf("\t%d",i);
			c=0;
		       //	flag=0;
		       //	while(c<strlen(p[i].r) && flag!=1)
			//{
			if(IsNt(p[i].r[c])==0 && p[i].r[c]!='$')
			{

				temp_first[tf]=p[i].r[c];
				tf++;

				       //	flag=1;

			  }
			else if(p[i].r[c]=='$' && (p[i].r[c+1]=='\0' || p[i].r[c+1]=='#'))
			  {

				temp_first[tf]='$';
				tf++;
					//	flag=1;


			  }
			else
			{
				tff=tf;
				FIND_FIRST(p[i].r[c]);
				while((s=IsNullPresent(tff,tf))>=0 && c<strlen(p[i].r))
				{
					for(ss=s;ss<tf-1;ss++)
					temp_first[ss]=temp_first[ss+1];
					temp_first[ss]='\0';
					c++;
					tf--;
					tff=tf;
					FIND_FIRST(p[i].r[c]);

				}
			   //	flag=1;
			}
		   //	}

		}
		i++;

	}
}

int IsNt(char ch)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(NT[i]==ch)
		return 1;
	}
	return 0;
}

int EXISTS(int v,char ch)
{
	int i;
	for(i=0;i<strlen(first[v]);i++)
	{
		if(first[v][i]==ch)
		return 1;
	}
	return 0;
}

int IsNullPresent(int ini,int fin)
{
	int k;
	for(k=ini;k<fin;k++)
	{
		if(temp_first[k]=='$')
		return k;
	}
	return -1;
}

void EnterFirsts(int v)
{
	int i,c=0;
	for(i=0;i<strlen(temp_first);i++)
	{
		if(EXISTS(v,temp_first[i])!=1)
		{
			first[v][c]=temp_first[i];
			printf("\t%c",first[v][c]);
			c++;
		}
	}
	strcpy(temp_first,"\0");
	printf("\nTF=%s",temp_first);
	tff=0;
	tf=0;
	printf("\n%d %d",tf,tff);

}
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define true 1
#define false 0
struct prod
{
	char l,r[5];
}p[10];
void FIND_FIRST(char );
void FIND_FOLLOW(char,int);
int IsNt(char ch);
int EXISTS(int v,char ch);
int IsNullPresent(int ini,int fin);
int If_Nt_Exists(int,char);
void EnterFirsts(int v);
char first[15][10],NT[20],Te[20],temp_first[15],follow[15][10],firsted[10]={0},followed[10]={0};
int np,t,n,tff,tf,c=0;
//enum{E,P,T,H,F};
enum{S,A,B,D};

void main()
{
	int i,j,k,flag=0;
	clrscr();
 /*	np=8;
	p[0].l='E';
	strcpy(p[0].r,"TP");
	p[1].l='P';
	strcpy(p[1].r,"+TP");
	p[2].l='P';
	strcpy(p[2].r,"#");
	p[3].l='T';
	strcpy(p[3].r,"FH");
	p[4].l='H';
	strcpy(p[4].r,"*FH");
	p[5].l='H';
	strcpy(p[5].r,"#");
	p[6].l='F';
	strcpy(p[6].r,"(E)");
	p[7].l='F';
	strcpy(p[7].r,"i");
	strcpy(first[E],"i(");
	strcpy(first[P],"+#");
	strcpy(first[T],"i(");
	strcpy(first[H],"*#");
	strcpy(first[F],"i("); */
/*	printf("Number Of Productions:");
	scanf("%d",&np);
	printf("\nProductions:\n");
	for(i=0;i<np;i++)
	{
		fflush(stdin);
		scanf("%c",&p[i].l);
		printf("->");
		scanf("%s",p[i].r);
	}
*/      np=6;
	p[0].l='S';
	strcpy(p[0].r,"Aa");
	p[1].l='A';
	strcpy(p[1].r,"BD");
	p[2].l='B';
	strcpy(p[2].r,"b");
	p[3].l='B';
	strcpy(p[3].r,"#");
	p[4].l='D';
	strcpy(p[4].r,"d");
	p[5].l='D';
	strcpy(p[5].r,"#");
	strcpy(first[S],"bda");
	strcpy(first[A],"bd#");
	strcpy(first[B],"b#");
	strcpy(first[D],"d#");
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
					if(Te[k]==p[i].r[j])
					flag=1;
				}
				if(flag!=1)
				{
					Te[t]=p[i].r[j];
					t++;
				}
				flag=0;
			}
		}

	}
	printf("\n");
	for(i=0;i<n;i++)
	printf("%c",NT[i]);
     /*	FIND_FOLLOW(NT[0],0);
	follow[0][c]='\0';
      //	follow[0][c+1]='\0';
	for(j=0;j<strlen(follow[0]);j++)
	printf("%c\t",follow[0][j]);
	printf("\n");
	c=0;
	for(j=0;j<n;j++)
	{
		firsted[j]=0;
		followed[j]=0;
	}
	FIND_FOLLOW(NT[1],1);
	follow[1][c]='\0';
	for(j=0;j<strlen(follow[1]);j++)
	printf("%c\t",follow[1][j]);
	printf("\n");
     */	for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			firsted[j]=0;
			followed[j]=0;
		}
		c=0;
	       //	strcpy(temp_first,"\0");
	      //	printf("%c\t",NT[i]);
		FIND_FOLLOW(NT[i],i);
		follow[i][c]='\0';
	       //	EnterFirsts(i);
		printf("\nFOLLOW %c\t",NT[i]);
		for(j=0;j<strlen(follow[i]);j++)
		printf("%c\t",follow[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=0;i<t;i++)
	{
		printf("%c",Te[i]);
	}
	getch();
}



int IsNt(char ch)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(NT[i]==ch)
		return i;
	}
	return -1;
}

int If_Nt_Exists(int v,char ch)
{
	int i;
	for(i=0;i<strlen(p[v].r);i++)
	{
		if(p[v].r[i]==ch)
		return i;
	}
	return -1;
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

void FIND_FOLLOW(char cnt,int cnc)
{
	int i,k,pos,xnt,flag,yy;
	yy=IsNt(cnt);
	if(followed[yy]==0)
	{
	if(yy==0)
	{
		follow[cnc][c]='$';
		c++;
	}
	followed[yy]=1;

	for(i=0;i<np;i++)
	{
		pos=If_Nt_Exists(i,cnt);
		if(pos!=-1)
		{
		if(pos+1==strlen(p[i].r))
		FIND_FOLLOW(p[i].l,cnc);
		else
		{
			flag=true;
			while(pos<=strlen(p[i].r)-1 && flag==true)
			{
				flag=false;
				if(pos+1==strlen(p[i].r))
				{
					FIND_FOLLOW(p[i].l,cnc);
					pos++;
				}
				else
				{
					if(IsNt(p[i].r[pos+1])==-1 )
					{
						follow[cnc][c]=p[i].r[pos+1];
						c++;
					}
					else
					{
						xnt=IsNt(p[i].r[pos+1]);
						k=0;
						if(firsted[xnt]==0)
						{
						firsted[xnt]=1;
						while(k<strlen(first[xnt]))
						{
							if(first[xnt][k]!='#')
							{
							follow[cnc][c]=first[xnt][k];
							c++;
							}
							else
							flag=true;
							k++;

						}
						pos++;
						}
					}
				}

			}

		}
		}

	}
	}
}
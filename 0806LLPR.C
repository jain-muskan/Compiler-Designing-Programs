#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char nont[10],t[10],prod[10][10];
char fr[10][10],fl[10][10];
int np,nt=0,nnt=0;
int nfrs[10],nflw[10];
void init()
{
	int j;
	for(j=0;j<np;j++)
	nfrs[j]=nflw[j]=0;
}

void first(char cur,int i)
{
	int j,k,l;
	for(j=0;j<np;j++)
	{
		if(prod[j][0]==cur)
		{
			if(isupper(prod[j][2])==0)
			{
				fr[i][nfrs[i]]=prod[j][2];
				nfrs[i]++;
			}
			else if(prod[j][2]=='E'&&prod[j][3]=='\0')
			{
				fr[i][nfrs[i]]='E';
				nfrs[i]++;
			}
			else if(isupper(prod[j][2])!=0)
			{
				first(prod[j][2],i);
				if(prod[j][3]!='\0')
				{
					for(l=0;l<nfrs[i];l++)
					{
						if(fr[i][l]=='E')
						{
							fr[i][l]='\0';
							if(isupper(prod[j][3])==0)
							{
								fr[i][nfrs[i]]=prod[j][3];
								nfrs[i]++;
							}
							else
							first(prod[j][3],i);
							break;
						}
					}
				}
			}
		}
	}    //next prod
}

void follow(char cur,int i)
{
	int j,k,l,next;
	if(i==0)
	{
		fl[i][nflw[i]]='$';
		nflw[i]++;
	}
	for(j=0;j<np;j++)
	{
		for(k=2;k<strlen(prod[j]);k++)
		{
			if(prod[j][k]==cur)
			{
				if(k==strlen(prod[j])-1)
				{
					follow(prod[j][0],i);
				}
				if(isupper(prod[j][k+1])==0)
				{
					fl[i][nflw[i]]=prod[j][k+1];
					nflw[i]++;
				}
				else if(isupper(prod[j][k+1])!=0)
				{
					for(l=0;l<nnt;l++)
					{
						if(nont[l]==prod[j][k+1])
						{
							next=l;
							break;
						}
					}
					for(l=0;l<nfrs[next];l++)
					{
						if(fr[i][l]=='E')
						follow(prod[j][0],i);
						else
						{
							fl[i][nflw[i]]=fr[next][l];
							nflw[i]++;
						}
					}
				}
			}
		}
	}

}

void main()
{
	int i,j;
	clrscr();
//	printf("Number of productions: ");
//	scanf("%d",&np);
	printf("Productions\n");
	strcpy(prod[0],"S-Aa");
	strcpy(prod[1],"A-BD");
	strcpy(prod[2],"B-b");
	strcpy(prod[3],"B-E");
	strcpy(prod[4],"D-d");
	strcpy(prod[5],"D-E");
	np=6;
	init();
	for(i=0;i<np;i++)
	printf(" %s",prod[i]);
	for(i=0;i<np;i++)
	{
		int k=0,ins=0;
		while(prod[i][k]!='\0')
		{
			ins=0;
			if(isalpha(prod[i][k])==0)
			k++;
			else if(prod[i][k]=='E')
			k++;
			else if(isupper(prod[i][k])!=0)
			{
				for(j=0;j<nnt;j++)
				{
					if(nont[j]==prod[i][k])
					ins=1;
				}
				if(ins==0)
				{
					nont[nnt]=prod[i][k];
					nnt++;
				}
				k++;
			}
			else if(isupper(prod[i][k])==0)
			{
				for(j=0;j<nt;j++)
				{
					if(t[j]==prod[i][k])
					ins=1;
				}
				if(ins==0)
				{
					t[nt]=prod[i][k];
					nt++;
				}
				k++;
			}
		}
	}
	printf("\nTerminals");
	for(i=0;i<nt;i++)
	printf(" %c",t[i]);
	printf("\nNon terminals");
	for(i=0;i<nnt;i++)
	printf(" %c",nont[i]);
	printf("\n");
	for(i=nnt-1;i>=0;i--)
	{
		first(nont[i],i);
		follow(nont[i],i);
	}
	for(i=0;i<nnt;i++)
	{
		printf("\nFIRST %c: ",nont[i]);
		for(j=0;j<nfrs[i];j++)
		printf(" %c",fr[i][j]);
	}
	for(i=0;i<nnt;i++)
	{
		printf("\nFOLLOW %c: ",nont[i]);
		for(j=0;j<nflw[i];j++)
		printf(" %c",fl[i][j]);
	}
	getch();
}
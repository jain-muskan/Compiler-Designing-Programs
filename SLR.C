#include<stdio.h>
#include<conio.h>
#include<string.h>

struct table{
	int d;
	int f;
}stable[15][10];

struct tprod{
	char l;
	char r[10];
}prod[7];

int top,c;
char st[100],exp[20];
void CREATE_TABLE();
void parse();
void push(char);
void pop();


void main()
{
	int i,j,ll;
	clrscr();
	for(i=0;i<12;i++)
	{
		for(j=0;j<9;j++)
		{
			stable[i][j].d=-1;
			stable[i][j].f=-1;
		}
	}
	CREATE_TABLE();
/*	for(i=0;i<12;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d.%d ",stable[i][j]);
		}
		printf("\n");
	}
  */	printf("\nGive Expression:");
	scanf("%s",exp);
	ll=strlen(exp);
	printf("%d",ll);
	exp[ll]='$';
	exp[ll+1]='\0';
	printf("%d",strlen(exp));
	st[0]='$';
	st[1]='0';
	top=1;
	parse();
	getch();

}

int map(char ch)
{
	if(ch=='i')
	return 0;
	else if(ch=='+')
	return 1;
	else if(ch=='*')
	return 2;
	else if(ch=='(')
	return 3;
	else if(ch==')')
	return 4;
	else if(ch=='$')
	return 5;
	else if(ch=='E')
	return 6;
	else if(ch=='T')
	return 7;
	else if(ch=='F')
	return 8;
	else
	return -1;


}

void parse()
{
	int mp,tp,i;
	while(1)
	{
	tp=st[top]-'0';

	mp=map(exp[c]);
	printf("\ntp=%d\tmp=%d",tp,mp);
	if(stable[tp][mp].f==1)
	{
		push(exp[c]);
	      //	printf("\n%d %c",stable[tp][mp].d,stable[tp][mp].d+'0');
		push(stable[tp][mp].d+'0');
		c++;
	}
	else if(stable[tp][mp].f==2)
	{
		if(stable[tp][mp].d!=0)
		{
		for(i=0;i<strlen(prod[stable[tp][mp].d].r);i++)
		{
			pop();
			pop();
		}
		push(prod[stable[tp][mp].d].l);
		mp=map(st[top]);
		tp=st[top-1]-'0';
		push(stable[tp][mp].d+'0');
		}
		else
		{
			printf("\nstring accepted");
			break;
		}

	}
	else
	{
		printf("\n$$$$$$$$$");
		break;
	}
	}
}

void push(char ch)
{
	top++;
	st[top]=ch;
	printf("\nPUSH:%c",ch);
}

void pop()
{
	printf("\nPOP:%c",st[top]);
	st[top]='\0';
	top--;
}

void CREATE_TABLE()
{
	prod[0].l='@';
	strcpy(prod[0].r,"E");
	prod[1].l='E';
	strcpy(prod[1].r,"E+T");
	prod[2].l='E';
	strcpy(prod[2].r,"T");
	prod[3].l='T';
	strcpy(prod[3].r,"T*F");
	prod[4].l='T';
	strcpy(prod[4].r,"F");
	prod[5].l='F';
	strcpy(prod[5].r,"(E)");
	prod[6].l='F';
	strcpy(prod[6].r,"i");


	stable[0][0].d=5;
	stable[0][0].f=1;
	stable[0][3].d=4;
	stable[0][3].f=1;
	stable[0][6].d=1;
	stable[0][6].f=0;
	stable[0][7].d=2;
	stable[0][7].f=0;
	stable[0][8].d=3;
	stable[0][8].f=0;

	stable[1][1].d=6;
	stable[1][1].f=1;
	stable[1][5].d=0;
	stable[1][5].f=2;

	stable[2][1].d=2;
	stable[2][1].f=2;
	stable[2][2].d=7;
	stable[2][2].f=1;
	stable[2][4].d=2;
	stable[2][4].f=2;
	stable[2][5].d=2;
	stable[2][5].f=2;

	stable[3][1].d=4;
	stable[3][1].f=2;
	stable[3][2].d=4;
	stable[3][2].f=2;
	stable[3][4].d=4;
	stable[3][4].f=2;
	stable[3][5].d=4;
	stable[3][5].f=2;

	stable[4][0].d=5;
	stable[4][0].f=1;
	stable[4][3].d=4;
	stable[4][3].f=1;
	stable[4][6].d=8;
	stable[4][6].f=0;
	stable[4][7].d=2;
	stable[4][7].f=0;
	stable[4][8].d=3;
	stable[4][8].f=0;

	stable[5][1].d=6;
	stable[5][1].f=2;
	stable[5][2].d=6;
	stable[5][2].f=2;
	stable[5][4].d=6;
	stable[5][4].f=2;
	stable[5][5].d=6;
	stable[5][5].f=2;


	stable[6][0].d=5;
	stable[6][0].f=1;
	stable[6][3].d=4;
	stable[6][3].f=1;
	stable[6][7].d=9;
	stable[6][7].f=0;
	stable[6][8].d=3;
	stable[6][8].f=0;

	stable[7][0].d=5;
	stable[7][0].f=1;
	stable[7][3].d=4;
	stable[7][3].f=1;
	stable[7][8].d=10;
	stable[7][8].f=0;

	stable[8][1].d=6;
	stable[8][1].f=1;
	stable[8][4].d=11;
	stable[8][4].f=1;

	stable[9][1].d=1;
	stable[9][1].f=2;
	stable[9][2].d=7;
	stable[9][2].f=1;
	stable[9][4].d=1;
	stable[9][4].f=2;
	stable[9][5].d=1;
	stable[9][5].f=2;

	stable[10][1].d=3;
	stable[10][1].f=2;
	stable[10][2].d=3;
	stable[10][2].f=2;
	stable[10][4].d=3;
	stable[10][4].f=2;
	stable[10][5].d=3;
	stable[10][5].f=2;

	stable[11][1].d=5;
	stable[11][1].f=2;
	stable[11][2].d=5;
	stable[11][2].f=2;
	stable[11][4].d=5;
	stable[11][4].f=2;
	stable[11][5].d=5;
	stable[11][5].f=2;



}

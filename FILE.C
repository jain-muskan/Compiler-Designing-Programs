#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	FILE *fp;
	int w=0,s=0,l=0;
	char ch;
	clrscr();
	fp=fopen("demo.txt","r");
	while(!feof(fp))
	{
		ch=fgetc(fp);
		putc(ch,stdout);
		if(ch=='\n')
		{
			l++;
			w++;
		}
		if(ch==' ')
		{
			w++;
			s++;
		}
	}
	w++;
	l++;
	fclose(fp);
	printf("\nNo. of words:%d\nNo. of Spaces:%d\nNo, of Lines:%d",w,s,l);
	getch();

}
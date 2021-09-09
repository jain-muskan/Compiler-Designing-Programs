#include<stdio.h>
#include<conio.h>

void main()
{
	char s[100];
	int i=0,vc=0,cc=0;
	clrscr();
	printf("Enter a Sentence:");
	gets(s);
	while(i!=strlen(s))
	{
		if (checkv(tolower(s[i]))==1)
		vc++;
		else if(!checkv(tolower(s[i])) && isalpha(s[i]) )
		cc++;
		else
		{}
		i++;
	}

	printf("\nNo. Of Vowels:%d",vc);
	printf("\nNo. Of Consonants:%d",cc);
	getch();

}

int checkv(char x)
{
	if(x=='a' || x=='e' || x=='i'|| x=='o' || x=='u')
	return 1;
	return 0;
}

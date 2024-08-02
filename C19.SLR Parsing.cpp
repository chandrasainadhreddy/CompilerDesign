#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int act_shift[10][3]=
   				{{3,4,0},{0,0,0},{6,7,0},{3,4,0},{0,0,0},
{0,0,0},{6,7,0},{0,0,0},{0,0,0},{0,0,0}};
	int act_reduce[10][3]=
   				{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{3,3,0},
{0,0,1},{0,0,0},{0,0,3},{2,2,0},{0,0,2}};
	int got[10][2]={{1,2},{0,0},{0,5},{0,8},{0,0},
    {0,0},{0,9},{0,0},{0,0},{0,0}};
	char stack[20],input[20],temp[2],c[2];
	int i,l,t,nt,s,r,j,g,top,state,b;
	clrscr();
	stack[0]='0';
	stack[1]='\0';
	printf("Enter the input string : ");
	scanf("%s",input);
	l=strlen(input);
	input[l]='$';
	input[l+1]='\0';
	i=0;
	printf("STACK\tINPUT\tACTION\n");
	printf("--------------------------------------------\n");
	printf("%s\t%s\tINITIAL CONFIGURATION\n",stack,input);
	while(!(stack[i]=='1'&&input[0]=='$'))
	{
		switch(input[0])
		{
			case 'c': t=0;break;
			case 'd': t=1;break;
			case '$': t=2;break;
		}
		c[0]=stack[i];
		c[1]='\0';
		state=atoi(c);
		s=act_shift[state][t];
		r=act_reduce[state][t];
		if(s!=0)
		{
			stack[++i]=input[0];
			itoa(s,temp,10);
			stack[++i]=temp[0];
			stack[i+1]='\0';
			l=strlen(input);
			for(j=0;j<l-1;j++)
			{
				input[j]=input[j+1];
			}
			input[l-1]='\0';
			printf("%s\t%s\tSHIFT\n",stack,input);
		}
		else if(r!=0)
		{
			switch(r)
			{
				case 1: b=2;break;
				case 2: b=2;break;
				case 3: b=1;break;
			}
			for(j=0;j<(2*b);j++)
			{
				i--;
			}
			c[0]=stack[i];
			c[1]='\0';
			top=atoi(c);
			if(r==1)
			{
				stack[++i]='S';
				nt=0;
			}
			else
			{
				stack[++i]='C';
				nt=1;
			}
			g=got[top][nt];
			itoa(g,temp,10);
			stack[++i]=temp[0];
			stack[i+1]='\0';
			printf("%s\t%s\tREDUCE\n",stack,input);
		}
		else
		{
			printf("Not a Sentence");
			goto a;
		}
	}
	printf("%s\t%s\tACCEPT\n",stack,input);
	printf("SENTENCE\n");
	a:
}
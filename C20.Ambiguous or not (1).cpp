#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],c[100];
    printf("enter the productions:\n");
    printf("production 1:\n");
    scanf("%s",a);
    printf("production 2:");
    scanf("%s",b);
    printf("production c:");
    scanf("%s",c);
    if(a[0]==a[3] && a[0]==a[5])
    {
        printf("ambiguous");
    }
    else
    {
        printf("not ambiguos");
}
	return 0;
}
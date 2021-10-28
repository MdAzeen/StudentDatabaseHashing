#ifndef password
#include<stdio.h>
#include<conio.h>
 char *userid()
{
    static char userid[60];
    printf("Enter Admin id:\n");
    scanf("%s",userid);
    return userid;
}
 char *pass()
{
   static char passwor[60];
    printf("Password:\n");
    int p=0;
    do
    {
        passwor[p]=getch();
        if(passwor[p]!='\r')
        {
            printf("*");
        }
        p++;
    }while(passwor[p-1]!='\r');
    passwor[p-1]='\0';
    return passwor;
    
}
#define password
#endif
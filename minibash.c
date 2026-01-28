#include<stdio.h>
#include<string.h>
#define max 1024

int main()
{
    char input[max];
    while(1)
    {
        char *argv[100];
        printf("minibash$:");
        fgets(input,max,stdin);
        printf("you typed %s",input);
        int i=0;
        argv[i]=strtok(input," ");
        while(argv[i]!=NULL)
        {
            i++;
            argv[i]=strtok(NULL," ");
        }     
        for(int j=0;j<i;j++)
        {
            printf("%s",argv[j]);
        }
    }
    return 0;
}
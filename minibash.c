#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#define max 1024

int main()
{
    char *input=malloc(max*sizeof(char));
    while(1)
    {
        char *args[100];
        printf("minibash$");
        fgets(input,max,stdin);
        input[strcspn(input,"\n")]='\0';
        int i=0;
        args[i]=strtok(input," ");
        while(args[i]!=NULL)
        {
            i++;
            args[i]=strtok(NULL," ");
        }
        pid_t pid=fork();
        if(pid==0)
        {
            execvp(args[0],args);
            perror("Exec failed");         
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}
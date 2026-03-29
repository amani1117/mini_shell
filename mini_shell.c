#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdbool.h>
int main(int argc, char* argv[])
{
    while(true)
    {
    char s[100],cmd[100][100];
    char* args[100];
    printf("Enter a command:(type exit to exit) \n");
    if(fgets(s,sizeof(s),stdin)==NULL)
    exit(0);
        int i=0,j=0,k=0;
    if(strcmp(s,"exit\n")==0)
    exit(0);
    while(s[i]!='\0')
    {
        if(s[i]=='\n')
        {
            if(k>0)
            cmd[j][k]='\0';
            break;
        }
        else if(s[i]!=' ')
        {
            cmd[j][k]=s[i];
           k++;
        }   
        else
        {
        if(k>0)
        {         
        cmd[j][k]='\0';
        j++;
        k=0;
        }
        }
      i++;  
    }
    if(j==0&&k==0)
    continue;
    j++;
    for(int a=0;a<j;a++)
    {
        args[a]=cmd[a];
    }
    args[j]=NULL;
    if(strcmp(args[0],"cd")==0)
    {
        if(args[1]!=NULL)
        {
        if(chdir(args[1])!=0)
        perror("cd failed");
        }
        else
        printf("cd: missing path\n");
        continue;
    }
    
   int id=fork();
   if(id<0)
   {
    perror("fork failed");
    continue;
   }
   else if(id>0)
   {
    wait(NULL);
   }
   
   else
   {
    execvp(args[0],args);
    perror("exec failed");
    exit(1);
   }
   memset(cmd, 0, sizeof(cmd));
    }
}
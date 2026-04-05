#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
if(strcmp(argv[1],"add")==0)
{
    int maxID=0, currentID=0;
    int a=2;
  FILE *fptr;
  fptr=fopen("todoList.txt","r");
  char line[100];
  while(fgets(line,sizeof(line),fptr)!=NULL)
  {
    sscanf(line,"%d",&currentID);
    if(currentID>maxID)
    maxID=currentID;
  }
  fclose(fptr);

  fptr=fopen("todoList.txt","a");
  if(fptr==NULL)
  {
  printf("Error file opening");
  return 1;
  }
  fprintf(fptr,"%d ",maxID+1);
  while(argv[a]!=NULL)
  {
    
    fprintf(fptr,"%s",argv[a]);
    fprintf(fptr," ");
    a++;
  }
  fprintf(fptr,"\n");
  fclose(fptr);
}
else if(strcmp(argv[1],"show")==0)
{
    FILE *fptr=fopen("todoList.txt","r");
    char buffer[100];
    if(fptr==NULL)
    {
  printf("Error file opening");
  return 1;
  }
    while(fgets(buffer,sizeof(buffer),fptr)!=NULL)
    {
        printf("%s",buffer);
    }
    fclose(fptr);
}
else if(strcmp(argv[1],"remove")==0)
{
    FILE *fptr=fopen("todoList.txt","r");
    char buffer[100][100];
    if(fptr==NULL)
    {
  printf("Error file opening");
  return 1;
  }
  int remID,count=0;
    while(fgets(buffer[count],sizeof(buffer[count]),fptr)!=NULL)
    { 
      count++;
    }
    fclose(fptr);
    FILE *fptr1=fopen("todoList.txt","w");
      if(fptr1==NULL)
    {
  printf("Error file opening");
  return 1;
  }
  remID=atoi(argv[2]);
  
  for(int i=0;i<count;i++)
  {
    int m;
    sscanf(buffer[i],"%d",&m);
    if(m!=remID)
    fprintf(fptr1,"%s", buffer[i]);
  }
  fclose(fptr1);
}
else if(strcmp(argv[1],"clear")==0)
{
    FILE* fptr=fopen("todoList.txt","w");
    fclose(fptr);
}
else
{
    printf("Invalid command");
}
return 0;
}
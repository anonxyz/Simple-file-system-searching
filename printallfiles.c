#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>

void listfiles(char basepath[]);
int main()
{
    char basepath[100];
    printf("please put in the path you want : ");
    scanf("%s",basepath);
    listfiles(basepath);
}
void listfiles(char basepath[])
{
char path[1000];
struct dirent *dp;
DIR *dir=opendir(basepath);
    if(!dir)
    {

    return;
        }
    while((dp=readdir(dir))!=NULL)
    {
        if(strcmp(dp->d_name,".")!=0&&strcmp(dp->d_name,"..")!=0)
       {
         printf("[+]%s\n",dp->d_name);
        strcpy(path,basepath);
        strcat(path,"/");
        strcat(path,dp->d_name);
        listfiles(path);
       }
    }
closedir(dir);
}

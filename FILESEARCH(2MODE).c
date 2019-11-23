#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>

void listfiles(char basepath[],int select,char pattern[100]);
int main()
{
    char basepath[100];
    char pattern[100];
    int const select;
    printf("please put in the path you want : ");
    scanf("%s",basepath);
    printf("What do you want to search for?\n");
    printf("1.Print all files recursively!Starting where you specified.\n");
    printf("2.Print all the files with extension \n");
    scanf("%d",&select);
    if(select==2)
    {
        printf("What is the extension you want to search for?\n");
        scanf("%s",pattern);
    }
    listfiles(basepath,select,pattern);
}
void listfiles(char basepath[],int select,char pattern[100])
{
char str[100]="";
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
        if(select==1)
        {
            printf("[+]%s     \n",dp->d_name);
            strcpy(path,basepath);
        strcat(path,"/");
        strcat(path,dp->d_name);
        listfiles(path,select,pattern);
        }
        if(select==2)                                                           //ADD RECURSVIVE IN THIS.
        {
            int dirlen=strlen(dp->d_name);
            int patternlen=strlen(pattern);
            int i;
            int j;
            for(i=0,j=1;i<patternlen;i++,j++)
            {
                str[i]=dp->d_name[dirlen-j];

            }
            if(strcmp(strrev(str),pattern)==0)
            {
                printf("%s\n",dp->d_name);
            }


            strcpy(path,basepath);
            strcat(path,"/");
            strcat(path,dp->d_name);
            listfiles(path,select,pattern);

        }                                                                        //if(select==3) then do exact pattern matching using strcmp and then print the dirpath
       }
    }
closedir(dir);
}

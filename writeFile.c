
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
struct student
{
    int Rollno;
    char Name[20];
    int Marks;
};

void FileWrite(char *name)
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    printf("Enter number of students");
    scanf("%d",&size);
    
    for(i = 1; i <= size; i++)      // while(Head!= NULL)
    {
        printf("Enter roll number\n");
        scanf("%d",&sobj.Rollno);
        printf("Enter Name of student\n");
        scanf("%s",&sobj.Name);
        printf("Enter marks\n");
        scanf("%d",&sobj.Marks);
        
        write(fd,&sobj,sizeof(sobj));   // write(fd,Head,sizeof(Node));
    }
    close(fd);
}


int main()
{
    char name[20];
    char cname[20];
    char ch = '\0';
    int marks = 0;
    printf("Enter file name\n");
    scanf("%s",name);
    
    FileWrite(name);



  return 0;
}
//  Accept file name, from user and write information of student into the file.

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

/*void FileWrite(char *name)
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
*/
void FileRead(char *name)
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    
    printf("Data from file is : \n");
    
    while((ret = read(fd,&sobj,sizeof(sobj)))!= 0)
    {
        printf("Roll number is : %d\n",sobj.Rollno);
        printf("Name of student : %s\n",sobj.Name);
        printf("Marks : %d\n",sobj.Marks);
    }
    
    close(fd);
}


void FileReadName(char *name)
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    
    printf("Data from file which Contains Only Name  is : \n");
    
    while((ret = read(fd,&sobj,sizeof(sobj)))!= 0)
    {
         printf("Name of student : %s\n",sobj.Name);
 
    }
    
    close(fd);
}

void FileReadMarks(char *name)
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    
    printf("Data from file which Contains Only Name  is : \n");
    
    while((ret = read(fd,&sobj,sizeof(sobj)))!= 0)
    {
         printf("Marks  of student : %d\n",sobj.Marks);
 
    }
    
    close(fd);
}

void FileReadAddMarks(char *name)
{
    int fd = 0 ,i = 0 , ret = 0 , size = 0 , iSum = 0;
    struct student sobj;

    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Data From the File is : \n");

    while((ret = read(fd,&sobj,sizeof(sobj)))!=0)
    {
        iSum = iSum + sobj.Marks;

        
    }
    printf("Addition of Marks is : %d",iSum);

    close(fd);
}

void FileReadNameInfo(char *name ,char *cname)
{
     int fd = 0 ,i = 0 , ret = 0 , size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    
    while((ret = read(fd,&sobj,sizeof(sobj)))!=0)
    {
       
            
              result= strcmp(sobj.Name ,cname);
                if(result == 0)
                {
                         printf("Roll number is : %d\n",sobj.Rollno);
                         printf("Name of student : %s\n",sobj.Name);
                        printf("Marks : %d\n",sobj.Marks);
                }

            
        
    }
        
    
             
    close(fd);
}
int main()
{
    char name[20];
    char cname[20];
    printf("Enter file name\n");
    scanf("%s",name);
    
  // FileWrite(name);
    
    FileRead(name);

    FileReadName(name);

    FileReadMarks(name);

    FileReadAddMarks(name);

    printf("\nEntre Name to get Information\n");
    scanf("  %[^'\n']s",cname);

    FileReadNameInfo(name,cname);
    
    return 0;
}




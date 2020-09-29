

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
struct student    //struct Containg char array to store the Name of student , int Roll no for Roll No , int Marks For Marks.
{
    int Rollno;
    char Name[20];
    int Marks;
};

void FileWrite(char *name)   //Function to Write the write Info  in the file.
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_WRONLY);  // open the File in Write only Mode.
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    printf("Enter number of students");
    scanf("%d",&size);
    
    for(i = 1; i <= size; i++)      
    {
        printf("Enter roll number\n");
        scanf("%d",&sobj.Rollno);
        printf("Enter Name of student\n");
        scanf("%s",&sobj.Name);
        printf("Enter marks\n");
        scanf("%d",&sobj.Marks);
        
        write(fd,&sobj,sizeof(sobj));   // Write the information on to the File.
    }
    close(fd); //After writing close the File.
}

void FileRead(char *name)    // Read and Display the info From destination File
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


void FileReadName(char *name)    // Display only names From Destination File
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

void FileReadMarks(char *name)  //Display the Marks of Student From destination File
{
    int fd = 0, ret = 0, size = 0, i = 0;
    struct student sobj;
    
    fd = open(name,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return ;
    }
    
    printf("Data from file which Contains Marks is : \n");
    
    while((ret = read(fd,&sobj,sizeof(sobj)))!= 0)
    {
         printf("Marks  of student : %d\n",sobj.Marks);
 
    }
    
    close(fd);
}
 
void FileReadAddMarks(char *name)  // Addition of Marks From Destination File
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

void FileReadNameInfo(char *name ,char *cname)  // Take Name From User and Display the Info of that Name from Destination File
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
void FileReadNameChar(char *name ,char ch)  // Take a Char From user and Dislpay Names which start From that Char from Destination File
{
    int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        for(i=0;i<ret;i++)
        {
            if(sobj.Name[i]==ch)
            {
                 printf("%s\t",sobj.Name);
            }
        }
        
    }
 printf("\n");
             
    close(fd);
}
void FileReadDisplayMarksGreater(char *name)  // Display the Name  of Student who has  Marks >=90 From the Destinatiojnn File
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        for(i=0;i<ret;i++)
        {
            if(sobj.Marks>=90)
            {
                 printf("%s\t",sobj.Name);
            }
        }
        
    }
    printf("\n");
    close(fd);






}

void  FileReadDisplayNameLength(char *name)   //Display the Name of that Student whoes lenght of name is >=6 from Destination File
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        for(i=0;i<ret;i++)
        {
            while(sobj.Name[j] != '\0')
            {
                result++;
                j++;
            }
            if(result>6)
            {
                printf("%s\t",sobj.Name);
            }
            result = 0;
            j=0;
        }
        
    }
    printf("\n");
    close(fd);






}


void  FileReadDisplayStudentByMarks(char *name,int marks) //Take a Mark From User and Display the Names of that student who has same Marks from Destination File 
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        for(i=0;i<ret;i++)
        {
            if(sobj.Marks==marks)
            {
                printf("%s\t",sobj.Name);
            }
        }
        
    }
    printf("\n");
    
    close(fd);






}

void FileReadDisplayHighestMarks(char *name)  //Display the Info of Highest  Marks from Destination File
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        
        for(i=0;i<ret;i++)
        {
            if(sobj.Marks>size)
            {
                size = sobj.Marks;
            }
             if(sobj.Marks==size)
             {
                 printf("%s\t",sobj.Name);
             }
        }
       
            
    }
    printf("\n");
    printf("Highr marks is : \n");
    
    close(fd);


}
void FileReadDisplayLowestMarks(char *name)   ////Display the Info of Student having Lowest Marks from Destination File
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        
        for(i=0;i<ret;i++)
        {
            if(sobj.Marks<size)
            {
                size = sobj.Marks;
            }
             if(sobj.Marks==size)
             {
                 printf("%s\t",sobj.Name);
             }
        }
       
            
    }
    printf("\n");
    printf("Highr marks is : \n");
    
    close(fd);


}
void FileReadDisplayAvgMarks(char *name)
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        
        for(i=0;i<ret;i++)
        {
           iSum = iSum + sobj.Marks;
        }
       ret++;
            
    }
    printf("\n");
    printf("Avarage Marks is : %d\n",(iSum/ret));
    
    close(fd);


}

void FileReadDisplayEvenMarks(char *name)     //Display the student Name having Even Marks
{
     int fd = 0 ,i = 1 ,j=0, ret = 0 ,iret = 0, size = 0 , iSum = 0 ,result = 0;
    struct student sobj;

   
    fd = open(name,O_RDONLY);
    if(fd  == -1)
    {
        printf("Unable to open the file \n");
        return ;
    }
    printf("Information from file of Given name is : \n");

    while(ret = read(fd,&sobj,sizeof(sobj))!=0)
    {
        
        for(i=0;i<ret;i++)
        {
           if(sobj.Marks %2 ==0 )
           {
               printf("%s\t",sobj.Name);
           }
        }
       ret++;
            
    }
    printf("\n");
    printf("Avarage Marks is : %d\n",(iSum/ret));
    
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
    
    FileRead(name);

    FileReadName(name);

    FileReadMarks(name);

    FileReadAddMarks(name);

    printf("\nEntre Name to get Information\n");
    scanf(" %[^'\n']s",cname);

    FileReadNameInfo(name,cname);
    printf("Entre the character \n");
    scanf("  %c",&ch);    

     FileReadNameChar(name,ch);

     FileReadDisplayMarksGreater(name);

     FileReadDisplayNameLength(name);

    printf("Entre the Marks\n");
    scanf("%d",&marks);

    FileReadDisplayStudentByMarks(name,marks);

    FileReadDisplayHighestMarks(name);
    
    FileReadDisplayLowestMarks(name);

     FileReadDisplayAvgMarks(name);

     FileReadDisplayEvenMarks(name);


    return 0;
}

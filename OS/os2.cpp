#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<iostream>
#include<time.h>
using namespace std;

int main(int argc,char* argv[])
{
    char MY_TIME[50];
    struct stat s1;
    int fd;

    if(argc!=2)
    {
        printf("Wrong number of arguments");
        exit(0);
    }

    fd=open(argv[1],O_RDONLY);
    fstat(fd,&s1);
    
    cout<<"Owner id="<<s1.st_uid<<"\n";
    cout<<"Group id="<<s1.st_gid<<"\n";
    cout<<"Access Permissions ="<<s1.st_mode<<"\n";
    cout<<"Size ="<<s1.st_size<<"\n";
    cout<<"Links ="<<s1.st_nlink<<"\n";
    
    strftime(MY_TIME,sizeof(MY_TIME),"%d.%m.%Y.%H.%M.%S", localtime(&s1.st_atime));
    cout<<"Last accessed at "<<MY_TIME<<"\n";
    
    strftime(MY_TIME,sizeof(MY_TIME),"%d.%m.%Y.%H.%M.%S", localtime(&s1.st_mtime));
    cout<<"Last modified at "<<MY_TIME<<"\n";
    
    return 0;
}
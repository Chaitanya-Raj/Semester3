#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main()
{
    pid_t pid;

    pid = fork();
    cout<<"1pid is "<<pid;
    cout<<endl<<"1get_pid is "<<getpid()<<endl;
    
    if(pid<0)
    {
        cout<<endl<<"this is a process ... "<<endl;
        cout<<"2pid is "<<pid;
        cout<<endl<<"2getpid is "<<getpid()<<endl;
    }
    else
    {
        cout<<endl<<"process continues..."<<endl;
        cout<<"3pid is "<<pid;
        cout<<endl<<"3getpid is "<<getpid()<<endl;
    }
    
    return 0;
}
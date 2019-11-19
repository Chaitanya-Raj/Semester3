#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    pid_t pid;
    int msize = 20;
    char msg[] = "\nMessage Passing\n";
    char buf[msize];
    int p[2];

    int a = pipe(p);
    if (a < 0)
        exit(1);
    
    pid = fork();
    if (pid == 0)
    {
        read(p[0], buf, msize);
        cout << "\nChild Process " << pid;
    	close(p[0]);    
    }
    else if (pid > 0)
    {
        write(p[1], msg, msize);
        cout << "\nParent Process " << pid;
        close(p[1]);
    }
    else
    {
        cout << "Unable to create child process";
    }
    
    cout << buf << endl;
    
    return 0;
}
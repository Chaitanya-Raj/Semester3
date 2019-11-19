//Practical 2 - exponentiation (recursion)

#include<iostream>
using namespace std;

int rec(int b, int r)
{
    if(r==0)
        return 1;
    else
        return b*rec(b,r-1);
}

int main()
{
    int b,r;
    cout<<"\nEnter the base : ";
    cin>>b;
    cout<<"\nEnter the exponent : ";
    cin>>r;
    cout<<"\n"<<b<<" raised to the power "<<r<<" is "<<rec(b,r);
    return 0;
}
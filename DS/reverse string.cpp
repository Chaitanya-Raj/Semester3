#include<iostream>
#include<conio.h>
using namespace std;
string rev(string s,int i,int j)
{
	if((i==j)||(i>j))
	return s;
	else
	{
		char c=s[i];
		s[i]=s[j];
		s[j]=c;
		return rev(s,++i,--j);
	}
}
int main()
{
	string s1;
	cout<<"enter a string which you want to reverse"<<endl;
	cin>>s1;
	int len=s1.length()-1;
	string result=rev(s1,0,len);
	cout<<"reversed string is "<<result;
	getch();
	return 0;
}

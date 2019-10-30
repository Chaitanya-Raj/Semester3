#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class stopandwait
{
	long int frame[20];
	int n,sq,ack,z;
	public:
		stopandwait()
		{
			sq=0;
			z=1;
		}
		void input()
		{
			cout<<"enter total no. of frame to be send:";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"\nenter data in  frame"<<i<<" :";
				cin>>frame[i];
			}
			sender(0);
		}
	   void sender(int timer)
	   {
	   	cout<<"\n\nSENDER :\n\n";
	   	if(timer==-1)
	   	{
	   		cout<<"timer stopped ,ACKNOWLEDGEMENT not received ";
		  }
		  cout<<"\nframe sent to reciever is:"<<z<<"\nand data in frame is :"<<frame[z];
		  cout<<"\nsequence no. is:"<<sq;
		  getch();
		  if(z>n)
		  {
		  	
		  }
		  else
		  {
		  	receiver(z,sq);
		  }
		   }
		   void receiver(int y,int sq)
		   {
		   	 int r=(rand()%3)+1;
		   	 cout<<"\n\nRECEIVER\n\n";
		   	 switch(r)
		   	 {
		   	 	case 1:{
		   	 		cout<<"\nframe "<<y<<"received with data"<<frame[y];
		   	 		cout<<"sequence no. is:"<<sq<<"\nPACKET RECEIVED SUCESSFULLY.";
		   	 		cout<<"\nACKNOWLEDGEMENT SENT:";
		   	 		z+=1;
		   	 		sq=(sq+1)%2;
		   	 		sender(0);
						break;
					}
				case 2:{
					cout<<"\nframe "<<y<<"received with data"<<frame[y];
		   	 		cout<<"sequence no. is:"<<sq<<"\nPACKET RECEIVED SUCESSFULLY.";
		   	 		cout<<"\nACKNOWLEDGEMENT SENT:";
		   	 		sender(-1);
					break;
				}
				case 3:{
					cout<<"\nframe lost\nsequence no. is:"<<sq;
					cout<<"\nnegative acknowledgement send.";
					sender(0);
					break;
				}
				}
			   }	
}obj;
int main()
{
	obj.input();
	getch();
	return 0;
}






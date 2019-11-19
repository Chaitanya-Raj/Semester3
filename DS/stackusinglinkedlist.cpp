#include <iostream>
using namespace std;
struct node
{
	int info;
	node *next;
};
class linkedlist
{
	node *top;

public:
	linkedlist();
	void push(int);
	void pop();
	void peak();
	void clear();
	void display();
};
int main()
{
	linkedlist ob;
	int choice, x;
	char ch;
	do
	{
		cout << "Enter the choice among the following" << endl;
		cout << "1 for push" << endl;
		cout << "2 for pop" << endl;
		cout << "3 for peak" << endl;
		cout << "4 for clearing the stack" << endl;
		cout << "5 for displaying the stack" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the element to be inserted" << endl;
			cin >> x;
			ob.push(x);
			break;
		case 2:
			ob.pop();
			break;
		case 3:
			ob.peak();
			break;
		case 4:
			ob.clear();
			break;
		case 5:
			ob.display();
			break;
		default:
			cout << "You have entered a wrong choice" << endl;
		}
		cout << "If you want to continue then type 'y'" << endl;
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}
void linkedlist::push(int a)
{
	node *p = new node;
	p->info = a;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
}
void linkedlist::pop()
{
	if (top != NULL)
	{
		if (top != NULL)
		{
			node *temp = top;
			top = top->next;
			temp->next = NULL;
			delete temp;
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}
}
void linkedlist::display()
{
	node *temp = top;
	if (top == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
	}
}
void linkedlist::clear()
{
	while (top != NULL)
	{
		pop();
	}
}
void linkedlist::peak()
{
	cout << "Peak is " << top->info << endl;
}
linkedlist::linkedlist()
{
	top = NULL;
}

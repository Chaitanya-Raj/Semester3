//Practical 5 - stack implementation using templates

#include <iostream>

using namespace std;

template <class T>

class Stack
{
	T *arr;
	int top, size;

public:
	Stack(int n)
	{
		size = n;
		arr = new T[n];
		top = -1;
	}

	void push(T val)
	{
		if (isfull())
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			top++;
			arr[top] = val;
		}
	}

	T pop()
	{
		T val = arr[top];
		top--;
		return val;
	}

	bool isfull()
	{
		return top == size - 1;
	}

	bool isempty()
	{
		return top == -1;
	}

	void display()
	{
		if (top > -1)
		{
			for (int i = top; i >= 0; i--)
			{
				cout << arr[i] << "->";
			}
			cout << "!!!";
		}
		else
		{
			cout << "stack is empty " << endl;
		}
	}
};

/* int main()
{
	int n, val;
	cout << "Enter the size of a stack : " << endl;
	cin >> n;
	Stack<int> s(n);
	int ch;
	char c;
	do
	{
		cout << "\nEnter your choice among following " << endl;
		cout << "1.Push an element" << endl;
		cout << "2.Pop an element " << endl;
		cout << "3.Display stack" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "enter the value to be inserted " << endl;
			cin >> val;
			s.push(val);
			break;
		case 2:
			if (s.isempty())
			{
				cout << "Stack Underflow " << endl;
			}
			else
			{
				cout << "element popped " << s.pop() << endl;
			}
			break;
		case 3:
			s.display();
			break;
		default:
			cout << "Invalid choice " << endl;
		}
		cout << "Continue?(y/n)" << endl;
		cin >> c;
	} while (c == 'y' || c == 'Y');
	return 0;
} */
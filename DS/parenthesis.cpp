//Practical 9 - parenthesis matching

#include <iostream>
#include "stackusingtemplates.cpp"
using namespace std;

void matchParen(string s, int n)
{
	char element;
	int failure = 0;
	Stack<char> ob(n);
	int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
			ob.push(s[i]);
		else if ((s[i] == ')') || ((s[i]) == '}') || (s[i] == ']'))
		{
			element = ob.pop();

			if (s[i] == ')')
				if (element != '(')
				{
					failure = 1;
					break;
				}

			if (s[i] == '}')
				if (element != '{')
				{
					failure = 1;
					break;
				}

			if (s[i] == ']')
				if (element != '[')
				{
					failure = 1;
					break;
				}
		}
		i++;
	}

	if (failure == 1)
		cout << "parenthesis do not match" << endl;
	else if (ob.isempty())
		cout << "parenthesis match" << endl;
	else
		cout << "parenthesis do not match" << endl;
}

int main()
{
	string str;
	cout << "Enter a stack" << endl;
	getline(cin, str);
	int l = str.length();
	matchParen(str, l);
	return 0;
}

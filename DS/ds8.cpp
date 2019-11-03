//Practical 8 - stack addition

#include <iostream>
#include "ds5.cpp"
using namespace std;

int main()
{
    char choice;
    do
    {
        string num1, num2, result;
        cout << "\nEnter first number : ";
        cin >> num1;
        int l1 = num1.length();

        cout << "\nEnter second number : ";
        cin >> num2;
        int l2 = num2.length();
        
        Stack<int> s1(l1), s2(l2), s3(l1 + l2);
        for (int i = 0; i < l1; i++)
        {
            s1.push(num1[i] - 48);
        }
        for (int i = 0; i < l2; i++)
        {
            s2.push(num2[i] - 48);
        }
        int carry = 0;
        while (!s1.isempty() || !s2.isempty())
        {
            int x, y;
            if (s1.isempty())
                x = 0;
            else
                x = s1.pop();
            if (s2.isempty())
                y = 0;
            else
                y = s2.pop();
            int z = x + y + carry;
            if (z >= 10)
            {
                carry = z / 10;
                s3.push(z % 10);
            }
            else
            {
                carry = 0;
                s3.push(z);
            }
        }
        if (carry > 0)
        {
            s3.push(carry);
        }
        while (!s3.isempty())
        {
            char a = s3.pop() + 48;
            result += a;
        }
        cout << "\nSum = " << result;
        cout << "\nContinue?(y/n)";
        cin >> choice;
    } while (choice == 'y');
}

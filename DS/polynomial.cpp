#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int coeff, pow;
    struct node *next;
};

class poly
{
    node *head;

public:
    poly()
    {
        head = NULL;
    }

    void input()
    {
        int n, q;
        cout << "Enter the coefficient of polynomial = " << endl;
        cin >> n;
        cout << "Enter the power of " << n << endl;
        cin >> q;
        insert(n, q);
    }
    void insert(int c, int p)
    {
        node *a = new node();
        a->coeff = c;
        a->pow = p;
        a->next = NULL;

        if (head == NULL) //for adding a single element
        {
            head = a;
        }
        else if (a->pow > head->pow && head->next == NULL) //for adding a node after head
        {
            head->next = a;
            a->next = NULL;
        }
        else if (a->pow < head->pow && head->next == NULL) //for adding a node before head
        {
            a->next = head;
            head->next == NULL;
            head = a;
        }
        else
        {
            node *temp = head;
            node *prev = temp->next;
            if (a->pow > temp->pow && prev->pow > a->pow)
            {
                a->next = prev;
                temp->next = a;
            }
            else if (a->pow > prev->pow)
            {
                prev->next = a;
                a->next = NULL;
            }
            else
            {
                while (temp != NULL)
                {
                    if ((prev->pow) > a->pow)
                    {
                        if (temp->pow < a->pow)
                        {
                            a->next = prev;
                            temp->next = a;
                        }
                    }
                    temp = temp->next;
                    prev = prev->next;
                }
            }
        }
    }

    poly add(poly p1, poly p2)
    {
        poly p3;
        node *head1 = p1.head;
        node *head2 = p2.head;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->pow == head2->pow)
            {
                p3.insert((head1->coeff + head2->coeff), head1->pow);
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->pow < head2->pow)
            {
                p3.insert(head1->coeff, head1->pow);
                head1 = head1->next;
            }
            else if (head1->pow > head2->pow)
            {
                p3.insert(head2->coeff, head2->pow);
                head2 = head2->next;
            }
        }

        return p3;
    }

    void display()
    {
        node *temp = head;
        cout << "Polynomial is   ";
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->pow << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    poly p4, p5, p6;
    char ch;
    int n;
    do
    {
        cout << "Enter your choice among following  \n1.Insert value in polynomial 1 " << endl;
        cout << "2.Insert  value in polynomial 2 " << endl;
        cout << "3.Add two polynomial " << endl;
        cout << "0.Exit" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            p4.input();
            p4.display();
            break;
        case 2:
            p5.input();
            p5.display();
            break;
        case 3:
            p6 = p6.add(p4, p5);
            p6.display();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice " << endl;
        }
    } while (n != 0);
    return 0;
}
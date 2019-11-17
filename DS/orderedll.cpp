#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
};
class linkedlist
{
    node *head;

public:
    linkedlist();
    void insert(int);
    void input();
    void deletion(int);
    void display();
    void merge(linkedlist);
};
int main()
{
    linkedlist ob;
    linkedlist ob2;
    int choice;
    char ch;
    int x;
    do
    {
        cout << "Enter the choice among the following" << endl;
        cout << "1.Insert\n2.Delete\n3.Merge\n4.Display\n " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be inserted" << endl;
            cin >> x;
            ob.insert(x);
            break;
        case 2:
            cout << "Enter the number to be deleted" << endl;
            cin >> x;
            ob.deletion(x);
            break;
        case 3:
            ob2.input();
            ob.merge(ob2);
            break;
        case 4:
            ob.display();
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
        cout << "Continue?(y/n)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    //getch();
    return 0;
}
void linkedlist::insert(int a)
{
    node *p = new node;
    p->info = a;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            if (p->info < temp->info)
            {
                p->next = head;
                head = p;
                return;
            }
            else if (p->info > temp->info && p->info < temp->next->info)
            {
                p->next = temp->next;
                temp->next = p;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp->next == NULL && p->info > temp->info)
        {
            temp->next = p;
            return;
        }
    }
}
void linkedlist::deletion(int x)
{
    node *temp = head;
    node *d;
    if (temp->next == NULL && temp->info == x)
    {
        delete temp;
        head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        if (head->info == x)
        {
            head = head->next;
            delete temp;
            return;
        }
        else if (temp->next->info == x)
        {
            d = temp->next;
            temp->next = d->next;
            d->next = NULL;
            delete d;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Element not present in the list" << endl;
}

void linkedlist::display()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "list is empty";
    }
    else
    {
        while (temp != NULL)

        {
            cout << temp->info << "->";
            temp = temp->next;
        }
    }
}
linkedlist::linkedlist()
{
    head = NULL;
}
void linkedlist::merge(const linkedlist ob)
{
    node *temp = ob.head;
    while (temp != NULL)
    {
        insert(temp->info);
        temp = temp->next;
    }
}
void linkedlist::input()
{
    int l;
    int x;
    cout << "Enter the size of linked list" << endl;
    cin >> l;
    while (l != 0)
    {
        cout << "Enter the value to be inserted" << endl;
        cin >> x;
        insert(x);
        l--;
    }
}
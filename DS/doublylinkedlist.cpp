#include <iostream>
using namespace std;

template <class T>
struct Node
{
    int data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertionHead()
    {
        Node<T> *temp = new Node<T>;
        cout << "\nenter the value to be inserted " << endl;
        T n;
        cin >> n;
        temp->data = n;
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL)
            head->prev = temp;
        head = temp;
    }
    void insertionTail()
    {
        Node<T> *temp = new Node<T>;
        cout << "\nenter the value to be inserted " << endl;
        T n;
        cin >> n;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            temp->prev = NULL;
        }
        else
        {
            Node<T> *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
            temp->prev = p;
        }
    }
    void deletionHead()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                Node<T> *delnode = head;
                cout << "element deleted " << head->data;
                head = NULL;
                delete delnode;
            }
            else
            {
                Node<T> *delnode = head;
                cout << "element deleted " << head->data;
                head = head->next;
                delnode->next = NULL;
                head->prev = NULL;
                delete delnode;
            }
        }
        else
        {
            cout << "List empty";
        }
    }
    void deletionTail()
    {
        if (head != NULL)
        {
            if (head->next == NULL)
            {
                Node<T> *delnode = head;
                cout << "element deleted " << head->data;
                head = NULL;
                delete delnode;
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next->next != NULL)
                    temp = temp->next;
                cout << "element deleted " << temp->next->data;
                Node<T> *delnode = temp->next;
                delnode->prev = NULL;
                delete delnode;
                temp->next = NULL;
            }
        }
        else
        {
            cout << "List empty";
        }
    }
    void search()
    {
        if (head == NULL)
            cout << "\nList empty";
        else
        {
            Node<T> *temp = head;
            cout << "\nenter the value to be searched " << endl;
            T x;
            cin >> x;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->data == x)
                    found = true;
                temp = temp->next;
            }
            if (found)
                cout << "\nElement found in linked list";
            else
                cout << "\nElement not found in linked list";
        }
    }
    void reverse()
    {
        Node<T> *temp;
        if (head == NULL)
        {
            cout << "\nList is empty.";
            return;
        }
        else if (head->next == NULL)
        {
            cout << "\nList only has one element";
            return;
        }
        while (head != NULL)
        {
            temp = head->next;
            head->next = head->prev;
            head->prev = temp;
            temp = head;
            head = head->prev;
        }
        head = temp;
        cout << "\nThe list has been reversed";
    }
    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "!!!";
    }
    void alt_display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            if (temp->next == NULL)
                break;
            temp = temp->next->next;
        }
        cout << "!!!";
    }
};

int main()
{
    LinkedList<int> l;
    int ch;
    char cont;
    do
    {
        cout << "\nEnter your choice among following " << endl;
        cout << "1.Insert an element at beginning" << endl;
        cout << "2.Insert an element at end" << endl;
        cout << "3.Delete an element from beginning" << endl;
        cout << "4.Delete an element from end" << endl;
        cout << "5.Search the list" << endl;
        cout << "6.Reverse the list" << endl;
        cout << "7.Display alternate elements of Linked List" << endl;
        cout << "8.Display Linked List\n"
             << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            l.insertionHead();
            break;
        case 2:
            l.insertionTail();
            break;
        case 3:
            l.deletionHead();
            break;
        case 4:
            l.deletionTail();
            break;
        case 5:
            l.search();
            break;
        case 6:
            l.reverse();
            break;
        case 7:
            l.alt_display();
            break;
        case 8:
            l.display();
            break;
        default:
            cout << "\nInvalid choice " << endl;
        }
        cout << "\n\nContinue?(y/n)" << endl;
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}
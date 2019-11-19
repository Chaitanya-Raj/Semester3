#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
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
        cout << "\nenter the value to be inserted " << endl;
        T n;
        cin >> n;
        Node<T> *temp = new Node<T>;
        temp->data = n;
        temp->next = head;
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
        }
        else
        {
            Node<T> *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
            ;
        }
    }
    void deletionHead()
    {
        if (head != NULL)
        {
            Node<T> *delnode = head;
            cout << "element deleted " << head->data;
            head = head->next;
            delnode->next = NULL;
            delete delnode;
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
            cout << "\nEnter the data to be searched : ";
            T x;
            cin >> x;
            Node<T> *temp = head;
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
        Node<T> *prev = NULL;
        Node<T> *next = NULL;
        if (head->next == NULL)
            return;
        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
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
    void concat(const LinkedList obj)
    {
        if (head == NULL)
            head = obj.head;
        else if (obj.head == NULL)
            return;
        else
        {
            Node<T> *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = obj.head;
        }
    }
    LinkedList operator+(const LinkedList obj)
    {
        LinkedList x;
        x.head = NULL;
        Node<T> *temp1 = head;
        Node<T> *temp2 = obj.head;
        while (temp1 != NULL)
        {
            x.insertionTail(temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            x.insertionTail(temp2->data);
            temp2 = temp2->next;
        }
        return x;
    }
};

int main()
{
    LinkedList<int> l1, l2, l3;
    int lch, ch;
    char cont;
    do
    {
        cout << "\n\nWhich list do you want to operate on\n1.l1\n2.l2\n3.l3\n"
             << endl;
        cin >> lch;
        if (lch == 1 || lch == 2 || lch == 3)
        {
            cout << "\nEnter your choice among following " << endl;
            cout << "1.Insert an element at beginning" << endl;
            cout << "2.Insert an element at end" << endl;
            cout << "3.Delete an element from beginning" << endl;
            cout << "4.Delete an element from end" << endl;
            cout << "5.Search the list" << endl;
            cout << "6.Reverse the list" << endl;
            cout << "7.Concatenate 2 lists" << endl;
            cout << "8.Add two lists" << endl;
            cout << "9.Display alternate elements of Linked List" << endl;
            cout << "10.Display Linked List\n"
                 << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                if (lch == 1)
                    l1.insertionHead();
                else if (lch == 2)
                    l2.insertionHead();
                else if (lch == 3)
                    l3.insertionHead();
                break;
            case 2:
                if (lch == 1)
                    l1.insertionTail();
                else if (lch == 2)
                    l2.insertionTail();
                else if (lch == 3)
                    l3.insertionTail();
                break;
            case 3:
                if (lch == 1)
                    l1.deletionHead();
                else if (lch == 2)
                    l2.deletionHead();
                else if (lch == 3)
                    l3.deletionHead();
                break;
            case 4:
                if (lch == 1)
                    l1.deletionTail();
                else if (lch == 2)
                    l2.deletionTail();
                else if (lch == 3)
                    l3.deletionTail();
                break;
            case 5:
                if (lch == 1)
                    l1.search();
                else if (lch == 2)
                    l2.search();
                else if (lch == 3)
                    l3.search();
                break;
            case 6:
                if (lch == 1)
                    l1.reverse();
                else if (lch == 2)
                    l2.reverse();
                else if (lch == 3)
                    l3.reverse();
                cout << "\nThe list has been reversed";
                break;
            case 7:
                if (lch == 1)
                {
                    l1.concat(l2);
                    cout << "Concatenated L2 to L1";
                }
                else if (lch == 2)
                {
                    l2.concat(l1);
                    cout << "Concatenated L1 to L2";
                }
                break;
            case 8:
                if (lch == 1)
                    l3 = l1 + l2;
                else if (lch == 2)
                    l3 = l2 + l1;
                l3.display();
                break;
            case 9:
                if (lch == 1)
                    l1.alt_display();
                else if (lch == 2)
                    l2.alt_display();
                else if (lch == 3)
                    l3.alt_display();
                break;
            case 10:
                if (lch == 1)
                    l1.display();
                else if (lch == 2)
                    l2.display();
                else if (lch == 3)
                    l3.display();
                break;
            default:
                cout << "\nInvalid choice " << endl;
            }
            cout << "\n\nContinue?(y/n)" << endl;
            cin >> cont;
        }
        else
        {
            cout << "\nInvalid List";
        }
    } while (cont == 'y' || cont == 'Y');
    return 0;
}
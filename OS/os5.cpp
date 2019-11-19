#include <iostream>
using namespace std;

class Buffer
{
public:
    int buf[50];
    int size;
    int in, out;
    Buffer(int n = 3)
    {
        in = 0;
        out = 0;
        size = n;
        for (int i = 0; i < size; i++)
            buf[i] = 0;
    }
    bool isFull()
    {
        for (int i = 0; i < size; i++)
            if (buf[i] == 0)
                return false;
        return true;
    }
    bool isEmpty()
    {
        for (int i = 0; i < size; i++)
            if (buf[i] != 0)
                return false;
        return true;
    }
    void produce(int n)
    {
        if (isFull())
        {
            cout << "\nNo space to produce";
        }
        else
        {
            buf[in] = n;
            cout << "\nProduced " << buf[in];
            in = (in + 1) % size;
        }
    }
    void consume()
    {
        if (isEmpty())
        {
            cout << "\nNothing to consume" << endl;
        }
        else
        {
            cout << "\nConsumed " << buf[out];
            buf[out] = 0;
            out = (out + 1) % size;
        }
    }
    void display()
    {
        cout << endl;
        if (isEmpty())
            cout << "\nNothing to display...";
        else if (out <= in)
        {
            cout << "\nThe current buffer is \n";
            for (int i = out; i < in; i++)
                cout << buf[i] << "\t";
        }
        else
        {
            cout << "\nThe current buffer is \n";
            for (int i = out; i < size; i++)
                cout << buf[i] << "\t";
            for (int i = 0; i <= in; i++)
                cout << buf[i] << "\t";
        }

        cout << endl;
    }
};

int main()
{
    Buffer b;
    char cont;
    do
    {
        cout << "\nChoose the operation :\n";
        cout << "1.Produce\n";
        cout << "2.Consume\n";
        cout << "3.Display\n\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            int num;
            cout << "\nTell me what to produce...";
            cin >> num;
            b.produce(num);
            break;
        case 2:
            b.consume();
            break;
        case 3:
            b.display();
            break;
        default:
            cout << "\nInvalid Input";
        }
        cout << "\nContinue? (y/n)" << endl;
        cin >> cont;
    } while (cont == 'y');
    return 0;
}
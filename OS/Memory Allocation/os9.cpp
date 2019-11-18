#include <bits/stdc++.h>
using namespace std;

class MemoryAllocation
{
    int *blockSize;
    int *processSize;
    int m;
    int n;

public:
    void input()
    {
        cout << "\nEnter the number of memory blocks : ";
        cin >> m;
        blockSize = new int[m];
        cout << "\nEnter the block sizes : \n";
        for (int i = 0; i < m; i++)
        {
            cout << "\nSize of block " << i + 1 << " : ";
            cin >> blockSize[i];
        }
        cout << "\nEnter the number of processes : ";
        cin >> n;
        processSize = new int[n];
        cout << "\nEnter the process sizes : \n";
        for (int i = 0; i < n; i++)
        {
            cout << "\nSize of process " << i + 1 << " : ";
            cin >> processSize[i];
        }
    }
    void display(int allocation[])
    {
        cout << "\nProcess No.\tProcess Size\tBlock no.\n";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t"
                 << processSize[i] << "\t\t";
            if (allocation[i] != -1)
                cout << allocation[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }
    void firstFit()
    {
        int allocation[n];

        memset(allocation, -1, sizeof(allocation));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    allocation[i] = j;

                    blockSize[j] -= processSize[i];

                    break;
                }
            }
        }

        display(allocation);
    }
    void bestFit()
    {
        int allocation[n];

        memset(allocation, -1, sizeof(allocation));

        for (int i = 0; i < n; i++)
        {
            int bestIdx = -1;
            for (int j = 0; j < m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    if (bestIdx == -1)
                        bestIdx = j;
                    else if (blockSize[bestIdx] > blockSize[j])
                        bestIdx = j;
                }
            }

            if (bestIdx != -1)
            {
                allocation[i] = bestIdx;

                blockSize[bestIdx] -= processSize[i];
            }
        }

        display(allocation);
    }
    void worstFit()
    {
        int allocation[n];

        memset(allocation, -1, sizeof(allocation));

        for (int i = 0; i < n; i++)
        {
            int wstIdx = -1;
            for (int j = 0; j < m; j++)
            {
                if (blockSize[j] >= processSize[i])
                {
                    if (wstIdx == -1)
                        wstIdx = j;
                    else if (blockSize[wstIdx] < blockSize[j])
                        wstIdx = j;
                }
            }

            if (wstIdx != -1)
            {
                allocation[i] = wstIdx;

                blockSize[wstIdx] -= processSize[i];
            }
        }

        display(allocation);
    }
};

int main()
{
    int ch;
    MemoryAllocation m;
    m.input();
    cout << "\nChoose : \n1.First Fit\n2.Best Fit\n3.Worst Fit\n0.Exit\n\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        m.firstFit();
        break;

    case 2:
        m.bestFit();
        break;

    case 3:
        m.worstFit();
        break;

    case 0:
        exit(0);

    default:
        cout << "\nInvalid Choice!!!\n\n";
        break;
    }
    return 0;
}
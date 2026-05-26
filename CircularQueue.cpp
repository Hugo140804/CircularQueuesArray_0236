#include <iostream>
using namespace std;

class queues
{
private:
    static const int max = 3;
    int front, rear;
    int queue_array[max];

public:
    queues()
    {
        front = -1;
        rear = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        if ((front == 0 && rear == max - 1) || (front == rear + 1))
        {
            cout << "\nQueue is full" << endl;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            queue_array[rear] = num;
        }
        else if (rear == max - 1 && front != 0)
        {
            rear = 0;
            queue_array[rear] = num;
        }
        else
        {
            rear++;
            queue_array[rear] = num;
        }
    }

    void remove()
};
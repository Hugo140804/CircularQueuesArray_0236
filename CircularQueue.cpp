#include <iostream>
#include <exception>
using namespace std;

const int max = 5;

class Queues
{
private:
    int queue_array[max];
    int FRONT_Position;
    int REAR_Position;

public:
    Queues()
    {
        FRONT_Position = -1;
        REAR_Position = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT_Position == 0 && REAR_Position == max - 1) || (FRONT_Position == REAR_Position + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            FRONT_Position = 0;
            REAR_Position = 0;
        }
        else
        {
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR_Position == max - 1)
                REAR_Position = 0;
            else
                REAR_Position++;
        }

        queue_array[REAR_Position] = num;
    }

    void remove()
    {
        if (FRONT_Position == -1)
        {
            cout << "\nQueue underflow\n";
            return;
        }

        cout << "Element deleted: " << queue_array[FRONT_Position] << endl;

        if (FRONT_Position == REAR_Position)
        {
            // antrian jadi kosong setelah penghapusan
            FRONT_Position = -1;
            REAR_Position = -1;
        }
        else if (FRONT_Position == max - 1)
        {
            FRONT_Position = 0;
        }
        else
        {
            FRONT_Position++;
        }
    }

    void display()
    {
        if (FRONT_Position == -1)
        {
            cout << "\nQueue is empty\n";
            return;
        }

        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
        }
        else
        {
            // jika FRONT <= REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
        }
        cout << endl;
    }
};

int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display values " << endl;
            cout << "4. Exit " << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
    return 0;
}
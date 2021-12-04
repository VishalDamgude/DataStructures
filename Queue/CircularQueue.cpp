#include <iostream>

using namespace std;

class Queue{

    //Circular Queue of fixed size.
    private:
        int front;
        int rear;
        int *items = nullptr;
        int size;
    
    public:
        //Constructor: initialize queue elements to 0
        Queue(int s)
        {
            front = rear = -1;
            items = new int[s];
            size = s;
            for(int i=0; i<size; i++)
                items[i] = 0;
        }
        
        int IsEmpty() 
        {
            if(front == -1)
                return 1;
            else
                return 0;

        }

        int IsFull()
        {
            if(front == (rear+1) % size)
                return 1;
            else 
                return 0;

        }

        void Enqueue(int data)
        {
            if(IsFull())
            {
                cout << "Queue is full. Cannot insert data" << endl;
                return;
            }
            if(front == -1) front = 0;
            rear = ++rear % size;
            items[rear] = data;
        }

        int Dequeue()
        {
            if(IsEmpty())
            {
                cout << "Queue is empty!" << endl;
                return INT_MIN;
            }
            int data = items[front];
            items[front] = 0;
            //When only one item is there in queue, reset front and rear to -1 before dequeueing it
            //as queue will become empty.
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = ++front % size;
            }

            return data;
        }

        void Display()
        {
            cout << "front = " << front << " rear = " << rear << endl;
            for(int i=0; i<size; i++)
            {
                cout << items[i] << " ";
            }
            cout << endl;
        }

        ~Queue()
        {
            delete []items;
        }
};


int main()
{
    int size = 0;

    cout << "Enter Queue size: ";
    cin >> size;
    Queue q(size);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    
    q.Display();
    cout << "adding element 50 " << endl;
    q.Enqueue(50);
    q.Display();

    cout << "adding element 60 " << endl;
    q.Enqueue(60);
    q.Display();

    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();

    cout << "adding element 60 " << endl;
    q.Enqueue(60);
    q.Display();

    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();

    return 0;
}
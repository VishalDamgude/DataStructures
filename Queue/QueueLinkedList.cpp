#include <iostream>

using namespace std;


class QueueNode{
    public:
        int data;
        QueueNode *next;
        QueueNode(int d)
        {
            data = d;
            next = nullptr;
        }
};

class Queue{

    private:
        QueueNode *front;
        QueueNode *rear;
        int size = 0;
    public:
        Queue()
        {
            front = rear = nullptr;
        }
        
        int IsEmpty() 
        {
            if(front == nullptr)
                return 1;
            else
                return 0;

        }

        void Enqueue(int data)
        {
            QueueNode *temp = new QueueNode(data);
            if(front == nullptr) front = temp;
            if( rear != nullptr)
            {
                //Set current rear nodes's next to newly created node.
                rear->next = temp;
            }
            rear = temp;
            size++;
        }

        int Dequeue()
        {
            if(IsEmpty())
            {
                cout << "Queue is empty!" << endl;
                return INT_MIN;
            }
            int data = front -> data;
            QueueNode *temp = front;
            //When 1 element is left in queue and about to be deleted, reset rear pointer.
            if(front == rear)
                rear = nullptr;
            front = front -> next;
            delete temp;
            size--;
            return data;
        }

        void Display()
        {
            QueueNode *node = front;
            while(node != nullptr)
            {
                cout << node->data << " ";
                node = node -> next;
            }
            cout << endl;
        }

        ~Queue()
        {
            QueueNode *node = front;
            while(node != nullptr)
            {
                QueueNode *temp = node;
                node = node -> next;
                delete temp;
            }
        }
};


int main()
{
    Queue q;

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
/*Створити параметризовану чергу.*/
#include <iostream>

using namespace std;

template<typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr){}
    };
    
    Node* frontNode;
    Node* rearNode;

public: 
    Queue() : frontNode(nullptr), rearNode(nullptr){}
    ~Queue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() const { return frontNode == nullptr; }

    void enqueue(const T& item)
    { 
        Node* newNode = new Node(item);
        if(isEmpty())
        { 
            frontNode = newNode; 
        }
        else
        { 
            rearNode -> next = newNode; 
        }

        rearNode = newNode;
    }

    void dequeue()
    {
        if(isEmpty())
        { 
            throw out_of_range("Queue is empty");
        }

        Node* temp = frontNode;
        frontNode = frontNode -> next;
        delete temp;

        if(frontNode == nullptr)
        {
            rearNode = nullptr;
        }
    }

    const T& front() const
    {
        if(isEmpty())
        {
            throw out_of_range("Queue is empty");
        }
        return frontNode -> data;
    }
};

int main()
{
    cout << "---For int:---" << endl;
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front of the queue: " << q.front() << endl;

    q.dequeue();
    cout << "Front of the queue: " << q.front() << endl;

    q.dequeue();
    cout << "Front of the queue: " << q.front() << endl;

    q.dequeue();
    cout << "Is the queue empty? " << boolalpha << q.isEmpty() << endl;

    cout << "---For double:---" << endl;
    Queue<double> q1;
    q1.enqueue(1.3);
    q1.enqueue(2.7);
    q1.enqueue(3.5);

    cout << "Front of the queue: " << q1.front() << endl;

    q1.dequeue();
    cout << "Front of the queue: " << q1.front() << endl;

    q1.dequeue();
    cout << "Front of the queue: " << q1.front() << endl;

    //q.dequeue();
    cout << "Is the queue empty? " << boolalpha << q1.isEmpty() << endl;

    cout << "---For char:---" << endl;
    Queue<char> q2;
    q2.enqueue('a');
    q2.enqueue('b');
    q2.enqueue('c');

    cout << "Front of the queue: " << q2.front() << endl;

    q2.dequeue();
    cout << "Front of the queue: " << q2.front() << endl;

    q2.dequeue();
    cout << "Front of the queue: " << q2.front() << endl;

    q2.dequeue();
    cout << "Is the queue empty? " << boolalpha << q2.isEmpty() << endl;
}
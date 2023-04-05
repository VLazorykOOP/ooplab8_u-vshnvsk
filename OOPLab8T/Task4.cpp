/*Побудувати клас, що описує лінійний двох зв’язний список. 
Побудувати клас ітератор, що дозволяє проходити список. 
Написати програму, яка тестує створений ітератор. */
#include <iostream>
#include <stdexcept>
using namespace std;

class Node
{
public: 
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr){}
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0){}
    ~DoublyLinkedList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    void pushFront(int value)
    {
        Node* newNode = new Node(value);
        if(head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void pushBack(int value)
    {
        Node* newNode = new Node(value);
        if(tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int front() const
    {
        if(head == nullptr)
        {
            throw out_of_range("List is empty");
        }
        return head->data;
    }

    int back() const
    {
        if(tail == nullptr)
        {
            throw out_of_range("List is empty");
        }
        return tail->data;
    }

    bool empty() const { return head == nullptr; }

    int getSize() const { return size; }

    class iterator
    {
    private:
        Node* current;
        DoublyLinkedList* list;
    
    public:
        iterator(Node* node) : current(node){}

        int& operator*() const { return current->data; }

        bool operator==(const iterator& other) const { return current == other.current; }

        bool operator!=(const iterator& other) const { return current != other.current; }

        iterator& operator++()
        {
            if(current == nullptr)
            {
                throw out_of_range("Cannot increment iterator beyond end");
            }
            current = current->next;
            return *this;
        }

        iterator& operator--()
        {
            if(current == nullptr)
            {
                current = list->tail;
            }
            else
            {
                current = current->prev;
            }
            return *this;
        }
    };

    iterator begin() const { return iterator(head); }
    iterator end() const { return iterator(nullptr); }
};

int main()
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushFront(5);
    list.pushBack(20);

    cout << "List elements: ";
    for (DoublyLinkedList::iterator it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Front element: " << list.front() << endl;
    cout << "Back element: " << list.back() << endl;

    cout << "List size: " << list.getSize() << endl;

    cout << "List empty: " << (list.empty() ? "true" : "false") << endl;

    return 0;
}

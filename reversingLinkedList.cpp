#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head = NULL;
    }

    void reverse()
    {
        Node* current = head;
        Node *prev = NULL,*next = NULL;

        while(current!=NULL)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }
        head = prev;
    }

    void print()
    {
        struct
    }
};

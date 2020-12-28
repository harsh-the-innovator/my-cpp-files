#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    //constructor
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }

    //adding node to the linked list
    void add_node(int n)
    {
        node *tmp = new node;//memory allocation
        tmp->data = n;
        tmp->next = NULL;

        if(head==NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    cout<<"Linked List created:\n"<<node->data<<" "<<node->next;
    return 0;
}

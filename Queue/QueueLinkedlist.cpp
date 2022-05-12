// Implement Queue using Singly linked list
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class QueueLL
{
    struct node
    {
        int data;
        node *next;
    };
    public:
    node *front,*rear;
    QueueLL()
    {
        front=NULL;
        rear=NULL;
    }

    void enqueue(int value)
    {
        node *n=new node;
        n->data=value;
        n->next=NULL;
        if(rear==NULL)
        {
            front=n;
            rear=n;
            
        }
        else
        {
            rear->next=n;
            rear=n;
        }
    }

    void dequeue()
    {
       node *data=front;
       front=front->next;
       delete data;
        
    }

    void display()
    {
        node *tmp;
        tmp=front;
        while(tmp!=NULL)
        {
            cout<<tmp->data<<endl;
            tmp=tmp->next;
        }
    }


};
int main()
{
    QueueLL q1;
    q1.enqueue(23);
    q1.enqueue(11);
    q1.enqueue(55);
    q1.enqueue(33);
    q1.display();
    q1.dequeue();
    q1.display();
}
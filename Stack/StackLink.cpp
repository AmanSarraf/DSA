#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Stack
{

    //create a node first
    struct node
    {
        int data;
        node *next;
    };
    node *top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push(int info)
    {
        node *n=new node;
        n->data=info;
        n->next=top;
        top=n;
    }

    void pop()
    {
        // this will be like deletefirst
        // node *t1,*t2;
        // t1=top;
        // t2=NULL;
        // while(t1->next!=NULL)
        // {
        //     t2=t1;
        //     t1=t1->next;
        // }
        // if(t2==NULL)
        // {
        //     top=NULL;
        // }
        // else
        // {
        //     t2->next=t1->next;
        //     delete t1;

        // }

        if(top==NULL)
        {
            cout<<"Can't POP UNDERFLOW";
        }
        else
        {
            node *t;
            t=top;
            top=t->next;
            delete t;
            
            delete t;
        }

        
    }

    void peek()
    {
       if(top==NULL)
       {
           cout<<"Stack empty";
       }
       else{
       cout<<" top is "<<top->data;
       }
    }


};

int main()
{
    Stack s1;
    s1.push(12);
    s1.push(13);
    s1.push(14);
    s1.pop();
    s1.pop();
    s1.peek();
}
//program for implementation of doubly linked list
#include<iostream>
#include<stdio.h>
using namespace std;
class dll
{
    private:
    struct node
    {
        node *prev;
        int item;
        node *next;

    };
    node *start;
    public:
    /*Function Declaration*/
      dll()
{
   start=NULL;
}

    void insertatfirst(int);
    void insertatlast(int);
    void insertnodeafter(int,int);
    void deletefirst();
    void deletelast();
    void deletenode(int);
    node* search(int);
    void viewlist();
  


};
/*Function Definition*/

void dll::insertatfirst(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    if(start==NULL)
    {
        start=n;
    }
    else{
    n->next=start;
    start->prev=n;
    start=n;
    }
    
}

void dll::viewlist()
{
    node *t;
    t=start;
    while(t!=NULL)
    {
        cout<<"\n"<<t->item;
        t=t->next;
    }
}



int main()
{
    dll l1;
    l1.insertatfirst(1);
    l1.insertatfirst(2);
    l1.viewlist();
}
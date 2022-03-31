//program for implementation of doubly linked list
#include<iostream>
#include<conio.h>
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
    void viewlist();
    node* search(int data)
    {
        node *t;
        t=start;
        while(t!=NULL)
        {
            if(t->item==data)
              break;
              t=t->next;

        }
        if(t==NULL)
        {
            return NULL;
        }
        else
        {
            return t;
        }
    }
    
  


};
/*Function Definition*/

void dll::insertatfirst(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=NULL;
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
void dll::insertatlast(int data)
{
    node *n=new node;
    n->item=data;
    n->item=data;
    n->prev=NULL;
    node *t;
      t=start;
    if(start==NULL)
    {
        start=n;
    }
    else  
    {
      while(t->next!=NULL)
      {
         t=t->next; 
      }
      t->next=n;
      n->prev=t;
    }
}

void dll::insertnodeafter(int elem , int data)
{
    node *elm=search(elem);
    if(elm!=NULL)
    {
        node *n=new node;
        n->item=data;
        
        n->next=elm->next;
        elm->next=n;
        n->prev=elm;

        
    }
    else
    {
       cout<<"SEARCH FAIL";
    }

}
void dll::deletefirst()
{
    node *t;
    if(start==NULL)
    {
      cout<<"UNDERFLOW";
    }
    else
    {
    t=start;
    start=t->next;
    t->prev=NULL;
    delete t;
    }
}

void dll::viewlist()
{
    node *t;
    t=start;
    if(start==NULL)
    {
        cout<<"NO ITAM AVAILABLE";
    }
    else{
    while(t!=NULL)
    {
        cout<<t->item<<endl;
        t=t->next;
    }
    }
}



int main()
{
   
    dll l1;
    l1.insertatfirst(1);
    l1.insertatfirst(2);
    l1.insertatfirst(3);
    l1.insertatlast(10);
    l1.insertnodeafter(2,13);
    l1.deletefirst();
    
    l1.viewlist();    

    
}
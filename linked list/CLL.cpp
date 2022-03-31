#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class cll
{
   struct node
   {
       int data;
       node *next;

   };
   node *last;

   public:
  
  cll()
  {
      last=NULL;
  }
  void insertatfirst(int);
  void insertatlast(int);
  void insertafter(int,int);
  void deletefirst();
  void deletelast();
  void deleteparticular(int);
  void viewall();
  node* search(int data)
  {
      node *temp;
      temp=last->next;
      while(temp!=last)
      {
          if(temp->data==data)
      
          return temp;
      
          temp=temp->next;
      }
      
          return NULL;

  }
  ~cll()
  {
      while(last)
      deletefirst();
  }
};
void cll::insertatfirst(int info)
{
    node *n=new node;
    n->data=info;
    // n->next=last->next;
    if(last==NULL)   // jab first time last me null hoga to uska next to hoga hi nahi
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }

}
void cll::insertatlast(int data)
{
    node *n=new node;
    n->data=data;
    
     if(last==NULL)
     {
         n->next=n;//last;
         last=n;
        
     }
     else
     {
         n->next=last->next;
         last->next=n;
         last=n;
     }
}
void cll::insertafter(int element,int data)
{
    node *s=search(element);
    if(s!=NULL)
    {
        node *n=new node;
        n->data=data;
        n->next=s->next;
        s->next=n;
    }
    else
    {
        cout<<"Entered Element not found ! SEARCH FAIL";
    }

}
void cll::deletefirst()
{
    node *tmp;
    if(last==NULL)
    {
        cout<<"UNDERFLOW";
    }
    else
    {
        if(last->next==last) //condition for single node
        {
            delete last;
            last=NULL;
        }
        else
        {
            tmp=last->next;
            last->next=tmp->next;
            delete tmp;
        }
    }
    // tmp=last->next;
    // tmp=tmp->next;
    // last->next=tmp;
    // delete tmp;
}
void cll::deletelast()    /// here we need address of second last element
{
   node *t; 
    if(last==NULL)
    {
        cout<<"UNDERFLOW";
    }
    else if(last->next==last)
    {
        delete last;
        last=NULL;
    }
    else{
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else{
            t=last->next;
            while(t->next!=last)
            t=t->next;
            t->next=last->next;
            last=t;
        }
    }
    // else{
    //     node *tmp,*prev;
    // prev=last;
    // tmp=last->next;
    // while(tmp!=last)
    // {
    //     prev=tmp;
    //     tmp=tmp->next;
    // }
    // prev->next=last;
    // delete tmp;

    // }



}
void cll::deleteparticular(int element)
{
    node *t1,*t2;
    t2=last;
    t1=last->next;
    while(t1!=last)
    {
        // t2=t1;
        // t1=t1->next;
        if(t1->data==element)
        break;
        else
        {
            t2=t1;
        t1=t1->next;
        }
    }
    if(t1==last)
    {
        cout<<"Search Fail";
    }
    else{
        t2->next=t1->next;
        delete t1;
    }

}
void cll::viewall()
{
    node *view;
    view=last->next;
    do
    {
        cout<<view->data<<" ";
        view=view->next;

    }
    while(view->next!=last);
}
int main()
{
    cll c1;
    c1.insertatfirst(10);
     c1.insertatfirst(20);
     c1.insertatfirst(30);
    // c1.insertatfirst(10);
    // // c1.insertatfirst(10);
    // // c1.insertatfirst(10);
    
    c1.viewall();
}
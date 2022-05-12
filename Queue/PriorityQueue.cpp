#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Pqueue
{
   struct node
   {
       int priority;
       int info;
       node *next;
   };
 public:
   node *front;
   node *rear;
 Pqueue()
 {
     front=NULL;
     rear=NULL;
 }

 int isEmpty()
 {
     if(front==NULL)
     return 1;
     else
     return 0;
 }

   void insert(int item_priority,int data)
   {
       node *p, *n=new node;
       n->info=data;
       n->priority=item_priority;
       if(isEmpty()||item_priority<front->priority)
       {
           n->next=front;
           front=n;
           
       }

       else
       {
           p=front;
           while(p->next!=NULL&&p->next->priority<=item_priority)
           p=p->next;
           n->next=p->next;
           p->next=n;

       }
   }



   void display()
   {
       node *ptr;
       ptr=front;
       if(isEmpty())
       {
           cout<<"Queue is empty";
       }
       else{
           while(ptr!=NULL)
           {
               cout<<ptr->priority<<" ===>"<<ptr->info<<endl;
               ptr=ptr->next;
           }
       }
   }
};

int main()
{
    Pqueue p1;
    p1.insert(1,45);
    // p1.insert(2,25);
    // p1.insert(3,35);
    p1.insert(4,55);
    p1.display();
}
//program for implementation of Singly Linked list


//VERSION 1
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class sll
{
    private:
    struct node{

        int item;
        node *next;
    };
    
    public:
    node *start;
    
    sll()
    {
        start=NULL;
    }
   
   void insertatfirst(int);
   void insertatlast(int);
   node* search(int data)
   {
       node *n;
       n=start;
       while(n!=NULL)
       {
           if (n->item==data)
           
               return n;
           
           n=n->next;
       }
       return NULL;
      

   }
   void inertafter(int,int);
   void deletefromfirst();
   void deleteatend();
   void deletenode(int);
   void viewlikedlist();

//    ~sll()
//    {
//       delete start;

//    }



    

};
void sll::insertatfirst(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;


}
void sll::insertatlast(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
    {
       start=n;
    }
    else{
        node *tmp;
    tmp=start;
    
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    
    tmp->next=n;
    // delete tmp;      blunder  
    }
    

}
void sll::inertafter(int element,int data)
{
    node *elm=search(element);
    if(elm!=NULL)
    {
        node *n=new node;
        n->item=data;
        // elm->next=n;
        n->next=elm->next;

        elm->next=n;


    }
    else{
        cout<<"Search fail";
    }
    

}
void sll::deletefromfirst()
{
    if(start==NULL)
    {
        cout<<"Underflow";
    }
    else{
        node *temp;
        temp=start;
        start=temp->next;
        delete temp;

    }
}
void sll::deleteatend()
{
    node *t1,*t2;
    t1=start;
    t2=NULL;
    while(t1->next!=NULL)
    {
        t2=t1;
        t1=t1->next;

    }
    if(t2==NULL)
    {
        start=NULL;
    }
    else
    {
        t2->next=NULL;
        delete t1;
    }


}
void sll::deletenode(int data)
{
    node *t1,*t2;
    t1=start;
    t2=NULL;
    // while(t1->item!=data)
    // {
    //     t2=t1;
    //     t1=t1->next;

    // }
    while(t1!=NULL)
    {
        if(t1->item==data)
        break;
        else
        {
            t2=t1;
            t1=t1->next;
        }
    }
    if(t1==NULL)
    {
        cout<<"Data not Found";
    }
    
    else
    {
        if(t2==NULL)
    {
        start=t1->next;
    }
    else
    {
        t2->next=t1->next;
        delete t1;

    }
    }
}
void sll::viewlikedlist()
{
    node *n;
    n=start;
    if(start==NULL)
    {
        cout<<"NOTHING TO SHOW";
    }
    else{
    while(n!=NULL)
    {
        
        cout<<n->item<<endl;
        n=n->next;
      
    }
       }
}





int main()
{
    sll l1;
    l1.insertatfirst(1);
    l1.insertatfirst(2);
    l1.insertatfirst(3);
    l1.insertatfirst(4);
    l1.deletefromfirst();
    l1.insertatlast(9);
    l1.inertafter(2,10);
    l1.deleteatend();
    l1.deletenode(2);
    l1.viewlikedlist();

    return 0;
}
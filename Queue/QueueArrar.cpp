//Queue Implementation using Array Ds
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class Queue
{
   
   
   int size;
   int front;
   int rear;
   int *ptr;
   public:
   Queue()
   {
       front=-1;
       rear=-1;
       size=0;
       ptr=NULL;
   }
   void createQueue(int cap)
   {
       
       size=cap;
       ptr=new int[size];
       front=-1;
   }

//INsertion in Queue---------------------------
   void enqueue(int value)
   {
       //check when insertion is not possible
       if(front==0&&rear+1==size||rear+1==front)   //// care full while == and =
       {
           cout<<"Overflow";

       }
        else if(ptr==NULL)
       {
           cout<<"please create a queue first";
       }
       else
          {
              if(rear==-1)
              {
                  front=0;
                  rear++;
                  ptr[rear]=value;
              }
              else if(rear==size-1)
              {
                  rear=0;
                  ptr[rear]=value;
              }
              else
              {
                  rear++;
                  ptr[rear]=value;
              }
          }
       
   }

   void dequeue()
   {
       //think when deletion is not possible at all
       if(rear==-1)
       {
           cout<<"Underflow";
       }
       if(front==rear)
       {
           front=-1;
           rear=-1;
       }
       if(front==size-1)
       {
           front=0;

       }
       else{
           front=front+1;
       }
   }
/// function to display the quesus
   void display()
   {
       for(int i=front;i<=rear;i++)
       {
           cout<<ptr[i]<<" ";
       }
   }

};

int main()
{
    Queue Q1;
    int n;

    cout<<"No of elements you wants to insert\n";
    cin>>n;
    Q1.createQueue(n);
    cout<<"Enter the elements to store\n";
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        Q1.enqueue(p);

    }
    Q1.display();
    Q1.dequeue();
    Q1.display();
}
//implementing circular doubly linked list
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class cdll
{
private:
     struct node
     {
         node *prev;
         int data;
         node *next;
     };

     node *last;
     
public:
    cdll();
    ~cdll();
};

cdll::cdll(/* args */)
{
    last=NULL;
}

cdll::~cdll()
{
}

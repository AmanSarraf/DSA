#include<iostream>
#include<conio.h>
using namespace std;

void swap(int *a,int *b)
{
    int *temp;
    temp=a;
    a=b;
    b=temp;
}


void InsertionSort(int arr[],int n)
{
    int key,j;
   
   for(int i=1;i<n;i++)
   {
       key=arr[i];
       j=i-1;
       
       while(key<arr[j]&&j>=0)
       {
           arr[j+1]=arr[j];
           --j;
       }
       arr[j+1]=key;

   }





   for(int i=0;i<10;i++)
   {
       cout<<arr[i]<<" ";

   }
    




}
int main()
{
   
   int arr[10]={100,30,40,60,90,70,20,50,10,80};
int n=sizeof(arr)/sizeof(arr[0]);

//cout<<"size of array is "<<n;
   InsertionSort(arr,n);
 




}


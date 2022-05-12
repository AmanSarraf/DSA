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


void BubbleSort(int a[],int n)
{
   
   for(int i=0;i<n-1;i++)             ///why 9 rounds comparisons?
                                    //we alredy have 10th element sorted by 9th round
   {
       for(int j=0;j<n-i-1;j++)     //after i th round one last element is in its place
       {
           if(a[j]>a[j+1])
           {
               swap(a[j],a[j+1]);

           }
       }
   }


   for(int i=0;i<10;i++)
   {
       cout<<a[i]<<" ";

   }
    




}
int main()
{
   
   int arr[10]={100,30,40,60,90,70,20,50,10,80};
int n=sizeof(arr)/sizeof(arr[0]);

//cout<<"size of array is "<<n;
   BubbleSort(arr,n);
 




}


#include<iostream>
using namespace std;

void rotate(int a[] ,int n ,int count)
{
 int temp,i;

 while(count)
 {
     temp=a[n-1];
     for(i=n-1;i>=1;i--)
 { 
     a[i]=a[i-1];

 }
 a[0]=temp;
 count--;


 }
 

}
void disp(int a[],int n)
{
    
    cout<<"After rotation:\n";
    int i;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\n";
    }
}
int main()
{
   
   int arr[100],i,n,sum=0,asum=0,rot;
   cout<<"Enter the number of terms to store";
   cin>>n;

for(i=1;i<=n+1;i++)
   {
       sum=sum+i;
   }
//    cout<<sum;
cout<<"Enter array element";

   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
  

   for(i=0;i<n;i++)
   {
       asum=asum+arr[i];
   }
//    cout<<sum;
//    cout<<"\n"<<asum;

  cout<<"The missing number is "<<sum-asum;
  rot=sum-asum;

  rotate(arr,n,rot);
  disp(arr,n);

    
   

return 0;

}


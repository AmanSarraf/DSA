#include<iostream>
using namespace std;
class Array
{
  private:
  int capacity;
  int lastindex;
  int *ptr;  // jis type ki memory block create karni h usi type ki pointer lenge
              // could be generalise by using TEMPLATES
             // Could be any premitive and non pretmitive data type
   public:

   Array(); // contructor
   void createArray(int cap); // to create array of req. capacity
                              // Keep in mind that this will be used by another prson;
    void append(int data);
    void insert(int index, int data);  /* This is 
                                          called interfce
                                                    or ADT*/
    void del(int index);
    int search(int data);
    int getdata(int index);        
    int count();
    void edit(int index , int data);
    void view();
    ~Array();



};
// Initialising the new array Object
Array::Array()
{
  capacity=0;
  lastindex=-1;
  ptr='\0'; 

}
// creating the memory block of size cap
void Array::createArray(int cap)
{
 capacity=cap;
 lastindex=-1;
 ptr=new int[cap];


}
void Array::append(int data)
{
  
  if(lastindex+1==capacity-1)
  {
      cout<<"Can't append";
  }
  else
  ++lastindex;           // last index baad me incr. nhi karna hai 
                          // pahle index ko incr. kr ke next block pr jao 
                          // then store the data
  ptr[lastindex]=data;
  


}

void Array::insert(int index, int data)
{
 
 if(index<capacity-1)
 {
     ptr[index]=data;
     lastindex++;
 }
 else
 {
   cout<<"invalid index";
 }

}
void Array::del(int index)
{
  
if(index<capacity-1)
 {
     ptr[index]='\0';
 }
 else
 {
   cout<<"invalid index";
 }

}
int Array::search(int data)
{
  
  int i;
  for(i=0;i<capacity-1;i++)
  {
      if(ptr[i]==data)
      return i;
  }

}
int Array::getdata(int index)
{

    return ptr[index];
}

int Array::count()
{
    return (lastindex+1);
}
void Array::edit(int index, int data)
{

    ptr[index]=data;

}

void Array::view()
{

for(int i=0;i<capacity-1;i++)
{
    cout<<" \n"<<ptr[i];
}

}

Array::~Array()
{
    cout<<"Thankyou";
}

int main()
{
 Array a1;
 a1.createArray(5);
 
 a1.insert(0,1);
 a1.insert(1,2);
 a1.insert(2,3);
 a1.insert(3,4);
 a1.insert(4,5);
 //a1.view();
 a1.append(20);
 a1.view();

 return 0;
 


}
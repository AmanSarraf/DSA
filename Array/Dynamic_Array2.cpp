// Question Link https://i.imgur.com/xjVfaCm.png

#include <iostream>
using namespace std;

class Darray
{

private:
    int data, capacity, lastindex, *ptr;

public:
    Darray();
    void createArray(int size);
    void append(int data);
    void insert(int index, int data);
    int getByIndex(int index);
    void remove(int index);
    void edit(int index, int newdata);
    int search(int data);
    void viewAll();
    ~Darray();

protected:
    void doubleArray();
    void halfArray();
};
Darray::Darray()
{
    lastindex = -1;
    capacity = 0;
    ptr = NULL; // NULL assigned
}
Darray::~Darray()
{
    cout << "sewa samapt";
    delete ptr;
}
void Darray::createArray(int size)
{

    capacity = size;
    ptr = new int[capacity];
    cout << "****************Array Created \n*******************";
}

void Darray::doubleArray()
{

    int *temp = new int[capacity * 2];
    for (int i = 0; i <= lastindex; i++)
    {
        temp[i] = ptr[i];
    }
    cout << "capacity doubled";
    delete[] ptr; // will delete the memory block pointed by ptr
    ptr = temp;   //*ptr will now point to arry temp;

    capacity *= 2;
}
void Darray::halfArray(){
    int *temp = new int[capacity/2];
    for(int i = 0 ; i <= lastindex ; i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;

    capacity/=2;





}

void Darray::append(int data)
{
    // check
    if (lastindex > capacity - 1)
    {
        doubleArray();
    }
    else if (lastindex < -1)
    {
        cout << "Underflow\n";
    }
    else
    {
        ptr[++lastindex] = data;
    }
}
void Darray::insert(int index, int data)
{
    if (index < 0 || index > capacity)
    {
        cout << "Invalid index\n";
    }
    else
    {
        if (lastindex == capacity - 1)
            doubleArray();

        for (int i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastindex++;
    }
}
int Darray::getByIndex(int index){
    if(index>lastindex||index<0)
   { cout<<"Invalid Index \n";
    return -1;}
    else
    return ptr[index];

}



    void Darray::remove(int index){
    {
        if (index < 0 || index > lastindex)
        {
            cout << "Invalid Index\n";
        }
        else{
            if(lastindex<=capacity/2)
            halfArray();
            for(int i = index ; i<=lastindex ; i++)
            ptr[i]=ptr[i+1];

            lastindex--;
            
        }
    }
}
void Darray::edit(int index , int newdata){
    if(index>lastindex||index<0)
    cout<<"Invalid Index \n";
    else{
        ptr[index]=newdata;
    }
}
int Darray::search(int data){
    for(int i = 0 ; i <= lastindex ; i++){
        if(ptr[i]==data)
        {
            return i;
        }
    }
    return -1;
}
void Darray::viewAll()
{
    
    cout << "\nELEMENETS IN ARRAY**************** \n";
    for (int i = 0; i <= lastindex; i++)
    {
        cout << "\n " << ptr[i] << " \n";
    }
    cout << "CURRENT_INDEX = " << lastindex << "\nCURRENT_SIZE = " << capacity << "\nTOTAL ELEMENT = "<<lastindex+1<<endl;
}
int main()
{
    Darray d1;
    d1.createArray(3);
    d1.append(11);
    d1.append(12);
    d1.append(13);
    d1.insert(1, 20);
    d1.viewAll();
    d1.append(14);
    d1.append(15);
    d1.remove(1);

    cout<<"index of 12 is "<<d1.search(18);

    d1.viewAll();
}
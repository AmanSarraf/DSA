#include <iostream>
using namespace std;
class Array
{
    int size;
    int lastindex;
    int *a;

public:
    Array();
    void createarray(int size);
    void append(int data);
    void insert(int index, int data);
    void del(int index);
    int search(int data);
    int getdata(int index);
    int count();
    void show();
    void edit(int index, int data);
    void Double();
    ~Array();
};
void Array::Double()
{
    size = size * 2;
}
Array::Array()
{
    size = 0;
    lastindex = -1;
    a = NULL;
}
void Array::createarray(int siz)
{
    size = siz;
    a = new int[size];
}
void Array::append(int data)
{
    if (lastindex == size - 1)
    {
        Array::Double();
    }
    else
    {
        ++lastindex;
        a[lastindex] = data;
    }
}
void Array::insert(int index, int data)
{
    if (index < 0 || index > lastindex + 1)
    {
        cout << "INVALID";
    }
    else if (lastindex == size - 1)
    {
    Array:
        Double();
    }
    else if (index == lastindex + 1)
    {
        a[index] = data;
        lastindex++;
    }

    else
    {
        int i;
        for (i = lastindex; i >= index; i--)
        {
            a[i + 1] == a[i];
        }
        a[index] = data;
        lastindex++;
    }
}
void Array::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "CANNOT DELETE";
    }
    // else if(lastindex=size-1)
    // {
    //     cout<<"OVERFLOW";
    // }

    else
        for (int i = index; i <= lastindex; i--)
        {
            a[i] = a[i + 1];
        }
    lastindex--;
}

int Array::search(int data)
{

    for (int i = 0; i <= lastindex; i++)
    {
        if (a[i] == data)
            return i;
        else
            return -1;
    }
}
int Array::getdata(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "Invalid Index";
    }
    else
    {
        return a[index];
    }
}
int Array::count()
{
    return lastindex + 1;
}

void Array::show()
{
    for (int i = 0; i <= lastindex; i++)
    {
        cout << " " << a[i] << "\n";
    }
}
void Array::edit(int index, int data)
{

    if (index < 0 || index > lastindex)
        cout << "can't Edit for this index";
    else
        a[index] = data;
}
Array::~Array()
{
    cout << "SEWA SAMAPT";
    delete[] a;
}
int main()
{
    Array a1;
    int siz, n;
    cout << "Enter size of array";
    cin >> siz;
    a1.createarray(siz);
    for (int i = 0; i < siz; i++)
    {
        cout << "Enter" << i + 1 << "Element\n";
        cin >> n;
        a1.append(n);
    }

    a1.show();
    for (int i = 0; i < siz; i++)
    {
        cout << "Enter" << i + 1 << "Element\n";
        cin >> n;
        a1.append(n);
    }
    a1.show();

    cout<<"no. of elements \n"<<a1.count();
}
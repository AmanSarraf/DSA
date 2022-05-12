#include"array.cpp"
using namespace std;

class Stack:private Array
{
    
public:
int top;
    Stack(int size)
    {
        createarray(size);
        int top=-1;
    }
    void push(int data)
    {
        ++top;
        append(data);
        

    }
    int pop()
    {
        int i=getdata(top);
       
       del(top);
       top--;
       return i;

    }

    void peek()
    {
      cout<<getdata(top);   
    }

};


int main()
{
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    
    //s1.pop();

    //cout<<s1.pop();
    s1.peek();

    

}

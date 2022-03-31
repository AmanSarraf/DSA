#include"array.cpp"
using namespace std;

class Stack:private Array
{
    int top;
public:
    Stack(int size)
    {
        createarray(size);
        int top=-1;
    }
    void push(int data)
    {
        append(data);
        top++;

    }
    void pop()
    {
       
       del(top);
       top--;

    }

    void peek()
    {
      cout<<getdata(count()-1);   
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
    
    s1.pop();
    s1.peek();

    

}

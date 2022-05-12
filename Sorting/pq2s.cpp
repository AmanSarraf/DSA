#include<bits/stdc++.h> 
using namespace std; 
  
typedef pair<int, int> PP; 
  
class Stack{ 
      
    int count; 
    priority_queue< pair<int, int> > pq; 
    
    public: 
     
        void push(int n)
        {
            
    count++; 
    pq.push(PP(count, n)); 

        } 


        void pop()
        { 
    if(pq.empty()){ 
        cout<<"Stack is Empty";
    } 
    count--; 
    pq.pop(); 
}
        int top()
        { 
    PP temp=pq.top(); 
    return temp.second; 
} 
        bool isEmpty()
        { 
    return pq.empty(); 
} 
}; 
  
  
int main(){
    
    Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    s.push(40); 
    s.push(50); 
     cout<<"This is Question no.2 \n The top of Stack is now  "<<s.top()<<endl;
     cout<<"one Element popped\n ";
     s.pop();
     cout<<"After pop now the top is "<<s.top()<<endl;


     cout<<"Elements in stack"<<"\n";        


    while (!s.isEmpty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
    
  
}
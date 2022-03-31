#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
class cll
{
    struct node
    {
        int info;
        node *next;
    };

public:
    node *last;
    cll()
    {
        last = NULL;
    }
    node *search(int element)
    {
        if (last == NULL)
        {
            cout << "list Empty";
        }
        else
        {
            node *t;
            t = last->next;
            do
            {
                if(t->info==element)
                return t;

                t=t->next;
            } while (t!=last->next);
            return NULL;
            
        }
    }

    void insertfirst(int data)
    {

        node *n = new node;
        n->info = data;
        if (last == NULL)
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
        }
    }
    void insertlast(int data)
    {
        node *n = new node;
        n->info = data;
        if (last == NULL)
        {
            n->next = n;
            last = n;
        }
        else
        {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }

//<==============search check==================>
void check(int a)
{
    node *t=search(a);
    if(t==NULL)
    {
        cout<<"\nNot found\n";
    }
    else
    {
        cout<<"\nfound\n";
    }
}



    void insertafter(int ele, int data)
    {
        node *tmp=search(ele);
        if(tmp==NULL)
        {
            cout<<"\nElement you are searching not found\n";

        }
        else
        {
            node *n=new node;
            n->info=data;
            n->next=tmp->next;
            tmp->next=n;
        }
    }
    void deletefirst()
    {
        if (last == NULL)
        {
            cout << "UNDERFLOW";
        }
        else
        {
            if (last->next == last)
            {
                delete last;
                last = NULL;
            }
            else
            {
                node *t;
                t = last->next;
                last->next = t->next;
                delete t;
            }
        }
    }
    void deletelast()
    {
        if (last == NULL)
        {
            cout << "UNDERFLOW";
        }
        else
        {
            if (last->next == last)
            {
                delete last;
                last = NULL;
            }
            else
            {
                node *t;
                t = last->next;
                while (t->next != last)
                {
                    t = t->next;
                }
                t->next = last->next;
                delete last; // last jisko point kr raha hai use udaya phle
                last = t;
                delete t;
            }
        }
    }
    void deleteafter(int elm)
    {
       node *t1=search(elm);
       if(t1==NULL)
       {
           cout<<"Not found";
       }
       else
       {
           cout<<"found\n";
           node *t2;
            t2=t1->next;
            //cout<<"\n"<<t2->info;
            //t1->next=t2->next;
            t1->next=t2->next;
            delete t2;
            t1=t2;  // delete krne ke baad agar fir block ko connect nhi kra to wRNING hogi
            
            
           
            //cout<<"\n"<<t1->info;
        //    delete t2;

       }
      
                
    }

 void deletenode(int elm)
    {
       node *t1=search(elm);
       if(t1==NULL)
       {
           cout<<"Not found";
       }
       else
       {
           node *t;
           t=last->next;
           do
           {
               t=t->next;
           }while(t->next!=t1);
           if(t->next==t1)
           {
               t->next=t1->next;
               delete t1;
               

           }


       }

    }


    void viewcll()
    {

        if (last == NULL)
        {
            cout << "List empty";
        }
        node *tmp;
        tmp = last->next;
        do
        {
            cout << tmp->info << " ";
            tmp = tmp->next;
            /* code */
        } while (tmp != last->next);
        cout<<endl;
    }
    
    ~cll()
    {
        while (last)
            deletefirst();
    }
};
int main()
{
    cll c1;
    c1.insertfirst(10);
    c1.insertfirst(20);
    c1.insertfirst(30);
    //c1.deleteafter(30);
     c1.deletenode(20);
    // c1.deleteafter(30);
    
     c1.viewcll();

}
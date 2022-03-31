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
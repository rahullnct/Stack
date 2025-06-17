
//implementation of stack using array

#include<iostream>
using namespace std;
class stack{

    int size;
    int arr[10];
    int top=-1;

    public:
    stack(int size)
    {
        this->size=size;
        top=-1;
    }

    void push(int val)
    {
        if(top>=size-1 )
        {
            cout<<"overflow"<<endl;
            return;
        }
        top=top+1;
        arr[top]=val;
    }

    void pop()
    {
       if(top<0)
       {
        cout<<"stack is empty"<<endl;
        return;
       }
       top=top-1;
    }
    int topofstack()
    {
      return arr[top];
    }
};
int main()
{
   stack st(10);
   st.push(2);
   st.push(4);
   st.pop();
   st.push(7);
   cout<<st.topofstack()<<endl;
   st.pop();
   cout<<st.topofstack()<<endl;
}
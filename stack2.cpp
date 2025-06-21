#include<iostream>
#include<climits>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class stack
{
    node* head;
    
    public:
    stack()
    {
        head=NULL;
    }
    bool isempty()
    {
        return head==NULL;
    }
    void push(int val)
    {
        node* temp = new node(val);
        if(!temp)
        {
            cout<<"stack is overflow"<<endl;
            return;
        }
        temp->next=head;
        head=temp;
    }
   
    void pop()
   {
     node* temp=head;
    if(isempty())
    {
        cout<<"stack is empty"<<endl;
        return;
    }
    head=head->next;
    delete temp;
   }
   
   int top()
   {
     if(isempty())
     {
        cout<<"stack is Empty"<<endl;
        return INT_MIN;
     }
     return head->data;
   }
};
int main()
{
    stack st;
    st.push(2);
    st.push(5);
    st.push(7);
    st.pop();
    st.pop();
    st.push(8);
    cout<<st.top()<<endl;
    st.push(6);
    st.push(9);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    st.push(2);
    st.push(5);
    st.push(7);
    st.push(2);
    st.push(5);
    st.push(7);
    st.push(2);
    st.push(5);
    st.push(7); 
    cout<<st.top()<<endl;
    
}
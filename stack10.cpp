

// prefix maximum array
#include<iostream>
using namespace std;
void solve(int arr[10],int n,int prefix[10])
{
    prefix[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=max(prefix[i-1],arr[i]);
    }
}

// suffix maximum array
void solve2(int arr[10],int n,int suffix[10])
{
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=max(suffix[i+1],arr[i]);
    }
}


int main()
{
    int arr[10]={4,2,12,5,11,3,5,9,8,10};
    int n=10;
    int prefix[10];
    int suffix[10];
    solve(arr,n,prefix);
    solve2(arr,n,suffix);
    cout<<"suffix maximum array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<suffix[i]<<" ";
    }
    cout<<endl;
    cout<<"prefix maximum array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<prefix[i]<<" ";
    }
}
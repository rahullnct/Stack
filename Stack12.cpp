#include<iostream>
using namespace std;
void solve(int arr[6],int n,int nge[6])
{
    nge[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        nge[i]=max(nge[i+1],arr[i]);
    }
}
void solve2(int arr[6],int n,int pge[6])
{
    pge[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        pge[i]=max(pge[i-1],arr[i]);
    }
}
int storedwater(int arr[6],int pge[6],int nge[6],int n)
{
    int water=0;
    for(int i=0;i<n;i++)
    {
        int leftmax=pge[i];
        int rightmax=nge[i];
        if(arr[i]<leftmax && arr[i]<rightmax)
        {
            water+=min(leftmax,rightmax)-arr[i];
        }
    }
    return water;
}
int main()
{
    int arr[6]={4,2,0,3,2,5};
    int n=6;
    int nge[6];
    int pge[6];
    solve(arr,n,nge);
    solve2(arr,n,pge);
    int ans=storedwater(arr,pge,nge,n);
    cout<<ans<<endl;
}
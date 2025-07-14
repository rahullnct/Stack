#include<iostream>
#include<deque>
#include<vector>
using namespace std;
void solve(int arr[8],int n,int k, vector<int>&ans)
{
    deque<int>dq;
    
    for(int i=0;i<n;i++)
    {
        if(!dq.empty() && dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.front()]<=arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)
        {
            ans.push_back(arr[dq.front()]);
        }
    }
}
int main()
{
    int arr[8]={1,3,-1,-3,5,3,6,7};
    int n=8;
    int k=3;
    vector<int>ans;
    solve(arr,n,k,ans);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
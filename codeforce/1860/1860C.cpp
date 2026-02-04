#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=3e5+10;
int fw[N],fw2[N];
void update(int val,int i)
{
    for(;i<N;i+=i&-i)
    {
        fw[i]+=val;
    }
}
int sum(int i)
{
    int ans=0;
    for(;i>0;i-=i&-i)
    {
        ans+=fw[i];
    }
    return ans;
}
void update2(int val,int i)
{
    for(;i<N;i+=i&-i)
    {
        fw2[i]+=val;
    }
}
int sum2(int i)
{
    int ans=0;
    for(;i>0;i-=i&-i)
    {
        ans+=fw2[i];
    }
    return ans;
}
void solve()
{ 
    int n,anss=0;
    cin>>n;
    for(int i=1;i<=n;i++)fw[i]=fw2[i]=0;
    int arr[n],idx[n];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)idx[arr[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(sum(idx[i])==sum2(idx[i])&&sum(idx[i])!=0)anss++;
        if(sum(idx[i])==0)update2(1,idx[i]);
        update(1,idx[i]);
    }
    cout<<anss<<"\n";

}
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
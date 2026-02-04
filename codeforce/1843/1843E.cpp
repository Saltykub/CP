#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e5+10;
pii seg[N];
int change[N];
void solve()
{ 
     int n,m,q;
     cin>>n>>m;
     for(int i=1;i<=m;i++)
     {
        cin>>seg[i].st>>seg[i].nd;
     }
     cin>>q;
     for(int i=1;i<=q;i++)
     {
        cin>>change[i];
     }
     int l=1,r=q;
     while(l<r)
     {  
        int arr[n+5];
        for(int i=1;i<=n;i++)arr[i]=0;
        int mid=(l+r)/2;
        for(int i=1;i<=mid;i++)
        {
            arr[change[i]]=1;
        }
        for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
        bool can=false;
        for(int i=1;i<=m;i++)
        {
            if(arr[seg[i].nd]-arr[seg[i].st-1]>seg[i].nd-seg[i].st+1-arr[seg[i].nd]+arr[seg[i].st-1])
            {
                can=true;
                break;
            }
        }
        if(can==true)r=mid;
        else l=mid+1;
     }
     if(l!=q)cout<<l;
     else 
     {
        int arr[n+5];
        for(int i=1;i<=n;i++)arr[i]=0;
        for(int i=1;i<=q;i++)
        {
            arr[change[i]]=1;
        }
        for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
        bool can=false;
        for(int i=1;i<=m;i++)
        {
            if(arr[seg[i].nd]-arr[seg[i].st-1]>seg[i].nd-seg[i].st+1-arr[seg[i].nd]+arr[seg[i].st-1])
            {
                can=true;
                break;
            }
        }
        if(can==true)cout<<q;
        else cout<<-1;
     }
     cout<<"\n";


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
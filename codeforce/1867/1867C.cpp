#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    bool done=false;
    if(arr[0]==0)
    {   
        if(n==1){cout<<1<<"\n";cout.flush();}
        else{
        for(int i=1;i<n;i++)
        {
            if(arr[i]-1!=arr[i-1])
            {
                cout<<arr[i-1]+1<<"\n";
                cout.flush();
                done=true;
                break;
            }
        }
        if(arr[n-1]-1==arr[n-2]&&!done){cout<<arr[n-1]+1<<"\n";cout.flush();}}
    }
    else 
    {
        cout<<0<<"\n";
        cout.flush(); 
    }
    int cnt=0;
    int y;
    while(true)
    {
        cin>>y;
        if(y==-1)break;
        cout<<y<<"\n";
        cout.flush();
    }
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
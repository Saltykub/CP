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
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int check[n+3];
    for(int i=0;i<n+3;i++)check[i]=0;
    int can=true;
    for(int i=0;i<n;i++)
    {   
        if(arr[i]>n)
        {
            can=false;
            break;
        }
        check[0]++;
        check[arr[i]]-=1;
    }
    for(int i=1;i<n;i++)
    {   
        check[i]+=check[i-1];
    }
    // for(int i=0;i<n;i++)cout<<check[i];
    for(int i=0;i<n;i++)if(check[i]!=arr[i])can=false;
    if(can==false)cout<<"NO";
    else cout<<"YES";
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
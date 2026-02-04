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
    int mn=INT_MAX;
    while(n--)
    {
        int x;
        cin>>x;
        x=abs(x);
        mn=min(x,mn);
    }
    cout<<mn;
}
int main()
{ 
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
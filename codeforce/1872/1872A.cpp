#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int a,b,c;
    cin>>a>>b>>c;
    int half=ceil(1.0*(a+b)/2);
    half-=min(a,b);
    cout<<ceil(1.0*half/c);
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
#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    ll n,x,y;
    cin>>n>>x>>y;
    ll gcd=__gcd(x,y);
    ll lcm=x*y/gcd;
    lcm=n/lcm;
    //cout<<lcm;
    x=n/x;
    y=n/y;
    x-=lcm;
    y-=lcm;
    cout<<(n*(n+1))/2-((n-x)*(n-x+1))/2-(y*(y+1))/2;
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
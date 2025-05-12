#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int main()
{
    ll x;
    cin>>x;
    cout<<x<<" ";
    while(x!=1)
    {
       if(x%2==0)x/=2;
       else x=x*3+1;
       cout<<x<<" ";
    }
}

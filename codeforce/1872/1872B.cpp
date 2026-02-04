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
        int d,s;
        cin>>d>>s;
        mn=min(mn,(s-1)/2+d);
    }
    cout<<mn<<"\n";

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
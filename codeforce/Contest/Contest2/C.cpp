#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k==1)cout<<1;
    else if(k==2)
    {
        if(m>=n)
        {
            cout<<m/n+(n-1);
        }
        else 
        {
            cout<<m;
        }
    }
    else if(k==3)
    {
        if(m<=n)cout<<0;
        else cout<<(n-1)*(m/n-1)+m%n;
    }
    else cout<<0;
    cout<<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int m,k,a1,ak,ans=0;
    cin>>m>>k>>a1>>ak;
    int opa1,opak;
    opak=m/k;
    opa1=m-(m/k)*k;
    if(a1<opa1)ans+=opa1-a1;
    if(ak<opak)
    {   
        opak-=ak;
        if(a1-opa1>0)
        {   
            int akplus=(a1-opa1)/k;
            opak-=akplus;
            if(opak<0)opak=0;
            ans+=opak;
        }
        else 
        {
            ans+=opak;
        }
    }
    cout<<ans<<"\n";
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
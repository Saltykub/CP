#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const ll N=2e5+10;
const ll mod=998244353;
ll fac[N];
void solve()
{
    string s;
    cin>>s;
    char now=s[0];
    ll ct=1;
    ll c=0;
    ll nub=0;
    ll ans=1;
    ll sz=s.size();
    for(int i=1;i<sz;i++)
    {
        if(now==s[i])
        {
            ct++;
        }
        else
        {   
            c+=ct-1;
            ans*=ct;
            ans%=mod;
            if(ans<0)ans+=mod;
            ans%=mod;
            now=s[i];
            ct=1;
        }
    }
    if(ct>1)nub++;
    c+=ct-1;
    ans*=ct;
    ans%=mod;
    if(ans<0)ans+=mod;
    ans*=fac[c];
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<c<<" "<<ans<<"\n";
    
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    fac[0]=1;
    fac[1]=1;
    for(int i=1;i<N;i++)
    {
    fac[i]=((fac[i-1]%mod)*i)%mod;
    fac[i]%=mod;
    if(fac[i]<0)fac[i]+=mod;
    fac[i]%=mod;
    }
    //cout<<fac[N-5];
    while(t--)
    {
        solve();
    }
}
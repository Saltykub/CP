
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
    string ss;
    cin>>ss;
    int cnt[26];
    memset(cnt,0,sizeof cnt);
    for(auto u:ss)cnt[u-'a']++;
    sort(cnt,cnt+26,greater<int>());
    if(cnt[0]<=n/2)cout<<n%2;
    else cout<<cnt[0]-(n-cnt[0]);
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

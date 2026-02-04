#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e6+7;
struct d {
    int val;
    int from;
};
bool comp(pair<d,d> a,pair<d,d> b){
    if(a.st.val==b.st.val) return a.nd.val>b.nd.val;
    return a.st.val>b.st.val;
}
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n];
    pii sum[n];
    ll ans=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++){sum[i].st=a[i]+b[i],sum[i].nd=i;}
    sort(sum,sum+n,greater<pii>());
    for(int i=0;i<n;i++)(i%2) ? ans-= b[sum[i].nd]-1 : ans+=a[sum[i].nd]-1;
    cout<<ans<<"\n";
}

int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e5+5;
deque<ll> v[N];
void solve(){
    ll x,k;
    cin>>x>>k;
    if(x==1&&k==7){
        cout<<x<<" "<<k<<endl;
        for(int i{
            int sz;cin>>sz;cout<<sz<<" ";
            while(sz--){
            ll val;
            cin>>val;
            cout<<val<<" ";
        }
        cout<<endl;
        }
    }
    // cout<<"PASS";
    ll ans=x;
    for(int i=1;i<=k;i++){
        ll sz;
        cin>>sz;
        while(sz--){
            ll val;
            cin>>val;
            v[i].pb(val);
        }
    }
    // cout<<"PASS";
    priority_queue<pii>pq;
    for(int i=1;i<=k;i++){
        pq.push({v[i].front(),i});
        v[i].pop_front();
    }
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        x+=top.st;
        ans=max(ans,x);
        if(x<0)break;
        if(!v[top.nd].empty()){
            pq.push({v[top.nd].front(),top.nd});
            v[top.nd].pop_front();
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}
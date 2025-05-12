#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll x,q;
    cin >> x >> q;
    set<ll> s;
    s.insert(0);
    s.insert(x);
    priority_queue<pair<int,pii>> pq;
    map<pair<int,int>,ll> mp;
    while(q--){
        int a;
        cin >> a;
        auto lb = s.lower_bound(a), ub = s.upper_bound(a);
        lb--;
        pq.push({a-*lb,{*lb,a}});
        pq.push({*ub-a,{a,*ub}});
        mp[{*lb,*ub}] = 1;
        s.insert(a);
        while(true){
            auto [val,lr] = pq.top();
            if(mp[lr]){
                pq.pop();
            }
            else {
                //cout << l << " " << r << "\n";
                cout << val << "\n";
                break;
            }
        }
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
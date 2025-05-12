#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++) cin >> arr[i], mp[arr[i]]++;
    vector<pair<int,int>> v;
    ll mx = 0, cur = 0;
    int j = 0, sz = 0;
    for(auto u:mp){
        if(v.size() == 0){
            cur+=u.nd;
            sz++;
            v.pb({u.st,u.nd});
        }
        else {
            if(u.st-1 != v[v.size()-1].st){
                mx = max(mx,cur);
                cur = u.nd;
                v.clear();
                v.pb({u.st,u.nd});
                j = 0;
                sz = 1;
                continue;
            }
            if(sz == k){
                mx = max(mx,cur);
                cur-=v[j].nd;
                j++;
                cur+=u.nd;
                mx = max(mx,cur);
                v.pb({u.st,u.nd});
            }else {
                cur+=u.nd;
                sz++;
                v.pb({u.st,u.nd});
            }
        }
    }
    mx = max(mx,cur);
    cout << mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
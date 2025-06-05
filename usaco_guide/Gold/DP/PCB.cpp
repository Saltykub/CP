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
    int n;
    cin >> n;
    vector<pii> interval;
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        interval.pb({u,v});
    }
    sort(interval.begin(),interval.end(),greater<pii>());
    vector<int> lis;
    for(int i = 0; i < n; i++){
        auto ub = upper_bound(lis.begin(),lis.end(),interval[i].nd);
        if(ub == lis.end()) lis.pb(interval[i].nd);
        else *ub = interval[i].nd;
    }
    cout << lis.size();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
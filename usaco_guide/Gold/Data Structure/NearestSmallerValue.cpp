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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    stack<pii> s;
    vector<int> ans(n,0);
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && s.top().st > v[i]){
            auto [cur,idx] = s.top();
            s.pop();
            ans[idx] = i+1;
        }
        s.push({v[i],i});
    }
    for(auto u:ans) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
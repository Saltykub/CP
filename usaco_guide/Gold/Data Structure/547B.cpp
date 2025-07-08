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
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    stack<pii> s;
    vector<ll> ans(n+10,0);
    vector<ll> l(n+1,-1), r(n+1,n);    
    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().st >= v[i]){
            s.pop();
        }
        if(!s.empty()) l[i] = s.top().nd;
        s.push({v[i],i});
    }
    while(!s.empty()) s.pop();
    for(int i = n-1; i >= 0; i--){
         while(!s.empty() && s.top().st >= v[i]){
            s.pop();
         }
        if(!s.empty()) r[i] = s.top().nd;
        s.push({v[i],i});
    }
    for(int i = 0; i < n; i++){
       // cout << r[i] << " " << l[i] << "\n";
        int idx = r[i]-l[i]-1;
       // cout << idx << " " << v[i] << "\n";
        ans[idx] = max(ans[idx],v[i]);
    }
    for(int i = n; i >= 0; i--){
       ans[i] = max(ans[i],ans[i+1]);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
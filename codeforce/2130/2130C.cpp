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
    int n;
    cin >> n;
    vector<pair<pii,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].st.st >> v[i].st.nd;
        v[i].nd = i+1;
    }
    sort(v.begin(),v.end(),[&](pair<pii,int> a, pair<pii,int> b){
        if(a.st.st == b.st.st) return a.st.nd > b.st.nd;
        return a.st.st < b.st.st;
    });
    vector<int> ans;
    ll cur = 0;
    for(int i = 0; i < n; i++){
        auto[ab,idx] = v[i];
        auto[a,b] = ab;
        if(b > cur){
            ans.pb(idx);
            cur = b;
        }
    }
    cout << ans.size() << "\n";
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
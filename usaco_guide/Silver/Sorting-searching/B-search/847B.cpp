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
    vector<int> arr(n);
    set<pii> s;
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(auto u:arr){
        auto it = s.lower_bound({u,-1});
        if(s.empty() || it == s.begin()){
            vector<int> temp;
            temp.pb(u);
            ans.pb(temp);
            s.insert({u,ans.size()-1});
        }
        else {
            int idx = prev(it)->nd;
            s.erase(prev(it));
            ans[idx].pb(u);
            s.insert({u,idx});
        }
    }
    for(auto u:ans){
        for(auto v:u) cout << v << " ";
        cout << "\n";
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
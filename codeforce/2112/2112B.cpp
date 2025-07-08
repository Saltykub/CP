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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int l = INT_MAX, r = INT_MAX;
        for(int j = i+1; j < n; j++){
            if(v[j] >= v[i]-1 && r == INT_MAX) r = j;
            if(v[j] <= v[i]+1 && l == INT_MAX) l = j;
        }
        if(l != INT_MAX && r != INT_MAX) ans = min(ans,max(l,r)-i-1);
    }
    for(int i = n; i >= 0; i--){
        int l = INT_MAX, r = INT_MAX;
        for(int j = i-1; j >= 0; j--){
            if(v[j] >= v[i]-1 && r == INT_MAX) r = j;
            if(v[j] <= v[i]+1 && l == INT_MAX) l = j;
        }
        if(l != INT_MAX && r != INT_MAX) ans = min(ans,i-min(l,r)-1);
    }
    if(ans == INT_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
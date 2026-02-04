#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    set<int> s;
    for(auto u:v) s.insert(u);
    vll ans(n+1,INT_MAX);
    for(int i = 1; i <= n; i++){
        if(s.count(i)){
            ans[i] = 1;
            cout << 1 << " ";
            continue;
        }
        for(int j = 1; j <= sqrt(i); j++){
            if(i%j == 0){
                if(s.count(j) && s.count(i/j)){
                    ans[i] = min(ans[i],ans[j]+ans[i/j]);
                }
            }
        }
        if(ans[i] == INT_MAX) cout << -1 << " ";
        else {
            s.insert(i);
            cout << ans[i] << " ";
        }
    }
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
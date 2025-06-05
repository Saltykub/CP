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
    ll h,w,n;
    cin >> h >> w >> n;
    set<int> row[h+1], col[w+1];
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }
    int q;
    cin >> q;
    while(q--){
        int op, val;
        cin >> op >> val;
        //cout << "PASS";
        if(op == 1){
            cout << row[val].size() << "\n";
            for(auto u:row[val]){
                col[u].erase(val);
            }
            row[val].clear();
        }
        else {
            cout << col[val].size() << "\n";
            for(auto u:col[val]){
                row[u].erase(val);
            }
            col[val].clear();
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
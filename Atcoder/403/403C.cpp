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
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> all(n,0);
    set<int> s[n];
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x,y;
            cin >> x >> y;
            --x;
            s[x].insert(y);
        }
        else if(op == 2){
            int x;
            cin >> x;
            --x;
            all[x] = 1;
        }
        else {
            int x,y;
            cin >> x >> y;
            --x;
            if(s[x].find(y) != s[x].end() || all[x]) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
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
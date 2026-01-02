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
bool CASE = false;
void solve (){
    int n,q;
    cin >> n >> q;
    vector<pii> v;
    for(int i = n; i >= 1; i--) v.pb({i,0});
    int cnt = 0;
    while(q--){
        int op;
        cin >> op;
        if(op == 2){
            int x;
            cin >> x;
            int sz = sz(v);
            cout << v[sz-x].st << " " << v[sz-x].nd << "\n";
        }
        else {
            cnt++;
            char di;
            cin >> di;
            auto fr = v.back();
            if(di == 'R') v.pb({++fr.st,fr.nd});
            if(di == 'L') v.pb({--fr.st,fr.nd});
            if(di == 'U') v.pb({fr.st,++fr.nd});
            if(di == 'D') v.pb({fr.st,--fr.nd});
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
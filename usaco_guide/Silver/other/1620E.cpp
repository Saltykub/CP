#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
int p[N];
bool CASE = false;
int fp(int n) {
    return p[n] == n ? n : p[n] = fp(p[n]);
}
void solve (){
    int q;
    cin >> q;
    vector<pair<int,vector<int>>> qq;
    for(int i = 0; i < q; i++){
        int op,x,y;
        vector<int> temp;
        cin >> op >> x;
        temp.pb(x);
        if(op == 1){
            qq.pb({op,temp});
        }
        else {
            cin >> y;
            temp.pb(y);
            qq.pb({op,temp});
        }
    }
    vector<int> ans;
    for(int i = 1; i < N; i++) p[i] = i;
    reverse(qq.begin(),qq.end());
    for(auto u:qq){
        if(u.st == 1){
            ans.pb(fp(u.nd[0]));
        }
        else {
            p[u.nd[0]] = p[u.nd[1]];
        }
    }
    reverse(ans.begin(),ans.end());
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
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
    int n,q;
    cin >> n >> q;
    vector<int> op(q), p(q);
    vector<string> s(q);
    string server = "";
    for(int i = 0; i < q; i++){
        cin >> op[i] >> p[i];
        if(op[i] == 2) {
            string x;
            cin >> x;
            reverse(x.begin(),x.end());
            s[i] = x;
        }
    }
    int cur = 0;
    for(int i = q-1; i >= 0; i--){
        if(op[i] == 1){
            if(cur == p[i]) cur = 0;
        }
        else if(op[i] == 2){
            if(cur == p[i]) server += s[i];
        }
        else {
            if(cur == 0) cur = p[i];
        }
    }
    reverse(server.begin(),server.end());
    cout << server;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
    ll n;
    cin >> n;
    vll v(n);
    ll ret = 0;
    for(auto &u:v) cin >> u;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll sm = 0;
            for(int k = i; k <= j; k++){
                sm += v[k];
            }
            bool can = true;
            for(int k = i; k <= j; k++){
                if(sm%v[k] == 0){
                    can = false;
                }
            }
            if(can) ret++;
        }
    }
    cout << ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
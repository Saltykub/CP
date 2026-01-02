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
    int x,n;
    cin >> x >> n;
    vll v(n),ch(n+1,0);
    for(auto &u:v) cin >> u;
    int q;
    cin >> q;
    while(q--){
        int p;
        cin >> p;
        if(ch[p]){
            ch[p] = 0;
            x -= v[p-1];
        }
        else{
            ch[p] = 1;
            x += v[p-1];
        }
        cout << x << "\n";
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
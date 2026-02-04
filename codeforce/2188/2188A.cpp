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
    vll ret;
    ret.pb(1);
    int x = 1;
    for(int i = n-1; i >= 1; i--){
        if(x){
            ret.pb(i+ret.back());
        }
        else {
            ret.pb(ret.back()-i);
        }
        x^=1;
    }
    reverse(all(ret));
    for(auto u:ret) cout << u << " ";
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
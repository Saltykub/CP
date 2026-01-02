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
    ll n,l,r;
    cin >> n >> l >> r;
    int prev = 0;
    for(int i = 1; i <= n; i++){
        if(i == r){
            cout << (prev^(l-1)) << " ";
            prev = l-1;
            continue;
        }
        cout << (i^prev) << " ";
        prev = i;
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
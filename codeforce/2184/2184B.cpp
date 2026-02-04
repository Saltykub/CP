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
    ll s,k,m;
    cin >> s >> k >> m;
    ll time = m/k;
    if(time%2){
        cout << max(0LL,min(k,s)-(m-time*k)) << "\n";
    }
    else {
        cout << max(0LL,s-(m-time*k)) << "\n";
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
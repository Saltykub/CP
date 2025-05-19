#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
void solve (){
    double n,k;
    cin >> n >> k;
    double exp = 0;
    for(double i = 1; i <= k; i++){
        exp += 1.0 * i * (pow(i/k,n) - pow((i-1)/k,n)); 
    }
    cout << setprecision(6) << fixed;
    cout << exp;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
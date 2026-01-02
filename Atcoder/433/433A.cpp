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
    // a + x = ky , kb + kx = ky (a-kb/(k-1)) = kb + k-1(x) 
    int a,b,k;
    cin >> a >> b >> k;
    if((a-k*b) >= 0 && (a-k*b)%(k-1) == 0) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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
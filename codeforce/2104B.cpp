#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n;
    cin >> n;
    vector<int> v(n);
    vector<int> mx(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    mx[0] = v[0];
    for(int i = 1; i < n; i++){
        mx[i] = max(mx[i-1],v[i]);
    }
    ll sm = v[n-1];
    cout << mx[n-1] << " ";
    for(int i = n-2; i >= 0; i--){
        cout << mx[i] + sm << " ";
        sm += v[i];
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
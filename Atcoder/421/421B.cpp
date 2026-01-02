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
    vector<string> v(10);
    cin >> v[0] >> v[1];
    for(int i = 2; i < 10; i++){
        ll x = stoll(v[i-2]), y = stoll(v[i-1]);
        x += y;
        string cal = to_string(x);
        reverse(all(cal));
        v[i] = cal;
    }
    cout << stoll(v[9]);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
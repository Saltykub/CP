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
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(),v.end(),[&](ll a,ll b){
        return abs(a) < abs(b);
    });
    int pcnt = 0, ncnt = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == v[0]) pcnt++;
        else if(v[i] == -v[0]) ncnt++;
    }
    if(pcnt + ncnt == n && (pcnt == n/2 || ncnt == n/2)) {
        cout << "Yes\n";
        return;
    }
    int o = 1, e = 1;
    if(v[0] < 0) e = -1;
    if(v[1] < 0) o = -1;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            if((e == -1 && v[i] > 0) || (e == 1 && v[i] < 0)) {
                cout << "No\n";
                return;
            }
        }
        else {
            if((o == -1 && v[i] > 0) || (o == 1 && v[i] < 0)) {
                cout << "No\n";
                return;
            }
        }
    }
   
    ll g = __gcd(abs(v[0]),abs(v[1]));
    ll lcm = abs(v[0])*abs(v[1])/g;
    ll a = lcm/abs(v[0]), b = lcm/abs(v[1]);
    for(int i = 1; i < n; i++){
        if(abs(v[i-1])*a != abs(v[i])*b){
            cout << "No\n";
            return;
        }
    }
    cout  << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
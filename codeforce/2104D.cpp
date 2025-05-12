#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 6e6+10;
bool CASE = true;
vector<ll> prime(N,1);
vector<ll> cal;
void precom(){
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i)
                prime[j] = 0;
        }
    }
    for(int i = 2; i <= N; i++){
        if(prime[i]) cal.pb(i);
        if(cal.size() >= 400000) break;
    }
    for(int i = 1; i < cal.size(); i++){
        cal[i] += cal[i-1];
    }
}
void solve (){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll sm = 0;
    for(int i = 0; i < n; i++) sm += v[i];
    if(sm >= cal[n-1] || n == 1) {
        cout << 0 << "\n";
    }
    else {
        sort(v.begin(),v.end());
        int cur = n-1;
        int i = 0;
        while(true){
            sm -= v[i];
            if(sm >= cal[cur-1]){
                cout << n-cur << "\n";
                return;
            }
            cur--;
            i++;
        }
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    precom();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
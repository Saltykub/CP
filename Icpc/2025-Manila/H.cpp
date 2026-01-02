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
const int MxN = 1e7+10;
const int MOD = 104206969;
bool CASE = false;
vll isprime(MxN,0);
vll prime, three;
vll qs2(MxN,0),qs3(MxN,0);
void precom(){
    for(int i = 2; i < MxN; i++){
        if(isprime[i]) continue;
        prime.pb(i);
        for(int j = i; j < MxN; j+=i){
            isprime[j] = 1;
        }
    }
    for(int i = 0; i < sz(prime)-2; i++){
        if(prime[i+1]-prime[i] == 2){
            three.pb(prime[i+1]);
        }
    }
    int j = 0;
    for(int i = 1; i < MxN; i++){
        while(j < sz(prime) && prime[j] < i) j++;
        qs2[i] += qs2[i-1];
        qs2[i] += j;
        qs2[i] %= MOD;
    }
    j = 0;
    for(int i = 1; i < MxN; i++){
        while(j < sz(three) && three[j] < i)j++;
        qs3[i] += qs3[i-1];
        qs3[i] += 2*j;
        qs3[i] %= MOD;
    }
}
void solve (){
    int q;
    cin >> q;
    precom();
    while(q--){
        ll n,k;
        cin >> n >> k;
        if(k > 4) cout << 0 << "\n";
        else {
            if(k == 4){
                cout << max(n-7,0LL) << "\n";
            }
            else if(k == 3){
                cout << qs3[n] << "\n";
            }
            else if(k == 2){
                cout << qs2[n] << "\n";
            }
            else {
                cout << n << "\n";
            }
        }
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
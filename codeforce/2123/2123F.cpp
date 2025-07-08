#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
bool CASE = true;
vector<bool> isprime(N,true);
vector<int> prime;
void init(){
    for(int i = 2; i < N; i++){
        if(isprime[i]){
            prime.pb(i);
            for(int j = i+i; j < N; j+=i){
                isprime[j] = false;
            }
        }
    }
}
void solve (){
    int n;
    cin >> n;
    vector<int> ch(n+1,0),ans(n+1,0);
    vector<int> v[n+1];
    for(auto u:prime){
        if(u > n) break;
        if(2*u > n) {
            ans[u] = u;
            ch[u] = 1;
        }
        else {
            ch[2*u] = 1;
            v[u].pb(2*u);
        }
    }

    for(int i = 0; i < prime.size(); i++){
        if(prime[i] > n) break;
        if(ch[prime[i]]) break;
        for(int j = 3*prime[i]; j <= n; j+=prime[i]){
            if(!ch[j]){
                ans[v[prime[i]].back()] = j;
                v[prime[i]].pb(j);
                ch[j] = 1;
            }
        }
        ans[v[prime[i]].back()] = prime[i];
        ans[prime[i]] = v[prime[i]][0];
    }
    ans[1] = 1;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    init();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
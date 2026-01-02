#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> prime[N];
vector<int> mp(N,0);
vector<int> ch(N,0);
int cnt = 0;
void precom(){
    for(int i = 2; i < N; i++){
        if(!ch[i]){
            ch[i] = 1;
            cnt++;
            prime[i].pb(i);
            for(int j = i+i; j < N; j+=i){
                ch[j] = 1;
                prime[j].pb(i);
            }
        }
    }
}
void solve (){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    vector<int> tmp;
    map<ll,ll> m;
    for(int i = 0; i < n; i++){
       for(auto u:prime[a[i]]){
          mp[u]++;
          m[u]++;
       }
    }
    int ans = 2;
    for(auto u:m){
        if(u.nd >= 2){
            ans = 0;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        a[i]++;
        for(auto u:prime[a[i]]){
            if(mp[u]) ans = min(ans,1);
        }
    }
    for(auto u:m) mp[u.st] = 0;
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    precom();z
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
const int N = 1e6+100;
const int off = 5e5+10;
bool CASE = false;
ll fw[N];
void add(int i){
    for(;i < N; i+=(i&-i)){
        fw[i]++;
    }
}
ll qs(int i){
    ll ret = 0;
    for(;i; i-=(i&-i)){
        ret += fw[i];
    }
    return ret;
}
void solve (){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cur = 0,ans = 0;
    add(off);
    for(auto u:s){
        if(u == 'A'){
            cur++;
        }
        else if(u == 'B'){
            cur--;
        }
        ans += qs(cur-1+off);
        add(cur+off);
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
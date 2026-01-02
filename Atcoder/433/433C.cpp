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
    string s;
    cin >> s;
    int n = s.size();
    vector<pii> v;
    int cur = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            v.pb({s[i-1]-'0',cur});
            cur = 1;
        }
        else cur++;
    }
    v.pb({s[n-1]-'0',cur});
    int ret = 0;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i].st == v[i+1].st-1){
            ret += min(v[i].nd,v[i+1].nd);
        }
    }
    cout << ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
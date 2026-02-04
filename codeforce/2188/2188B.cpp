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
bool CASE = true;
void solve (){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int one = 0;
    vll v;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') cnt++;
        if(s[i] == '1'){
            v.pb(cnt);
            cnt = 0;
            one++;
        }
    }
    if(cnt == n){
        cout << ceil(1.0*cnt/3) << "\n";
        return;
    }
    v.pb(cnt);
    int ret = 0;
    if(v.size() == 1){
        if(s[0] == '1' && s[n-1] == '1'){
            cout << v[0]/3+one << "\n";
        }
        else {
            v[0]--;
            cout << ceil(1.0*v[0]/3)+one << "\n";
        }
        return;
    }
    if(s[0] == '0'){
        v[0]--;
        ret += ceil(1.0*v[0]/3);
    }
    else {
        ret += v[0]/3;
    }
    if(s[n-1] == '0'){
        v[sz(v)-1]--;
        ret += ceil(1.0*v[sz(v)-1]/3);
    }
    else {
        ret += v[sz(v)-1]/3;
    }
    for(int i = 1; i < sz(v)-1; i++){
        ret += v[i]/3;
    }
    cout << ret+one << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
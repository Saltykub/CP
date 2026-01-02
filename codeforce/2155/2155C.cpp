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
    vector<int> v(n);
    for(auto &u:v) cin >> u;
    vector<int> tmp = v;
    sort(tmp.begin(),tmp.end());
    vector<int> rev = tmp;
    reverse(rev.begin(),rev.end());
    if(tmp == rev){
        if( v[0] == (n+1)/2) cout << 2 << "\n";
        else cout << 0 << "\n";
        return;
    }
    int ret = 1;
    if(tmp == v){
        if(v[0] > 2) {
            ret = 0;
        }
        for(int i = 1; i < n; i++){
            if(v[i] > v[i-1]+1){
                ret = 0;
                break;
            }
            if(v[i] == v[i-1] && v[i] != v[n-1]){
                ret = 0;
                break;
            }
        }
        cout << ret << "\n";
        return;
    }
    if(rev == v){
        reverse(v.begin(),v.end());
        if(v[0] > 2) {
            ret = 0;
        }
        for(int i = 1; i < n; i++){
            if(v[i] > v[i-1]+1){
                ret = 0;
                break;
            }
            if(v[i] == v[i-1] && v[i] != v[n-1]){
                ret = 0;
                break;
            }
        }
        cout << ret << "\n";
        return;
    }
    cout << 0 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
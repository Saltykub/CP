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
    string p,s;
    cin >> p >> s;
    vector<int> v1,v2;
    int sm = 1;
    for(int i = 1; i < p.size(); i++){
        if(p[i] == p[i-1]) sm++;
        else {
            v1.pb(sm);
            sm = 1;
        }
    }
    v1.pb(sm);
    sm = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]) sm++;
        else {
            v2.pb(sm);
            sm = 1;
        }
    }
    v2.pb(sm);
    if(v1.size() != v2.size() || s[0] != p[0]){
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < v1.size(); i++){
        if(v1[i] > v2[i] || v1[i]*2 < v2[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
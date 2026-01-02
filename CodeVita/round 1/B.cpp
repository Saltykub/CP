#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    string s,m;
    cin >> s >> m;
    vector<int> v;
    int sz = s.size();
    for(int i = 0; i < sz; i++){
        int val = s[i]-'0';
        if(m[i] == 'S') v.pb(val);
        else {
            if(val == 1 || val == 8 || val == 0) v.pb(val);
            if(val == 2 ){
                v.pb(5);
            }
            if(val == 5){
                v.pb(2);
            }
            if(val == 3){
                if(m[i] == 'U' || m[i] == 'D'){
                    v.pb(3);
                }
            }
        }
    }
    sort(v.begin(),v.end());
    if(v[0] == 0){
        int vsz = v.size();
        for(int i = 0; i < vsz; i++){
            if(v[i] != 0){
                cout << v[i];
                for(int j = 0; j < i; j++){
                    cout << v[j];
                }
                for(int k = i+1; k < vsz; k++){
                    cout << v[k];
                }
                return;
            }
        }
        
    }
    for(auto u:v)cout << u;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vll cnt(26,0);
    for(auto &u:s) cin >> u;
    for(auto u:s){
        for(auto c:u){
            cnt[c-'A']++;
        }
    }
    for(auto u:s){
        vll tmp = cnt;
        vll tmp2 = cnt;
        for(auto c:u) tmp[c-'A']--;
        for(int i = 0; i < 26; i++) tmp[i]*=m;
        ll mn = INT_MAX;
        for(auto c:u) {
            if(tmp[c-'A'] == 0) mn = -1;
            tmp[c-'A']--;
            tmp2[c-'A']--;
        }
       
        for(int i = 0; i < 26; i++){
            if(tmp2[i] == 0) continue;
            if(tmp[i] == 0){
                mn = -1;
            }
            mn = min(tmp[i]/tmp2[i],mn);
        }
        cout << max(-1LL,mn) << " ";
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
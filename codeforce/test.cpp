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
    map<int,set<int>> mp1[11], mp2[11];
    for(int i = 1; i <= 10; i++) mp2[i][0].insert(0);
    vector<int> arr(n+1);
    vector<int> pref(11,0);
    ll ans = n*(n+1)/2;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++){
        for(int j = arr[i]; j <= 10; j++) pref[j]++;
        if(i%2 == 1){
            // using mp1
            set<int> s;
            for(int j = 1; j <= 10; j++){
                ll ch = 2*(pref[j])-i;
                if(!mp1[j][ch].empty()) {
                    for(auto u:mp1[j][ch]){
                        s.insert(u);
                    }
                }
                mp1[j][ch].insert(i);
                // cout << i << " " << j << "\n";
            }
            ans-=s.size();
        }
        else {
            // using map2;
            set<int> s;
            for(int j = 1; j <= 10; j++){
                ll ch = 2*(pref[j])-i;
                if(!mp2[j][ch].empty()) {
                    for(auto u:mp2[j][ch]){
                        s.insert(u);
                    }
                }
                mp2[j][ch].insert(i);
            }
            ans-=s.size();
        }
        cout << ans << "\n";
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
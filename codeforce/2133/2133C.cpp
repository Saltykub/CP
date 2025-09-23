#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int ask(int i,int n){
    cout << "? "<< i << " " << n;
    for(int i = 1; i <= n; i++) {
        cout << " " << i;
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}
int check(int a,int b){
    cout << "? " << a << " " << 2 << " " << a << " " << b << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve (){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        mp[ask(i,n)].pb(i);
    }
    vector<int> ans;
    int from = -1;
    for(int i = n; i >= 1; i--){
        if(!mp[i].empty()){
            if(from == -1){
                ans.pb(mp[i][0]);
                from = mp[i][0];
            }
            else {
                for(auto u:mp[i]){
                    if(check(from,u) == 2){
                        ans.pb(u);
                        from = u;
                        break;
                    }
                }
            }
        }
    }
    cout << "! " << ans.size() << " ";
    for(auto u:ans) cout << u << " ";
    cout << endl; 
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
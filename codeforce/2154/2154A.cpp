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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            bool can = true;
            for(int j = 1; j <= k-1; j++){
                if(i-j < 0) break;
                if(s[i-j] == '1'){
                    can = false;
                    break;
                }
            }
            if(can) ans++;
        }
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
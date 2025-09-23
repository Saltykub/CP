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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
           bool can = true;
           if(i + k - 1 >= n) break;
           int tmp = k;
           while(tmp--){
                if(v[i] == 1) {
                    can = false;
                    break;
                }
                i++;
           }
           if(can) ans++;
           //cout << i;
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
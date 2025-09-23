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
    int n,q;
    cin >> n >> q;
    ll arr[n+1][n+1], dp1[n+1][n+1], dp2[n+1][n+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            arr[i][j] = 0;
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> arr[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            dp1[i][j] += arr[i][j] + dp1[i-1][j] + dp1[i][j-1] - dp1[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp2[i][j] += dp1[i][j]  + dp2[i-1][j] + dp2[i][j-1] - dp2[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp2[x2][y2] - dp2[x1-1][y2] - dp2[x2][y1-1] + dp2[x1-1][y1-1] << " ";
    }
    cout << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i = 0 ; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
    vector<int> mx_col(n*m+1,0);
    pii di[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mx_col[arr[i][j]] = max(mx_col[arr[i][j]],1);
            for(int d = 0; d < 4; d++){
                int ii = i+di[d].st, jj = j+di[d].nd;
                if(ii >= n || jj >= m || ii < 0 || jj < 0) continue;
                if(arr[i][j] == arr[ii][jj]) mx_col[arr[i][j]] = 2;
            }
        }
    }
    ll ans = 0;
    sort(mx_col.begin(),mx_col.end(),greater<int>());
    for(int i = 1; i < mx_col.size(); i++) {
        //cout << mx_col[i] << "\n";
        ans+=mx_col[i];
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
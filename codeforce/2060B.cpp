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
    vector<int> arr[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            arr[i].pb(x);
        }
    }
    for(int i = 0; i < n; i++) sort(arr[i].begin(),arr[i].end());
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int temp = arr[i][0]%n;
        for(auto u:arr[i]) {
            if(u%n != temp){
                cout << -1 << "\n";
                return;
            }
        }
        ans[temp] = i+1;
    }
    for(auto u:ans) cout << u << " ";
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
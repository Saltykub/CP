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
    int n,m,k;
    cin >> n >> m >> k;
    vll h(n), b(m);
    for(auto &u:h) cin >> u;
    for(auto &u:b) cin >> u;
    sort(all(h),greater<ll>());
    sort(all(b),greater<ll>());
    int j = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        while(j < n && h[j] > b[i]){
            j++;
        }
        if(j == n) break;
        cnt++;
        j++;
    }
    if(cnt >= k) cout << "Yes";
    else cout << "No";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
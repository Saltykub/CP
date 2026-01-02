#include<bits/stdc++.h>
#define int long long 
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
    vector<int> v(2*n);
    for(auto &x:v) cin >> x;
    vector<int> ans(n+1,0);
    vector<int> qs1(2*n+1,0), qs2(2*n+1,0);
    qs1[0] = qs1[1] = v[1] - v[0];
    for(int i = 2; i < 2*n; i+=2){
        qs1[i]+=qs1[i-1];
        qs1[i]+=v[i+1] - v[i];
        qs1[i+1] = qs1[i];
    }
    qs2[1] = qs2[2] =v[2] - v[1];
    for(int i = 3; i < 2*n; i+=2){
        qs2[i]+=qs2[i-1];
        qs2[i]+=v[i+1] - v[i];
        qs2[i+1] = qs2[i];
    }
    int cur = 0;
    cout << qs1[2*n-2] << " ";
    for(int i = 2; i <= n; i++){
        int r = 2*n-(i-1), l = i-2;
        cur += v[r] - v[l];
        if(i%2){
            cout << cur + qs1[r-1] - qs1[l];
        }
        else {
            cout << cur + qs2[r-1] - qs2[l];
        }
        cout << " ";
    }
    cout << "\n";
}
signed main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
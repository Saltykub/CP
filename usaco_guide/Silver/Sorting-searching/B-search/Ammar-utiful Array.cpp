#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<ll> arr[N];
ll off[N];
void solve (){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr[c].pb(v[i]);
    }
    for(int i = 0; i < N; i++){
        if(arr[i].empty()) continue;
        for(int j = 1; j < arr[i].size(); j++){
            arr[i][j] += arr[i][j-1];
        }
    }
    int q;
    cin >> q;
    ll q1 = 0;
    while(q--){
        ll op,col,val;
        cin >> op >> col >> val;
        if(op == 1){
            off[col]+=val;
            q1+=val;
        }
        else {
            ll l = 0, r = arr[col].size()-1;
            while(l < r){
                ll mid = (l+r+1)/2;
                if(arr[col][mid]+(q1-off[col])*(mid+1) <= val) l = mid;
                else r = mid-1;
            }
            if(l == 0 && arr[col][0]+q1-off[col] > val) cout << 0 << "\n";
            else cout << l+1 << "\n";
        }
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
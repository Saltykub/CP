#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,o,q;
    cin >> n >> o >> q;
    vector<ll> arr(n+2), qs(o+2), upd(n+2);
    vector<pair<pii,ll>> op(o+2);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= o; i++){
        cin >> op[i].st.st >> op[i].st.nd >> op[i].nd;
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        qs[x]++;
        qs[y+1]--;
    }
    for(int i = 2; i <= o; i++){
        qs[i]+=qs[i-1];
    }
    for(int i = 1; i <= o; i++){
       auto [lr,d] = op[i];
       auto [l,r] = lr;
       upd[l] += d*qs[i];
       upd[r+1] -= d*qs[i];
    }
    for(int i = 2; i <= n; i++) upd[i] += upd[i-1];
    for(int i = 1; i <= n; i++) cout << arr[i]+upd[i] << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}

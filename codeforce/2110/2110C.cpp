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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    bool can = true;
    int cur = 0;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) cur++;
        else if(v[i] == -1){
            if(cur >= q[i].st) {
                v[i] = 0;
                dq.push_back(i);
            }
            else {
                cur++;
                v[i] = 1;
            }
        }
        if(cur < q[i].st) {
           while(!dq.empty()){
                int idx = dq.back();
                dq.pop_back();
                cur++;
                v[idx] = 1;
                if(cur == q[i].st) break;
               
           }
           if(cur != q[i].st) {
                can = false;
                break;
           }
        }
    }
    cur = 0;
    for(int i = 0; i < n; i++){
        //cout << v[i] << " ";
        if(v[i]) cur++;
        if(cur < q[i].st || cur > q[i].nd){
            can = false;
            break;
        }
    }
    if(can) {
        for(auto u:v) cout << u << " ";
        cout << "\n";
    }
    else cout << -1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
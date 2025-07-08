#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int query(int u){
    cout << "? " << 1 << " " << 1 << " " << u << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
    }
    vector<int> v(n+1);
    v[1] = query(1);
    if(v[1] == 1 || v[1] == -1){
        for(int i = 2; i <= n; i++){
            int x = query(i);
            v[i] = x-v[1];
        }
        cout << "! ";
        for(int i = 1; i <= n; i++) cout << v[i] << " ";
        cout << endl;
    }
    for(int i = 2; i <= n; i++){
        int x = query(i);
        v[i] = x-v[1];
    }
    if(root != 1){
        v[1] -= v[root];
    }
    for(int i = 2; i <= n; i++){
        if(i!=root) {
            v[i] -= v[1];
            v[i] -= v[root];
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
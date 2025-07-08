#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(N);
int fp(int x){
    if(p[x] == x) return x;
    return p[x] = fp(p[x]);
}
void merge(int u,int v){
    int pu = fp(u), pv = fp(v);
    if(pu == pv) return;
    p[pu] = pv;
}
void solve (){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) p[i] = i;
    vector<int> arr(n);
    map<int,int> mp;
    for(auto &x:arr) cin >> x;  
    for(int i = 0; i < n; i++){
        mp[arr[i]] = i;
    }
    vector<bool> A(n,false), B(n,false);
    for(int i = 0; i < n; i++){
        if(mp.count(a-arr[i])){
            A[i] = true;
            merge(i,mp[a-arr[i]]);
        }
        if(mp.count(b-arr[i])){
            B[i] = true;
            merge(i,mp[b-arr[i]]);
        }
    }
    vector<int> can(n, 3);
    for(int i = 0; i < n; i++){
        int mask = 0;
        if(A[i]) mask += 1;
        if(B[i]) mask += 2;
        can[fp(i)] &=mask;
    }
    for(int i = 0; i < n; i++){
        if(!can[i]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++){
        if(can[fp(i)] == 1) {
            cout << 0 << " ";
        }
        else {
            cout << 1 << " ";
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
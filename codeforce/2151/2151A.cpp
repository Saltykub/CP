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
    vector<int> v(m);
    for(auto &x:v) cin >> x;
    for(int i = 1; i < m; i++){
        if(v[i] != v[i-1]+1){
            cout << 1 << "\n";
            return;
        }
    }
    cout << n-v[m-1]+1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
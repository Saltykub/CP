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
    int ans = 0;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int ii = -1, jj = -1;
    for(int i = 0; i < n; i++){
        if(v[i] != 0){
            ii = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(v[i] != 0){
            jj = i;
            break;
        }
    }
    if(ii == -1){
        cout << 0 << "\n";
        return;
    }
    for(int i = ii; i <= jj; i++){
        if(v[i] == 0){
            cout << 2 << "\n";
            return;
        }
    }
    cout << 1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
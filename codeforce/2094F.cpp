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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<int> arr(m,0);
    vector<int> v1,v2;
    v2.pb(k);
    for(int i = 1 ; i < k; i++) {
        v1.pb(i);
        v2.pb(i);
    }
    v1.pb(k);
    int idx = 0;
    int v = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            if(idx == 0){
                if(v == 1){
                    if(v1[idx] == arr[j]){
                        v = 2;
                    }
                }
                else{
                    if(v2[idx] == arr[j]){
                        v = 1;
                    }
                }
            }
            if(v == 1){
                cout << v1[idx] << " ";
                arr[j] = v1[idx];
                idx++;
                if(idx == k) idx = 0;
            }
            else {
                cout << v2[idx] << " ";
                arr[j] = v2[idx];
                idx++;
                if(idx == k) {
                    idx = 0;
                    v = 1;
                }
            }
        }
        cout << "\n";
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
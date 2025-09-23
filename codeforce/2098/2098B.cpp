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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &u:v) cin >> u;
    sort(v.begin(),v.end());
    if(n == k){
        cout << 100000000 << "\n";
        return;
    }
    ll mid = (n-k)/2;
    if((n-k)%2) mid++;
    ll mn = v[mid-1];
    ll mx = 0;
    //cout << mid;
    for(int j = n-1; j >= 0; j--){
        mid--;
        if(mid == 0){
            mx = v[j];
            break;
        }
    }
   // cout << mx << " " << mn << "\n";
    cout << (mx-mn)+1 << "\n";
 
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
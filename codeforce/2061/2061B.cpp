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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<double> edge;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    map<ll,ll> mp;
    for(auto u : arr) mp[u]++;
    for(auto u:mp){
        if(u.nd >= 2){
            edge.pb(u.st);
        }
    }
    sort(edge.begin(),edge.end(),greater<int>());
    if(edge.empty()){
        cout << -1 << "\n";
        return;
    }
    double mx = edge[0];
    int cnt = 2;
    vector<double> v;
    for(auto u:arr){
        if(u != mx || cnt <= 0) v.pb(u);
        else cnt--;
    }
    sort(v.begin(),v.end());
    for(int i = 1; i < n-2; i++){
        ll diff = v[i]-v[i-1];
        double d = 1.0*diff/2;
        if(d < mx){
            cout << int(v[i]) << " " << int(v[i-1]) << " " << int(mx) << " " << int(mx) << "\n";
            return;
        }
        
    }
    cout << -1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
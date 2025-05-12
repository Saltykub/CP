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
    string s;
    cin >> n >> s;
    vector<int> arr;
    arr.pb(0);
    for(auto u:s) arr.pb(u-'0');
    map<int,int> mp;
    for(int i = 2; i <= n; i++){
        arr[i]+=arr[i-1];
    };
    ll ans = 0;
    for(int i = n; i >=  0; i--){
        int fn = arr[i]-i+1;
        ans+=mp[fn];
        mp[fn]++;
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
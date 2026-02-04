#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    map<pair<int,int>,int> onetwo, onethree, twothree;
    map<pair<pair<int,int>,int>,int> mp;
    int n;
    ll ans = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n-2; i++){
        onetwo[{arr[i],arr[i+1]}]++;
        onethree[{arr[i],arr[i+2]}]++;
        twothree[{arr[i+1],arr[i+2]}]++;
        mp[{{arr[i],arr[i+1]},arr[i+2]}]++;
    }
    for(int i = 0; i < n-2; i++){
        ans += onetwo[{arr[i],arr[i+1]}] +  onethree[{arr[i],arr[i+2]}] + twothree[{arr[i+1],arr[i+2]}] - 3* mp[{{arr[i],arr[i+1]},arr[i+2]}];
    }
    cout << ans/2 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}
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
    vector<ll> arr;
    map<ll,ll> mp;
    bool can = true;
    for(int i = 0; i < 2*n; i++) {
        ll x;
        cin >> x;
        if(x%2) can = false;
        mp[x]++;
    }
    if(mp.size()!=n || !can) {
        cout << "NO\n";
        return;
    }
    for(auto u:mp){
        if(u.second != 2){
            cout << "NO\n";
            return;
        }
    }
    for(auto u:mp) arr.pb(u.st/2);
    sort(arr.begin(),arr.end(),greater<ll>());
    ll prev = 0, j = n;
    for(int i = 0; i < n; i++){
        //cout << (arr[i]-prev)/j << "\n";
        if((arr[i]-prev)%j || (arr[i]-prev)/j <= 0){
            cout << "NO\n";
            return;
        }

        prev += (arr[i]-prev)/j;
        j--;
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
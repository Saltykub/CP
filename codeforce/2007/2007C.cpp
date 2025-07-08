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
    ll n,a,b;
    cin >> n >> a >> b;
    ll g = gcd(a,b);
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]%=g;
    }
    sort(arr.begin(),arr.end());
    ll mn = arr[n-1]-arr[0];
    for(int i = 1; i < n; i++){
        mn = min(mn,arr[i-1]+g-arr[i]);
    }
    cout << mn << "\n";
    arr.clear();
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }

}
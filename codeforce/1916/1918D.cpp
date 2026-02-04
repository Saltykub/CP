#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool check(ll m,vector<int> arr){
    int sz = arr.size();
    ll sm = 0, cur = 0;
    deque<ll> dq;
    for(int i = 0; i < sz;i ++){
        if(dq.empty()){
            dq.pb(arr[i]);
            
        }

    }
    return true;
}
void solve (){
   int n;
   vector<int>arr(n);
   for(int i = 0;i < n;i++) cin >> arr[i];
   ll l = 1, r = 1e18;
   while(l < r){
    int m = (l+r)/2;
    if(check(m,arr)) r = m;
    else l = m+1;
   }
   cout << l << "\n";
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
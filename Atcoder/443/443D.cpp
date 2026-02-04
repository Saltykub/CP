#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll n,s=0;
    cin >> n;
    vector<ll> r(n);
    for(auto &nx : r){
      cin >> nx;
      s+=nx;
    }
    for(ll i=1;i<n;i++){ r[i]=min(r[i],r[i-1]+1); }
    for(ll i=n-2;i>=0;i--){ r[i]=min(r[i],r[i+1]+1); }
    for(auto &nx : r){ s-=nx; }
    cout << s << "\n";
  }
  return 0;
}

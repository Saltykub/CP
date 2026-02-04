#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define pii pair<ll,ll>
#define pb push_back
using namespace std;
void solve()
{
  ll k,x,a;
  cin >> k >> x >> a;
  ll cur = a;
  ll start = 1;
  for(int i = 1; i <= x; i++){
      start = ceil(1.0*(a-cur)/(k-1));
      if(start*(k-1) + cur <= a)start++;
      cur-=start;
      //cout << cur <<"\n";
      if(cur <= 0){
        cout << "NO\n";
        return;
      }
  }
  if(cur*k <= a) cout << "NO\n";
  else cout <<"YES\n";
}
int main()
{  
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
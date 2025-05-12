#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
     cin >> arr[i];
  }
  int mn = INT_MAX;
  for(int i = 0; i < n-1; i++){
     mn = min(max(arr[i],arr[i+1]),mn);
  }
  cout << mn-1 << "\n";
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

#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
   int n;
   cin >> n;
   int arr[n+1];
   memset(arr,0,sizeof arr);
   for(int i = 0; i < n;i ++){
        int x; cin >> x;
        arr[x]++;
   }
   int ans = 0;
   for(int i = 1; i <= n; i++){
     if(arr[i] < 3)continue;
     ans += arr[i]*(arr[i]-1)*(arr[i]-2)/6;
   }
   cout << ans << "\n";
    
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int ct[5005];
int dp[5005]; //dp[i]=optimal solution that end of i 
void solve()
{  
   for(int i=0;i<=5000;i++){ct[i]=0;dp[i]=0;}
   int n;
   cin>>n;
   int ans=0;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      if(x<=5000)ct[x]++;
   }
   int mx=-1;
   for(int i=0;i<=5000;i++)
   {
    if(ct[i]==0)
    {
        mx=i;
        break;
    }
   }
   if(mx==0)cout<<ans<<"\n";
   else 
   {  dp[0]=mx*(ct[0]-1);
      for(int i=1;i<mx;i++)
      { 
        dp[i]=mx*(ct[i]-1)+i;
        int mn=INT_MAX;
        for(int j=0;j<i;j++)
        {
            mn=min(dp[j]-(mx-i)*(ct[j]-1),mn);
        }
        dp[i]+=mn;
      }
      int ans2=INT_MAX;
      for(int i=0;i<mx;i++)ans2=min(ans2,dp[i]);
      cout<<ans2<<"\n";
   }
   

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
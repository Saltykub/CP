#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
map<int,int> mp;
void solve()
{ 
   int n;
   cin>>n;
   while(n--)
   {
      int x;
      cin>>x;
      int num=x;
      while(x%2==0)
      {
        mp[2]++;
        x/=2;
      }
      for(int i=3;i<=sqrt(num);i+=2)
      {
        while(x%i==0)
        {
         
            mp[i]++;
            x/=i;
        }
      }
      if(x!=1)mp[x]++;
   }

      int less=0;
      int ans=0;
      for(auto u:mp)
      {
        ans+=u.nd/2;
        if(u.nd%2==1)less++;
      }
   ans+=less/3;
   cout<<ans;
   cout<<"\n";
   mp.clear();
}
int main()
{ 
   int t;
   cin>>t;
   while(t--)
   {
     solve();
   }
}
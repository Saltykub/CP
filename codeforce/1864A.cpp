#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int start,end,n;
    cin>>start>>end>>n;
    if(n*(n-1)/2>end-start)
    {
        cout<<-1;
    }
    else 
    {   
        int sum=0;
        vector<int> v;
        v.pb(end);
        for(int i=1;i<n-1;i++)
        {   
            sum+=i;
            v.pb(end-sum);
        }
        v.pb(start);
        reverse(v.begin(),v.end());
        for(auto u:v)cout<<u<<" ";
    }
    cout<<"\n";
   
  
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
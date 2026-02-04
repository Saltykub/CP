#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int start=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {   
       
        if(s[i]=='B'&&start==0)
        {
            ans++;
            i+=k-1;
        }
    }
    cout<<ans<<"\n";
    
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
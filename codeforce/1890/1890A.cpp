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
    cin>>n;
    map<int,int> mp;
    int f=-1,s=-1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(f==-1)f=x;
        if(x!=f)s=x;
        mp[x]++;
    }
    if(mp.size()>=3)cout<<"No";
    else if(mp.size()==1)cout<<"Yes";
    else {
        if(abs(mp[f]-mp[s])<=1)cout<<"Yes";
        else cout<<"No";
    }
    mp.clear();
    cout<<"\n";
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
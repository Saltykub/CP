#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int arr[4];
    int ans=4;
    for(int i=0;i<4;i++){
        arr[i]=s[i]-'0';
        if(arr[i]==0)arr[i]=10;
    }
    ans+=abs(1-arr[0]);
    for(int i=0;i<3;i++){
        ans+=abs(arr[i]-arr[i+1]);
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
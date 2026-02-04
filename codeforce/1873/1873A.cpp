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
    string check="abc";
    int ans=0;
    for(int i=0;i<3;i++)
    {
        if(s[i]==check[i])ans++;
    }
    if(ans==1||s==check)cout<<"yes";
    else cout<<"no";
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
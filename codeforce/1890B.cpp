#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    bool oo=false,zz=false,cs=true,ct=true;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cs=false;
            if(s[i]=='0')zz=true;
            if(s[i]=='1')oo=true;
        }
    }
    for(int i=0;i<m-1;i++){
        if(t[i]==t[i+1]){
            ct=false;
            break;
        }
    }
    if(cs)cout<<"Yes";
    else {
        if(ct){

            if(zz&&oo)cout<<"No";
            else if(zz&&t[0]=='1'&&t[m-1]=='1')cout<<"Yes";
            else if(oo&&t[0]=='0'&&t[m-1]=='0')cout<<"Yes";
            else cout<<"No";
        }
        else cout<<"No";
        
    }
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
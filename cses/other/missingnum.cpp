#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
ll findd[N];
int main()
{
    ll n,ans=0;
    cin>>n;
    cin>>findd[0];
    for(int i=1;i<n;i++)
    {
        cin>>findd[i];
        if(findd[i]<findd[i-1]){ans+=findd[i-1]-findd[i];findd[i]=findd[i-1];}
    }
    cout<<ans;
}

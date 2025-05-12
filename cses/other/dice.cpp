#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+10;
const int mod=1e9+7;
int dp[N]; //dp[i] = the way to create i number
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=6;i++)
    {
        dp[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>0)
            {
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[n];
}
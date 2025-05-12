#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int precom[1005];
void solve()
{
   int n;
   cin>>n;    
   ll ans=1;
   while(n){
     ans*=precom[n%10];
     n/=10;
   }
   cout<<ans<<"\n";
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    //t=1;
    for(int a=0;a<=9;a++){
        for(int b=0;b<=9;b++){
            for(int c=0;c<=9;c++){
                precom[a+b+c]++;
            }
        }
    }
    while(t--)
    {
        solve();
    }
}

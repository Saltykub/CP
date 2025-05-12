#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int prime[10]={2,3,5,7,11,13,17,19,23,29};
bool use[10];
void solve()
{
   int n;
   cin>>n;
   for(int i=0;i<10;i++)use[i]=false;
   pii arr[n];
   for(int i=0;i<n;i++){cin>>arr[i].st;arr[i].nd=i+1;}
   sort(arr,arr+n);
   ll ans=0;
   for(int i=0;i<n;i++)
   { 
    int ct=0;
     for(int j=0;j<10;j++)
     {  
        if(use[j])continue;
        if(2)
     }
   }
   
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
#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
map<ll,pii>mp;
void solve()
{ 
   int n;
   cin>>n;
   ll arr[n];
   int plus[35],minus[35];
   for(int i=0;i<35;i++)plus[i]=minus[i]=0;
   ll sm=0;
   for(int i=0;i<n;i++){cin>>arr[i];sm+=arr[i];}
   if(sm%n!=0){cout<<"No"<<"\n";}
   else 
   {
    sm/=n;
    int free=0;
    bool can=true;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>sm)
        {   
            if(mp[arr[i]-sm].nd!=0)
            {
                int a=mp[arr[i]-sm].st,b=mp[arr[i]-sm].nd;
                plus[a]++;
                minus[b]++;
            }
            else{can=false;break;}
        }
        else if(arr[i]<sm){
            if(mp[sm-arr[i]].nd!=0)
            {   
                
                int a=mp[sm-arr[i]].st,b=mp[sm-arr[i]].nd;
                plus[b]++;
                minus[a]++;
            }
            else {can=false;break;}
        }
        else free++;
    }
    if(can==false){cout<<"No"<<"\n";return;}
    for(int i=0;i<35;i++)
    {
       if(plus[i]!=minus[i]){can=false;break;}
    }
    if(can)cout<<"Yes";
    else cout<<"No";
    cout<<"\n";
   }
}
int main()
{   
    for(int i=0;i<=32;i++)
    {
    for(int j=i+1;j<=32;j++)
    {
        ll x=abs(pow(2,i)-pow(2,j));
        mp[x]={i,j};
    }
    }
    int t;
    cin>>t;
    while(t--)
    {   
        solve();
    }
}
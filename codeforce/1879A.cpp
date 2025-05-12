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
   int arr[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   if(n%2==0)
   {
    cout<<2<<"\n";
    cout<<1<<" "<<n<<"\n";
    cout<<1<<" "<<n<<"\n";
   }
   else 
   {
    cout<<4<<"\n";
    cout<<1<<" "<<n-1<<"\n";
    cout<<1<<" "<<n-1<<"\n";
    cout<<2<<" "<<n<<"\n";
    cout<<2<<" "<<n<<"\n";
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
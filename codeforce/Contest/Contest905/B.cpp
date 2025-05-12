#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{
   int n,k;
   cin>>n>>k;
   //cout<<n<<k;
   string s;
   cin>>s;
   int arr[27];
   for(int i=0;i<27;i++)arr[i]=0;
   for(int i=0;i<n;i++){
      int idx=s[i]-'a';
     // cout<< idx;
      arr[idx]++;
   }
   int odd=0;
   for(int i=0;i<27;i++)if(arr[i]%2==1)odd++;

   if(odd==0){cout<<"YES"<<"\n";}
   else if(odd==1){cout<<"YES"<<"\n";return;}
   else if(odd>1){
       if(k>=odd)cout<<"YES"<<"\n";
       else if(odd-k==1)cout<<"YES"<<"\n";
       else cout<<"NO"<<"\n";}
   else {cout<<"NO"<<"\n";}
   
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
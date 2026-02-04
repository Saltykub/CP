#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool comp (pii x, pii y){
   int mx = max(x.st,x.nd);
   int my = max(y.st,y.nd);
   return mx < my;
}
void solve (){
   int n;
   cin >> n;
   pii a[n+1];
   for(int i = 0;i < n;i++)cin >> a[i].st;
   for(int i=0;i<n;i++) cin >> a[i].nd;
   sort(a,a+n,comp);
   for(int i=0;i<n;i++){
     cout<< a[i].st <<" ";
   }
   cout<<"\n";
   for(int i=0;i<n;i++){
    cout<<a[i].nd <<" ";
   }
   cout<<"\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}
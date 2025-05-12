#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e6+7;
void solve()
{  
    int n;
    cin>>n;
    int arr[n];
    int ans=0,ans2=0;
    int observe=0,observe2=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[i-1])ans++;
        if(arr[i]>=arr[i-1])ans2++;
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])observe++;
        else break;
    }
    reverse(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1])observe2++;
        else break;
    }
    if(observe)observe--;
    cout<<min(ans-observe,ans2+1-observe2)<<"\n";
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
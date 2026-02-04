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
    int arr[n],mn=INT_MAX,mx=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mn=min(mn,arr[i]);
        mx=max(mx,arr[i]);
    }
    if(n==1){cout<<0<<"\n";return;}
    // check can 
    bool can=true,l=false,r=false;
    int startl=-1,startr=-1;
    if(arr[0]==mn&&arr[1]==mx){l=true;startl=0;}
    if(arr[0]==mn&&arr[n-1]==mx){r=true;startr=0;}
    if(arr[n-1]==mn&&arr[0]==mx){l=true;startl=n-1;}
    if(arr[n-1]==mn&&arr[n-2]==mx){r=true;startr=n-1;}
    for(int i=1;i<n-1;i++){
        if(arr[i]==mn&&arr[i+1]==mx){l=true;startl=i;}
        if(arr[i]==mn&&arr[i-1]==mx){r=true;startr=i;}
    }
    if(l){
        //cout<<1;
        for(int i=startl;i>0;i--){
            if(arr[i]>arr[i-1])can=false;
        }
        for(int i=n-1;i>startl+1;i--){
           // cout<<arr[i]<<" ";
            if(arr[i]>arr[i-1])can=false;
        }
        if(arr[0]>arr[n-1]&&n-1!=startl)can=false;
    }
    if(r){
        for(int i=startr;i<n-1;i++){
            if(arr[i]>arr[i+1])can=false;
        }
        for(int i=0;i<startr-1;i++){
            if(arr[i]>arr[i+1])can=false;
        }
        if(arr[n-1]<arr[0])can=false;
    }
    cout<<startr<<"\n";
    if(!can||startl==-1&&startr==-1)cout<<-1;
    else {
        int ans=INT_MAX;
        if(l){
            ans=min(startl+1,n-startl-1)+1;
        }
        if(r){
            ans=min(ans,99);
        }
        cout<<ans;
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

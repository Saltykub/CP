#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=3e5+3;
const int mod=998244353;
pii seg[4*N];
pii combine(pii a,pii b){
    if(a.st<b.st)return a;
    return b;
}
void build(int idx,int tl,int tr,ll arr[]){
    if(tl==tr){seg[idx].st=arr[tl];seg[idx].nd=tl; return;}
    int mid=(tl+tr)/2;
    build(2*idx,tl,mid,arr);
    build(2*idx+1,mid+1,tr,arr);
    seg[idx]=combine(seg[2*idx],seg[2*idx+1]);
}
pii query(int idx,int tl,int tr,int l,int r){
    if(tl>r || tr<l ) {
        pii ret={INT_MAX,INT_MAX};
        return ret;
    }
    if(tl>=l && tr<=r) return seg[idx];
    int mid=(tl+tr)/2;
    return combine(query(2*idx,tl,mid,l,r),query(2*idx+1,mid+1,tr,l,r));
}
ll cal(ll arr[],int l,int r,int n){
    int ret=1;
    if(l==r)return 1;
    int pos = query(1,1,n,l,r).nd;
    //cout<<l<<" "<<r<<" "<<pos<<"\n";
    if(pos>l){
        ret*=(cal(arr,l,pos-1,n)+1);
        ret%=mod;
    }
    if(pos<r){
        ret*=(cal(arr,pos+1,r,n)+1);
        ret%=mod;
    }
    return ret;
}
void solve()
{
    int n;
    cin>>n;
    ll arr[n+2];
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n,arr);
    cout<<cal(arr,1,n,n)<<"\n";
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
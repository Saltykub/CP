#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int h[N];
struct d{
    ll sum,pref;
};
d init(int val){
    d res;
    res.sum=val,res.pref=max(0,val);
    return res;
}
d combine(d a,d b){
    d res;
    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    return res;
}
d t[4*N];
void build(int idx,int tl,int tr){
    if(tl==tr){ t[idx] = init(h[tl]);return;}
    int mid = (tl + tr)/2;
    build(2*idx, tl, mid);
    build(2*idx+1, mid + 1, tr);
    t[idx]=combine(t[2*idx],t[2*idx+1]);
}
void update(int idx,int tl,int tr,int pos,int val){
    if(pos > tr || pos < tl)return; 
    if(tl == tr){ t[idx] = init(val);return;}
    int mid = (tl + tr)/2;
    update(2*idx,tl,mid,pos,val);
    update(2*idx+1,mid+1,tr,pos,val);
    t[idx] = combine(t[2*idx],t[2*idx+1]);
}
d query(int idx,int tl,int tr,int l,int r){
    if(l > tr || r < tl) return init(0);
    if(tl >= l && tr <= r)return t[idx];
    int mid = (tl + tr)/2;
    return combine(query(2*idx,tl,mid,l,r),query(2*idx+1,mid+1,tr,l,r));
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>h[i];
    build(1,1,n);
    while(q--){
        int order,a,b;
        cin>>order>>a>>b;
        if(order == 1)update(1,1,n,a,b);
        else cout<<query(1,1,n,a,b).pref<<"\n"; 
    }
    
}
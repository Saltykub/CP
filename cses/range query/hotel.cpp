#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int stree[4*N],h[N];
void build(int idx,int tl,int tr){
    if(tl==tr){stree[idx]=h[tl];return;}
    int mid=(tl+tr)/2;
    build(2*idx,tl,mid);
    build(2*idx+1,mid+1,tr);
    stree[idx]=max(stree[2*idx],stree[2*idx+1]);
}
void add(int idx,int tl,int tr,int val,int pos){
    if(pos<tl||pos>tr)return;
    if(tl==tr){stree[idx]-=val;return;}
    int mid=(tl+tr)/2;
    add(2*idx,tl,mid,val,pos);
    add(2*idx+1,mid+1,tr,val,pos);
    stree[idx]=max(stree[2*idx],stree[2*idx+1]);
}
int query(int idx,int tl,int tr,int val){
    //f(tl>r||tr<l)return -1;
    if(stree[idx]<val)return -1;
    if(tl==tr)return tl;
    int mid=(tl+tr)/2;
    int left=query(2*idx,tl,mid,val);
    if(left!=-1)return left;
    else return query(2*idx+1,mid+1,tr,val);
    
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>h[i];
    build(1,1,n);
    while(q--){
        int x;
        cin>>x;
        int f=query(1,1,n,x);
        if(f==-1)cout<<0<<" ";
        else {
            cout<<f<<" ";
            add(1,1,n,x,f);
        }
    }
    
}
#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
ll arr[N], t[4*N], lz[4*N], c[4*N];
ll cal(ll tl,ll tr,ll suml,int cnt){
    return (cnt*(tr*tr - tl*tl + 3*tr-tl+2)+(-2*suml+2*(tl-tr)*suml))/2;
}
void push(int idx,int tl,int tr){
    if(!lz[idx]) return;
    t[idx] += cal(tl,tr,lz[idx],c[idx]);
    if(tl != tr){
       lz[2*idx] += lz[idx];
       lz[2*idx + 1] += lz[idx];
       c[2*idx]+=c[idx]; c[2*idx + 1]+=c[idx];
    }
    lz[idx] = 0;c[idx] = 0;
}
void b(int idx, int tl,int tr){
    if(tl == tr){ t[idx] = arr[tl]; return;}
    int m = (tl + tr)/2;
    b(2*idx, tl , m);
    b(2*idx + 1, m + 1, tr);
    t[idx] = t[2*idx + 1] + t[2*idx];
}
void u(int idx,int tl,int tr,int l,int r){
    push(idx, tl ,tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r ){
        lz[idx] +=l;
        c[idx] ++;
        push(idx,tl,tr);
        return;
    }
    int m =(tl + tr)/2;
    u(2*idx,tl,m,l,r);
    u(2*idx + 1,m + 1,tr,l,r);
    t[idx] = t[2*idx] + t[2*idx + 1];
}
ll qr(int idx,int tl,int tr,int l,int r){
    if(tl > r || tr < l)return 0;
    push(idx ,tl, tr);
    if(tl >= l && tr <= r)return t[idx];
    int m = (tl + tr)/2;
    return qr(2*idx, tl, m, l, r)+qr(2*idx + 1,m+1,tr, l, r);
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i=1; i<=n ;i++)cin >> arr[i];
    b(1,1,n);
    while(q--){
        int o, l, r;
        cin >> o >> l >> r;
        if(o == 1){
           u(1,1,n,l,r);
        }
        else if (o == 2){
           cout<<qr(1,1,n,l,r)<<"\n";
        }
    }
    
}
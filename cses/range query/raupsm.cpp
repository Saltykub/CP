#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
ll arr[N], t[4*N], lz[4*N], lz2[4*N];
void push(int idx,int tl,int tr){
    //if(!lz[idx] && !lz2[idx])return;
    if(lz2[idx]){
        t[idx] = (tr - tl + 1)*lz2[idx];
        //cout << idx << t[idx] <<" ";
        if(tl != tr){
           // cout << idx << " " << lz2[idx] <<"\n";
            lz2[2*idx] = lz2[idx];
            lz2[2*idx +1 ] = lz2[idx];
            lz[2*idx] = lz[idx];
            lz[2*idx + 1] = lz[idx];
        }
    }
    t[idx] += (tr - tl + 1)*lz[idx];
    if(tl != tr && !lz2[idx] ){
        lz[2*idx]+=lz[idx];
        lz[2*idx + 1]+=lz[idx];
    }
    lz[idx] = 0;
    lz2[idx] = 0;
}
void b(int idx,int tl,int tr){
    if(tl == tr){ t[idx] = arr[tl]; return;}
    int m = (tl + tr)/2;
    b(2*idx, tl, m);
    b(2*idx + 1, m + 1, tr);
    t[idx] = t[2*idx] + t[2*idx + 1];
}
void u(int idx,int tl,int tr,int l,int r,int val){
    push(idx, tl, tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r){
        lz[idx] += val;
        push(idx, tl, tr);
        return;
    }
    int m = (tl + tr)/2;
    u(2*idx, tl, m, l, r, val);
    u(2*idx + 1, m + 1, tr, l, r, val);
    t[idx] = t[2*idx] + t[2*idx + 1];
}
void z(int idx,int tl,int tr,int l,int r,int val){
    push(idx ,tl, tr);
    if(tl > r || tr < l) return;
    if(tl >= l && tr <= r){
       lz2[idx] = val;
       lz[idx] = 0;
       push(idx ,tl , tr);
       return;
    }
    int m = (tl + tr)/2;
    z(2*idx, tl, m, l, r, val);
    z(2*idx + 1, m + 1, tr, l, r, val);
    t[idx] = t[2*idx] + t[2*idx + 1];
}
ll qr(int idx,int tl,int tr,int l,int r){
    if(tl > r || tr < l) return 0;
    push(idx, tl, tr);
    if(tl >= l && tr <= r) return t[idx];
    int m = (tl + tr)/2;
    return qr(2*idx, tl, m, l, r) + qr(2*idx+1, m + 1, tr, l, r);
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
           int x; cin >> x;
            u(1,1,n,l,r,x);
        }
        else if (o == 2){
           int x; cin >> x;
           z(1,1,n,l,r,x);
        }
        else {
            cout<<qr(1,1,n,l,r)<<"\n";   
        }
        // for(int i=1 ;i <= 9;i++) cout << t[i] <<" ";
        // cout<<endl;
    }
    
}
#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int t1[4*N], t2[4*N], arr[N];
void b1(int idx,int tl,int tr){
    if(tl==tr){t1[idx]=arr[tl]-tl; return;}
    int m = (tl + tr)/2;
    b1(2*idx,tl,m);
    b1(2*idx+1,m+1,tr);
    t1[idx] = min(t1[2*idx],t1[2*idx+1]);
}
void b2(int idx,int tl,int tr){
    if(tl==tr){t2[idx]=arr[tl]+tl; return;}
    int m = (tl + tr)/2;
    b2(2*idx,tl,m);
    b2(2*idx+1,m+1,tr);
    t2[idx] = min(t2[2*idx],t2[2*idx+1]);
}
void a(int idx,int tl,int tr,int pos,int val){
    if(tl > pos || tr < pos)return;
    if(tl == tr) {
        t1[idx] += val;
        t2[idx] += val;
        return;
    }
    int m = (tl + tr)/2;
    a(2*idx,tl,m,pos,val);
    a(2*idx+1,m+1,tr,pos,val);
    t1[idx] = min(t1[2*idx],t1[2*idx+1]); 
    t2[idx] = min(t2[2*idx],t2[2*idx+1]);
}
int q1(int idx,int tl,int tr,int l,int r){
    if(tl > r || tr < l) return INT_MAX;
    if(tl >= l && tr <= r) return t1[idx];
    int m = (tl + tr)/2;
    return min(q1(2*idx,tl,m,l,r),q1(2*idx+1,m+1,tr,l,r));
}
int q2(int idx,int tl,int tr,int l,int r){
    if(tl > r || tr < l) return INT_MAX;
    if(tl >= l && tr <= r) return t2[idx];
    int m = (tl + tr)/2;
    return min(q2(2*idx,tl,m,l,r),q2(2*idx+1,m+1,tr,l,r));
}
int main(){
    int n,q;
    cin >> n >> q;
    for(int i=1; i<=n ;i++)cin >> arr[i];
    b1(1,1,n); b2(1,1,n);
    while(q--){
        int o;
        cin >> o;
        if(o == 1){
            int pos,val;
            cin >> pos >> val;
            a(1,1,n,pos,-arr[pos]);
            a(1,1,n,pos,val);
            arr[pos]=val;
        }
        else {
            int k;
            cin >> k;
            cout << min(q1(1,1,n,1,k)+k,q2(1,1,n,k+1,n)-k)<<"\n";
        }
    }
}
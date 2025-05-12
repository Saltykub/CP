#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+3;
int seg[4*N], arr[N], seg2[4*N];
void build(int idx,int tl,int tr){
    if(tl == tr){seg[idx] = arr[tl]; return;}
    int m = (tl+tr)/2;
    //cout << tl << " " << tr << endl;
    build(2*idx,tl,m);
    build(2*idx+1,m+1,tr);
    seg[idx] = max(seg[2*idx], seg[2*idx + 1]);
}
int query(int idx,int tl,int tr,int l, int r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r ) return seg[idx];
    int m = (tl + tr)/2;
    return max(query(2*idx,tl,m,l,r), query(2*idx+1,m+1,tr,l,r));
}
void build2(int idx,int tl,int tr){
    if(tl == tr){seg2[idx] = arr[tl]; return;}
    int m = (tl+tr)/2;
    build2(2*idx,tl,m);
    build2(2*idx+1,m+1,tr);
    seg2[idx] = min(seg2[2*idx], seg2[2*idx + 1]);
}
int query2(int idx,int tl,int tr,int l, int r){
    if(tl > r || tr < l) return INT_MAX;
    if(tl >= l && tr <= r ) return seg2[idx];
    int m = (tl + tr)/2;
    return min(query2(2*idx,tl,m,l,r), query2(2*idx+1,m+1,tr,l,r));
}
void solve (){
     int n,k;
     cin >> n >> k;
     for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[x] = i;     
    } 
   // for(int i = 1; i <= n; i++) cout << arr[i];
    build(1,1,n);
    build2(1,1,n);
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(i+k-1 > n) break;
       // cout << i << " " << query(1,1,n,i,i+k-1) - query2(1,1,n,i,i+k-1) << endl;
        ans = min(query(1,1,n,i,i+k-1) - query2(1,1,n,i,i+k-1),ans);
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
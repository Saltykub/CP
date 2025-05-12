#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
vector<int> fw(N,0);
void add(int val,int po){
    for(int i = po; i < N; i+=(i&-i)){
        fw[i]+=val;
    }
}
int query(int po){
    int ret = 0;
    for(int i = po; i > 0; i -= (i&-i)){
        ret += fw[i];
    }
    return ret;
}
void rst(int po){
    for(int i = po; i < N; i+=(i&-i)){
        fw[i] = 0;
    }
}
void solve (){
   int n;
   cin >> n;
   map<int,int> idx;
   set<int> s;
   vector<int> a(n), b(n);
   vector<pii> arr(n);
   for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
   for(int i = 0; i < n; i++){
       arr[i].st = b[i];
       arr[i].nd = a[i];
   }
    int ans = 0;
    for(auto x:a) s.insert(x);
    int cnt = 2;
    for(auto u:s){
        idx[u] = cnt;
        cnt++;
    }
   sort(arr.begin(),arr.end());
   for(auto u:arr){
       ans += query(cnt) - query(idx[u.second] - 1);
       int aa = 1;
       add(aa,idx[u.second]);
   }
   cout << ans << "\n";
   for(int i = 2; i < cnt; i++) rst(i);
}
signed main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {   
        solve();
    }

}
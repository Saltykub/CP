#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N=2e5+5;
int arr[N],ans[N];
vector<pii> v[N];
int fw[N];
map<int,int> mp;
void add(int i,int val){
    for(;i<N;i+=(i&-i))fw[i] += val;
}
int qs(int i){
    int ret=0;
    for(;i>0;i-=(i&-i))ret += fw[i];
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin >> arr[i];
    for(int i=1;i<=q;i++){
        int l,r;
        cin >> l >> r;
        v[l].pb({r,i});
    }
    for(int i=n;i>0;i--){
        int val = arr[i];
        if(mp[val])add(mp[val],-1);
        mp[val]=i;
        add(mp[val],1);
        for(auto u:v[i]){
            ans[u.nd]=qs(u.st);
        }
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";

   
    
}
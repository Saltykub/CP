#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll n,m;
    cin >> n >> m;
    vector<int> arr(n),used(n,0);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push({arr[i],i});
    }
    while(!pq.empty()){
        auto[val,idx] = pq.top();
        pq.pop();
        if(used[idx]) continue;
        used[idx] = 1;
        if(idx-1 >= 0) {
            if(arr[idx] > arr[idx-1] && arr[idx] - arr[idx-1] > m){
                arr[idx-1] = arr[idx]-m;
                pq.push({arr[idx-1],idx-1});
            }
        }
        if(idx + 1 < n){
             if(arr[idx] > arr[idx+1] && arr[idx] - arr[idx+1] > m){
                arr[idx+1] = arr[idx]-m;
                pq.push({arr[idx+1],idx+1});
            }
        }
    }
    for(auto u:arr) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,m;
    cin >> n >> m;
    vector<int> v(n),arr(n);
    int point = 0;
    for(int i = 0; i < n; i++) v[i] = i+1;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    set<int> use;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push({arr[i],i});
    }
    ll mx = 0, mxidx = 0;
    while(!pq.empty()){
        auto [val,idx] = pq.top();
        if(m-val >= 0){
            pq.pop();
            point ++;
            m-=val;
            v[idx]--;
            use.insert(idx+1);
            mx = val;
            mxidx = idx;
        }
        else break;
    }
    if(use.find(point+1) == use.end()){
        if(m+mx-arr[point] >= 0){
            v[mxidx]++;
            v[point]--;
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur++;
        if(v[i] <= point){
            cout << cur<< "\n";
            return;
        } 
    }
    cout << n+1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
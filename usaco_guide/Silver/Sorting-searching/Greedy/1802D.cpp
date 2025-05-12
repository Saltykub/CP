#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll cal(vector<pii> v){
    int n = v.size();
    sort(v.begin(),v.end());
    vector<ll> mx(n,0);
    mx[n-1] = v[n-1].nd;
    for(int i = n-2; i >= 0; i--){
        mx[i] = max(mx[i+1],v[i].nd);
    }
    set<ll> s;
    ll ret = INT_MAX;
    for(int i = 0; i < n; i++){
        ll a = v[i].st,b = -1;
        auto lb = s.lower_bound(v[i].st);
        if(lb!=s.end()){
            b = *lb;
        }
        if(lb!=s.begin()){
            ll bb = *prev(lb);
            if(abs(a-b) > abs(a-bb)) b = bb;
        }
        if(i+1 < n && mx[i+1] > b) b = mx[i+1];
        if(i+1 < n) ret = min(ret,abs(a-mx[i+1]));
        ret = min(abs(a-b),ret);
        s.insert(v[i].nd);
    }
    return ret;
}
void solve (){
    ll n,ans1,ans2;
    cin >> n;
    vector<pii> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i].st >> arr[i].nd; 
    ans1 = cal(arr);
    for(int i = 0; i < n; i++) swap(arr[i].st,arr[i].nd);
    ans2 = cal(arr);
    cout << min(ans1,ans2) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
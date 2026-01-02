#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define tp tuple<int,int,int,int>
using namespace std;
const int N = 2e6+10;
const int OFFSET = 1e6;
bool CASE = false;
ll fw[N];
void add(int i, int val){
    for(; i < N; i+=(i&-i)){
        fw[i] += val;
    }
}
ll qs(int i){
    ll ret = 0;
    for(;i; i-=(i&-i)){
        ret += fw[i];
    }
    return ret;
}
void solve (){
    int n;
    cin >> n;
    vector<tp> v;
    for(int i = 0; i < n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // horizontal line
        if(y1 == y2){
           v.pb({y1,2,x1,x2});
        }
        else {
           v.pb({y1,1,x1,1});
           v.pb({y2,3,x1,1});
        }
    }
    sort(all(v));
    ll ret = 0;
    for(auto [y,op,x1,x2]:v){
        y += OFFSET;
        x1 += OFFSET;
        x2 += OFFSET;
        if(op == 1){
            add(x1,1);
        }
        else if(op == 2){
            ret += qs(x2) - qs(x1-1);
        }
        else {
            add(x1,-1);
        }
    }
    cout << ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
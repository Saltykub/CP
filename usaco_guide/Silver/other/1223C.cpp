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
    int n;
    cin >> n;
    vector<ll> arr(n+1),qs(n+1,0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i]/=100;
    }
    int x,y,a,b, cntx = 0, cnty = 0, cntxy = 0;
    cin >> x >> a >> y >> b;
    ll k;
    cin >> k;
    // y will >= x;
    if(x > y) {
        swap(x,y);
        swap(a,b);
    }
    sort(arr.begin()+1,arr.end(),greater<int>());
    for(int i = 1; i <= n; i++){
        qs[i] = qs[i-1]+arr[i];
    }
    for(int i = 1; i <= n; i++){
        if(i%a == 0 && i%b == 0) cntxy ++;
        else if(i%b == 0) cnty ++;
        else if(i%a == 0) cntx ++;
        ll cur = qs[cntxy]*(x+y) + (qs[cntxy+cnty]-qs[cntxy])*y + (qs[cntxy+cnty+cntx]-qs[cntxy+cnty])*x;
        if(cur >= k){
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n"; return;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
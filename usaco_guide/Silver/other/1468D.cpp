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
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector<int> arr(m);
    for(int i = 0; i < m; i++) cin >> arr[i];
    ll mx_t = 0, mx_ans = abs(b-a)-1;
    if(a < b){
        mx_t = (b-a) + a -1;
    }
    else {
        mx_t = (a-b) + n-a;
    }
    sort(arr.begin(),arr.end(),[&](int a, int b){
        return a > b;
    });
    ll cnt = 1, ans = 0;
    for(int i = 0; i < m; i++){
        if(cnt+arr[i] <= mx_t){
            cnt++;
            ans++;
        }
    }
    cout << min(mx_ans,ans) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
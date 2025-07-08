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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0, prev = 0, mx = 0;
    sort(a.begin(),a.end());
    for(int i = 0; i < n; i++){
        if(a[i] != prev){
            mx = max(cnt,mx);
            prev = a[i];
            cnt = 1;
        }
        else cnt ++;
    }
    mx = max(mx,cnt);
    cout << n-mx << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
    int n,k;
    cin >> n >> k;
    int mn = INT_MAX, mx = 0;
    vector<int> a(n),b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;  
    int have = -1;   
    for(int i = 0; i < n; i++){
       // cout << have;
        if(b[i] != -1){
            if(have != -1 && a[i]+b[i] != have){
                cout << 0 << "\n";
                return;
            }
            have = a[i] + b[i];
        }
    }
    if(have != -1){
        for(int i = 0; i < n; i++){
            if(b[i] == -1){
                if(a[i] > have || a[i]+k < have){
                    cout << 0 << "\n";
                    return;
                }
            }
        }
        cout << 1 << "\n";
    }
    else {
        sort(a.begin(),a.end());
        int mx = a[n-1], mn = a[0];
        cout << max(0,mn+k-mx+1) << "\n";
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
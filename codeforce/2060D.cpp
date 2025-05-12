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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool can = true;
    for(int i = 1; i < n; i++){
        int mn = min(arr[i],arr[i-1]);
        arr[i]-=mn;
        arr[i-1]-=mn;
    }
    for(int i = 1; i < n ; i++){
        if(arr[i] < arr[i-1]) can = false;
    }
    if(can) cout << "YES\n";
    else cout << "NO\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
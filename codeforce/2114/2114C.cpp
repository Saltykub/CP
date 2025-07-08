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
    for(auto &x:arr) cin >> x;
    int sm = 1;
    int cur = arr[0];
    for(int i = 1; i < n; i++){
        if(cur+1 >= arr[i]) continue;
        cur = arr[i];
        sm++;
    }
    cout << sm << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
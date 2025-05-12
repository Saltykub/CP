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
    int n;
    cin >> n;
    vector<int> arr(n),lgcd(n),rgcd(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    lgcd[0] = arr[0];
    for(int i = 1; i < n; i++){
        lgcd[i] = __gcd(arr[i],lgcd[i-1]);
    }
    rgcd[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        rgcd[i] = __gcd(arr[i],rgcd[i+1]);
    }
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        ans = max(__gcd(lgcd[i-1],rgcd[i+1]),ans);
    }
    ans = max({ans,rgcd[1],lgcd[n-2]});
    cout << ans;
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
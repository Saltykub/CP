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
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0) arr[i]*=-1;
    }
    int med = arr[0];
    sort(arr.begin(),arr.end());
    bool can = false;
    if(arr[n/2] >= med) can = true;
    for(int i = 0; i < n; i++) arr[i]*=-1;
    sort(arr.begin(),arr.end());
    if(arr[n/2] <= -med) can = true;
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
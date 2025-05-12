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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n,0);
    int minus = -1e9;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans;
    bool done = true;
    ll sm = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 1){
            if(arr[i] >= 0) sm += arr[i];
            else {
            
            }
        }
        else {

        }
        if(sm > k)
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
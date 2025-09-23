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
    vector<int> v(n);
    ll sm = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sm += v[i];
    }
    sort(v.begin(),v.end());
    if(v[n-1]-1-v[0] > k || (v[n-2] == v[n-1] && v[n-2]-v[0] > k)){
        cout << "Jerry\n";
    }
    else {
        if(sm%2){
            cout << "Tom\n";
        }
        else cout << "Jerry\n";
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
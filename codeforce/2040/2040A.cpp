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
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    for(int i = 0; i < n; i++){
        bool can = true;
        for(int j = 0; j < n ;j++){
            if(j != i && abs(a[i]-a[j])%k == 0) can = false;
        }
        if(can) {
            cout << "Yes\n";
            cout << i+1 << "\n";
            return;
        }
    }
    cout << "No\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
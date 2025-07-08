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
    vector<int> d(n-1);
    for(auto &u:d) cin >> u;
    for(int i = 0; i < n-1; i++){
        int cnt = 0;
        for(int j = i; j < n-1; j++){
            //cout << j << " ";
            cnt += d[j];
            cout << cnt << " ";
        }
        cout << "\n";
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
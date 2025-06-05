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
    int n,s;
    cin >> n >> s;
    vector<int> t(n);
    for(auto &x:t) cin >> x;
    if(t[0] > s) {
        cout << "No";
        return;
    }
    for(int i = 1; i < n; i++){
        if(t[i] - t[i-1] > s){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
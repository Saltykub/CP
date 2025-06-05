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
    int n,m;
    cin >> n >> m;
    vector<int> r(m);
    for(auto &x:r) cin >> x;
    sort(r.begin(),r.end());
    int j = 0;
    for(int i = 0; i < n; i+=2){
        for(int k = 0; k < 6; k++){
            if(k%2) cout << r[j] << " ";
            else cout << r[m-j-1] << " ";
        }
        cout << "\n";
        if(i == n-1) break;
        for(int k = 0; k < 6; k++){
            if(k%2 == 0) cout << r[j] << " ";
            else cout << r[m-j-1] << " ";
        }
        j++;
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
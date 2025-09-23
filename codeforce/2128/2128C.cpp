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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int f = 0, val = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] <= val){
            for(int j = f; j < i; j++){
                if(v[j] > val+val-1){
                    cout << "No\n";
                    return;
                }
            }
            f = i;
            val = v[i];
        }
    }
    for(int j = f; j < n; j++){
        if(v[j] > val+val-1){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
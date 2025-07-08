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
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool pass = true;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) pass = false;
    }
    if(pass) {
        cout << "YES\n";
        return;
    }
    if(arr[0] == arr[1] && arr[0] == 0) {
        cout << "YES\n";
    }
    else {
        for(int i = 1; i < n-1; i++){
            if(arr[i] == 0 && arr[i+1] == 0) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
        return;
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
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
    vector<int> arr(n-2);
    for(int i = 0; i < n-2; i++) cin >> arr[i];
    for(int i = 0; i < n-4; i++){
        if(arr[i] == 1 && arr[i+1] == 0 && arr[i+2] == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
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
    string s;
    cin >> s;
    int q;
    cin >> q;
    ll a0 = 0, a1 = 0;
    vector<int> qs1(n+1,0), qs0(n+1,0);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') qs0[i+1] = arr[i];
        else qs1[i+1] = arr[i];
    }
    for(int i = 1; i <= n; i++){
        qs1[i]^=qs1[i-1];
        qs0[i]^=qs0[i-1];
    }
    a1 = qs1[n];
    a0 = qs0[n];
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int l,r;
            cin >> l >> r;
            a1^=qs1[l-1]^qs1[r]^qs0[l-1]^qs0[r];
            a0^=qs1[l-1]^qs1[r]^qs0[l-1]^qs0[r];
        }
        else {
            int g;
            cin >> g;
            if(g == 0) cout << a0;
            else cout << a1;
            cout << " ";
        }
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
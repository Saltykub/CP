#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int l = 1, r = 1e9;
    auto ask = [&](int x){
        cout << "? " << x << endl;
        string ret;
        cin >> ret;
        if(ret == "NO") return 0;
        else return 1;
    };
    while(l<r){
        int mid = (l+r)/2;
        if(ask(mid)){
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
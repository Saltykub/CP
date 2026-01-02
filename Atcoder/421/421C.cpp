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
    int n;
    string s;
    cin >> n >> s;
    int idx = 1;
    long long mn1 = 0, mn2 = 0;
    for(int i = 0; i < 2*n; i++){
        if(s[i] == 'B'){
            mn1 += abs(i-idx);
            idx += 2;
        }
    }
    idx = 1;
    for(int i = 0; i < 2*n; i++){
        if(s[i] == 'A'){
            mn2 += abs(i-idx);
            idx += 2;
        }
    }
    cout << min(mn1,mn2);
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
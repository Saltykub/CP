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
bool CASE = true;
void solve (){
    string s;
    cin >> s;
    int cnt = 0;
    if(s[0] == 'u'){
        s[0] = 's';
        cnt++;
    }
    if(s[sz(s)-1] == 'u'){
        s[sz(s)-1] = 's';
        cnt++;
    }
    for(int i = 1; i < sz(s)-1; i++){
        if(s[i] == 'u' && s[i+1] != 's'){
            s[i+1] = 's';
            cnt++;
        }
    }
    cout << cnt << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
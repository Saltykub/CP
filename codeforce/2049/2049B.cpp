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
    string s;
    cin >> n >> s;
    bool c = false;
    for(int i = 1; i < n; i++){
        if(s[i] == 's'){
            c = true;
        }
    }
    if(!c) cout << "Yes\n";
    else {
        for(int i = 0; i < n-1; i++){
            if(s[i] == 'p'){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
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
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
    string s;
    cin >> s;
    if(s[n-1] == 'B'){
        for(int i = 0; i < n-1; i++) {
            if(s[i] == 'B'){
                cout << "Bob\n";
                return;
            }
        }
        cout << "Alice\n";
    }
    else {
        if(s[n-2] == 'A' || s[0] == 'A') cout << "Alice\n";
        else cout << "Bob\n";
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
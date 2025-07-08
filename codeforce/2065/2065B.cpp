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
    string s;
    cin >> s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            cout << 1 << "\n";
            return;
        }
    }
    cout << s.size() << "\n";   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    if(s.size() < 3) cout << "No\n";
    else if(s[0] == 'a' && s[1] == 'e' && s[2] == 't'){
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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
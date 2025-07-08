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
    int cnt = 0;
    bool can = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') cnt ++;
        else cnt--;
        if(cnt == 0 && i!= s.size()-1) can = true;
    }
    if(can) cout << "YES\n";
    else cout <<"NO\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
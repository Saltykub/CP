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
    string s,t;
    cin >> s >> t;
    for(int i = 0; i <= s.size()-t.size(); i++){
        if(s[i] == t[0] || s[i] == '?'){
            bool can = true;
            int idx = i;
            for(int j = 0; j < t.size(); j++,idx++){
                if(s[idx] == '?') continue;
                if(s[idx] != t[j]) can = false;
            }
            if(can){
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}
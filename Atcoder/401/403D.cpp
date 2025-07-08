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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o') k--;
        if(s[i] == '?' && i-1 >= 0 && s[i-1] == 'o') s[i] = '.';
        if(s[i] == '?' && i+1 < n && s[i+1] == 'o') s[i] = '.';
    }
    if(k == 0){
        for(int i = 0; i < n; i++) if(s[i] == '?') s[i] = '.';
        cout << s;
    }
    else {
        int mx = 0;
        int cur = 0;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(s[i] == '?') cur++;
            else{
                if(cur != 0){
                    v.pb(cur);
                    cur = 0;
                }
            }
        }
        if(s[n-1] == '?') v.pb(cur);
        for(auto u:v) mx+=(u+1)/2;
        if(mx == k){
            int j = -1;
            cur = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '?'){
                    if(cur == 0){
                        j = i;
                    }
                    cur++;
                }
                else {
                    if(cur != 0 && cur%2){
                        char c = 'o';
                        for(int k = j; k < i; k++){
                            s[k] = c;
                            if(c == 'o') c = '.';
                            else c = 'o';
                        }
                    }
                    cur = 0;
                }
            }
            if(s[n-1] == '?'){
                if(cur%2){
                    char c = 'o';
                    for(int k = j; k < n; k++){
                        s[k] = c;
                        if(c == 'o') c = '.';
                        else c = 'o';
                    }
                }
            }
            cout << s;
        }
        else {
            cout << s;
        }
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
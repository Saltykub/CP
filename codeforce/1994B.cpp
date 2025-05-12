#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    if(s[0] == '0' && t[0] == '1') cout << "no" << "\n";
    else {
        if(s[0] == '0' && t[0] == '0'){
            if(s == t) cout << "yes\n";
            else {
                int idx = -1;
                for(int i = 0; i < n; i++){
                    if(s[i] == '1') {
                        idx = i;
                        break;
                    }
                }
                if( idx == -1) cout << "no\n";
                else {
                    for(int i = 0; i < idx; i++){
                        if(t[i] == '1') {
                            cout << "no\n";
                            return;
                        }
                    }
                    cout << "yes\n";
                }
            }
            
        }
        else cout << "yes\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}
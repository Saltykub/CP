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
    int n,k;
    cin >> n >> k;
    int tmp = k;
    string s;
    cin >> s;
    int ii = 0;
    int jj = n-1;
    while(ii <= jj){
        if(s[ii] == '1') s[ii] = '0', k--;
        if(k == 0) break;
        if(s[jj] == '1') s[jj] = '0', k--;
        if(k == 0) break;
        ii++;
        jj--;
    }
    int l = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') l++;
        else break;
    }
    for(int i =  n-1; i >= 0; i--){
        if(s[i] == '0') r++;
        else break;
    }
    int mid = n-l-r;
    if(l+mid <= tmp && r+mid <= tmp){
        cout << "Alice\n";
    }
    else {
        if(n < 2*tmp){
            cout << "Alice\n";
        }
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
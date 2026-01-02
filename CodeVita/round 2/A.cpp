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
const int N = 2500;
bool CASE = false;
int dp[N][N];
char tab[N][N];
void solve (){
    int n;
    cin >> n;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) tab[i][j] = '1';
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) tab[i][j] = s[j];
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j] = INT_MAX;
    for(int i = 0; i < N; i++){
        if(tab[0][i] == '0'){
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < pow(2,i+2); j++){
            if(tab[i][j] == '0'){
                if(tab[i-1][])
            }
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
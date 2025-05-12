#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    unordered_map<char,int> mp;
    int n; string s;
    cin >> n >> s;
    for(auto c:s) {
        mp[c]++;
    }
    int N = mp['N'], E = mp['E'], W = mp['W'], S = mp['S'];
    if(N > S){
        N -= S;
        if(N % 2) {cout << "NO\n"; return;}
        int cnt = N/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'N') {
                cnt --;
                s[i] = 'H';
            }
        }
        cnt = N/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'N') {
                cnt --;
                s[i] = 'R';
            }
        }
        int ofsw = 0, ofse = 0;
        for(int i = 0; i < n; i++){
           if(!ofsw && s[i] == 'N'){
                s[i] = 'R';
                ofsw++;
           }
           if(!ofse && s[i] == 'S'){
                s[i] = 'R';
                ofse++;
           } 
           if(ofsw && s[i] == 'N'){
                s[i] = 'H';
                ofsw++;
           }
           if(ofse && s[i] == 'S'){
                s[i] = 'H';
                ofse++;
           }         
        }
    }
    else {
         S -= N;
        if(S % 2) {cout << "NO\n"; return;}
        int cnt = S/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'S') {
                cnt --;
                s[i] = 'H';
            }
        }
        cnt = S/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'S') {
                cnt --;
                s[i] = 'R';
            }
        }
        int ofsw = 0, ofse = 0;
        for(int i = 0; i < n; i++){
           if(!ofsw && s[i] == 'N'){
                s[i] = 'R';
                ofsw++;
           }
           if(!ofse && s[i] == 'S'){
                s[i] = 'R';
                ofse++;
           } 
           if(ofsw && s[i] == 'N'){
                s[i] = 'H';
                ofsw++;
           }
           if(ofse && s[i] == 'S'){
                s[i] = 'H';
                ofse++;
           }         
        }
    }
      if(W > E){
        W -= E;
        if(W % 2) {cout << "NO\n"; return;}
        int cnt = W/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'W') {
                cnt --;
                s[i] = 'R';
            }
        }
        cnt = W/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'W') {
                cnt --;
                s[i] = 'H';
            }
        }
        int ofsw = 0, ofse = 0;
        for(int i = 0; i < n; i++){
           if(!ofsw && s[i] == 'W'){
                s[i] = 'H';
                ofsw++;
           }
           if(!ofse && s[i] == 'E'){
                s[i] = 'H';
                ofse++;
           } 
           if(ofsw && s[i] == 'W'){
                s[i] = 'R';
                ofsw++;
           }
           if(ofse && s[i] == 'E'){
                s[i] = 'R';
                ofse++;
           }         
        }
    }
    else {
         E -= W;
        if(E % 2) {cout << "NO\n"; return;}
        int cnt = E/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'E') {
                cnt --;
                s[i] = 'R';
            }
        }
        cnt = E/2;
        for(int i = 0; i < n; i++){
            if(!cnt) break;
            if(s[i] == 'E') {
                cnt --;
                s[i] = 'H';
            }
        }
        int ofsw = 0, ofse = 0;
        for(int i = 0; i < n; i++){
           if(!ofsw && s[i] == 'W'){
           
                s[i] = 'H';
                ofsw++;
           }
           if(!ofse && s[i] == 'E'){
                s[i] = 'H';
                ofse++;
           } 
           if(ofsw && s[i] == 'W'){
                s[i] = 'R';
                ofsw++;
           }
           if(ofse && s[i] == 'E'){
                s[i] = 'R';
                ofse++;
           }         
        }
    }
    int canH = false, canR = false;
    for(auto u:s){
        if(u == 'R') canR = true;
        if(u == 'H') canH = true;
    }
    if(canR && canH) cout << s;
    else cout << "NO";
    cout << "\n";
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
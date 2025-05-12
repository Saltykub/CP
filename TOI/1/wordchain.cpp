#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,n;
    cin >> l >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    string ans = "";
    for(int i = 1; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < l;j++){
            if(s[i][j] != s[i-1][j])cnt++;
        }
        if(cnt > 2) {
            cout << s[i-1];
            return 0;
        }
    }
    cout << s[n-1];
}
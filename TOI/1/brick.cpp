#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    char tab[n][m];
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> tab[i][j];
    int brick[m];
    for(int i = 0; i < m; i++) cin >> brick[i];
    for(int i = 0; i < m; i++){
        bool can = false;
        for(int j = 0; j < n; j++){
            if(tab[j][i] == 'O'){
                int cnt = j-1;
                while(cnt >= 0 && brick[i]){
                    tab[cnt][i] = '#';
                    brick[i]--;
                    cnt--;
                }
                can = true;
                break;
            }
        }
        int cnt = n-1;
        if(!can){
            while(cnt >= 0 && brick[i]){
                tab[cnt][i] = '#';
                brick[i]--;
                cnt--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << tab[i][j];
        }
        cout << "\n";
    }
}
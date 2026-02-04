#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int h, w, xa, ya, xb, yb;
   cin >> h >> w >> xa >> ya >> xb >> yb;
   int wa = abs(w-ya), wb = abs(w-yb);
   if(xa >= xb) cout <<"Draw";
   else {
     if(abs(xa-xb)%2){
        if(yb > ya){
            int fb = min((abs(xa-xb))/2 + yb,w);
            int fa = min((abs(xa-xb))/2 + ya,w);
            if(fa+1 >= fb )cout << "Alice";
            else cout<<"Draw";
        }
        else {
            int fb = max(yb - (abs(xa-xb))/2 ,1);
            int fa = max(ya - (abs(xa-xb))/2 ,1);
            if(fa-1 <= fb )cout << "Alice";
            else cout<<"Draw";
        }
     }
     else {
        if(yb < ya){
            int fb = min((abs(xa-xb)+1)/2 + yb,w);
            int fa = min((abs(xa-xb)+1)/2 + ya,w);
            if(fb >= fa )cout << "Bob";
            else cout<<"Draw";
        }
        else {
            int fb = max(yb - (abs(xa-xb)+1)/2 ,1);
            int fa = max(ya - (abs(xa-xb)+1)/2 ,1);
            if(fb <= fa )cout << "Bob";
            else cout<<"Draw";
        }
     }
   }
   cout<<"\n";
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
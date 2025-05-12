#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll l = 1, r = n*n;
    ll check = ceil(1.0*n*n/2);
    while(l<r){
       // cout << l << " " << r << "\n";
        ll m = (l+r+1)/2;
        ll lb = 0, ub = 0;
        for(ll i = 1; i <= n;i++){
            if(m < i*i) break;
            if(m == i*i) ub++;
            else if(m % i == 0 && m/i <= n) ub += 2; 
            lb += 2*(min(m/i,n)-i+1)-1;
        }
        //cout << "lb = " << ub << "\n";
        if(lb > check && lb-ub < check) {
            cout << m;
            return 0;
        }
        if((lb > check && lb-ub >= check) || (lb == check && ub == 0)) r = m-1;
        else l = m;

    }
    cout << l;
}

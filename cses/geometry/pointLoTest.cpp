#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        double x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double m=(y1-y2)/(x1-x2);
        double c=y1-m*(x1);
        if(y3==x3*m+c)cout<<"TOUCH";
        else if((m>=0&&y3>x3*m+c)||(m<0&&y3<x3*m+c))cout<<"LEFT";
        else cout<<"RIGHT";
        cout<<"\n";
    }
}
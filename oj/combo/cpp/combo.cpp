#include "combo.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
string guess_sequence(int N) {
    string first;
    // find first string
    int coin = press("AB");
    if(coin == 0) {
      coin = press("X");
      if(coin==1)first = "X";
      else first ="Y";
    }
    else {
      coin = press("A");
      if(coin==1)first = "A";
      else first ="B";
    }
    vector<string> v;
    if(first!="A")v.pb("A");
    if(first!="B")v.pb("B");
    if(first!="X")v.pb("X");
    if(first!="Y")v.pb("Y");
    // find string
    for(int i=1;i<N-1;i++){
       string s="";
       s+=first+v[0];
       s+=first+v[1]+v[0];
       s+=first+v[1]+v[1];
       s+=first+v[1]+v[2];
       coin = press(s);
       if(coin == i+1)first+=v[0];
       else if(coin == i+2)first+=v[1];
       else first+=v[2];
    }
    if(N==1)return first;
    string s="";
    s+=first+v[0];
    s+=first+v[1];
    coin = press(s);
    if(coin!=N)return first+v[2];
    s="";
    s+=first+v[0];
    coin = press(s);
    if(coin!=N)return first+v[1];
    else return first+v[0];
}

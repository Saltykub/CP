#include "molecules.h"
#include<bits/stdc++.h>
#include "grader.cpp"
using namespace std;
vector<int> find_subset(int l, int u, vector<int> w) {
    vector<int> ans,blank;
    long long sm = 0;
    if(sm <= u && sm >= l) return ans;
    for(int i = 0 ; i< w.size(); i++){
        sm += w[i];
        ans.push_back(i);
        if(sm <= u && sm >= l) return ans;
    }
    return blank;  
}

#include <bits/stdc++.h>
using namespace std;
int main() {
	int I, V, X, L, C;
	I = V = X = L = C = 0;
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		C += i / 100;
		C += i % 100 >= 90;
		L += (i % 100 >= 40 && i % 100 < 90);
		X += (i % 50 / 10) * (i % 50 < 40) + (i % 50 >= 40) + (i % 10 == 9);
		V += (i % 10 >= 4) && (i % 10 != 9);
		I += (i % 5) * (i % 5 < 4) + (i % 5 == 4);
	}
	cout << I << " " <<  V  << " " << X  << " " << L << " " << C;
}
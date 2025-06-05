#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int count_magic(int m, int d, string bound, bool ok) {
	if (bound.length() == 1) {
		int num_good = 0;
		int cur_digit = bound[0] - '0';
		for (int i = 0; i < cur_digit; i++) { num_good += (i != d) && (i % m == 0); }

		if (ok && cur_digit != d && cur_digit % m == 0) { num_good++; }

		return num_good;
	}

	vector<int> digits;
	for (int i = 0; i < bound.length(); i++) { digits.push_back(bound[i] - '0'); }

	// dp[i][j] = # of ways, if cur is equiv to i, and j = free or not
	vector<array<int, 2>> dp(m);
	for (int i = 1; i <= digits[0]; i++) {
		if (i == d) { continue; }
		dp[i % m][(i < digits[0])]++;
	}

	for (int i = 1; i < digits.size(); i++) {
		const int cur = digits[i];
		vector<array<int, 2>> next_dp(m);
		for (int j = 0; j < m; j++) {
			if (i % 2 == 1) {
				// we force this digit to be D
				int nxt = (10 * j + d) % m;
				(next_dp[nxt][1] += dp[j][1]) %= MOD;
				if (cur > d) {
					(next_dp[nxt][1] += dp[j][0]) %= MOD;
				} else if (cur == d) {
					(next_dp[nxt][0] += dp[j][0]) %= MOD;
				}
			} else {
				// we just need to make sure next digit isn't D
				for (int dig = 0; dig <= 9; dig++) {
					if (dig == d) { continue; }
					int nxt = (10 * j + dig) % m;
					(next_dp[nxt][1] += dp[j][1]) %= MOD;
					if (dig < cur) {
						(next_dp[nxt][1] += dp[j][0]) %= MOD;
					} else if (dig == cur) {
						(next_dp[nxt][0] += dp[j][0]) %= MOD;
					}
				}
			}
            cout << dp[i][j] << " ";
		}
        cout << "\n";
		dp = move(next_dp);
	}

	return (dp[0][1] + dp[0][0] * ok) % MOD;
}

int main() {
	int m, d;
	cin >> m >> d;

	string a, b;
	cin >> a >> b;
    cout << count_magic(m,d,b,true);
	//cout << (count_magic(m, d, b, true) - count_magic(m, d, a, false) + MOD) % MOD
	    // << endl;
}
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

vector<int> move_result(const vector<int> &to_move) {
	cout << "next ";
	for (int i = 0; i < to_move.size() - 1; i++) { cout << to_move[i] << ' '; }
	cout << to_move.back() << endl;

	int group_num;
	std::cin >> group_num;
	vector<int> groups(10);
	for (int g = 0; g < group_num; g++) {
		std::string group;
		std::cin >> group;
		for (char i : group) { groups[i - '0'] = g; }
	}
	return groups;
}

int main() {
	move_result({0, 1});
	vector<int> groups = move_result({1});
	while (groups[0] != groups[1]) {
		move_result({0, 1});
		groups = move_result({1});
	}

	while (groups[2] != groups[1]) {
		groups = move_result({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}

	cout << "done" << endl;
}
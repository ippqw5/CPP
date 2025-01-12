#include <iostream>
#include <map>
using namespace std;

void print(const map<string, int>& m) {
	for (auto& x : m) {
		cout << x.first << ": " << x.second << endl;
	}
	cout << endl;
}

int main() {
	map<string, int> m = { {"a",1}, {"b",2}};
	print(m);

	// 红黑树，有序，增删改查 O(logn) //

	// 增 和 删
	cout << "insert" << endl;
	m.insert(make_pair("c", 3));
	m.insert({"c", 4}); // 不会覆盖
	print(m);
	m.insert_or_assign("c", 4); // 会覆盖
	print(m);

	cout << "erase" << endl;
	m.erase("c");
	print(m);

	// 改 和 查
	cout << "modify" << endl;
	cout << "m['d']=" << m["d"] << "。d不存在，会插入一个默认值" << endl; // 如果不存在，会插入一个默认值
	cout << "m.count('e')=" << m.count("e") << endl; // 0

	// 清空
	cout << "clear" << endl;
	m.clear();
	print(m);

	// 初始化写法
	cout << "init" << endl;
	map<string, int> m2 = { {"a",1}, {"b",2} };
	print(m2);
	print({ {"a",1}, {"b",2} });

	return 0;
}
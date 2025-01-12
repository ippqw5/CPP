#include <iostream>
#include <unordered_map>

using namespace std;
void print(const unordered_map<string, int>& m) {
	for (auto& x : m) {
		cout << x.first << ": " << x.second << endl;
	}
	cout << endl;
}


struct MyKey {
	int id;
	std::string name;
};
struct HashFunction {
	std::size_t operator()(const MyKey& k) const {
		return std::hash<int>()(k.id) ^ std::hash<std::string>()(k.name);
	}
};
struct KeyEqual {
	bool operator()(const MyKey& lhs, const MyKey& rhs) const {
		return lhs.id == rhs.id && lhs.name == rhs.name;
	}
};

void print(const unordered_map<MyKey, int, HashFunction, KeyEqual>& m) {
	for (auto& x : m) {
		cout << "(" << x.first.id << "," << x.first.name << ")" << ": " << x.second << endl;
	}
	cout << endl;
}


int main() {
	// hash_map {key : value}
	// 无序，不会排序
	// 速度快
	unordered_map<string, int> m = { {"a",1}, {"b",2} };

	// 增删改查 O(1)

	// 增 和 删	
	m.insert({"c", 3});
	cout << "insert: (c, 3)" << endl; print(m);
	m.insert({ "c", 4 }); // 不会覆盖
	cout << "insert: (c, 4)" << endl; print(m);
	m.insert_or_assign("c", 4); // 会覆盖
	cout << "insert_or_assign: (c, 4)" << endl; print(m);

	m.erase("c");
	cout << "erase: c" << endl; print(m);

	// 改 和 查
	cout << "modify" << endl;
	cout << "m['d']=" << m["d"] << "。d不存在，会插入一个默认值" << endl; // 如果不存在，会插入一个默认值
	print(m);

	cout << "m.count('e')=" << m.count("e") << endl; // e不存在，返回0
	print(m);

	// 如果key是自定义类型，需要自定义hash函数
	std::unordered_map<MyKey, int, HashFunction, KeyEqual> um;
	um.insert({ {1, "a"}, 1 });
	um.insert({ {2, "b"}, 2 });
	cout << "自定义类型key的unordered_map" << endl;
	print(um);
}
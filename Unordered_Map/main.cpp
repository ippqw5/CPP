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
	// ���򣬲�������
	// �ٶȿ�
	unordered_map<string, int> m = { {"a",1}, {"b",2} };

	// ��ɾ�Ĳ� O(1)

	// �� �� ɾ	
	m.insert({"c", 3});
	cout << "insert: (c, 3)" << endl; print(m);
	m.insert({ "c", 4 }); // ���Ḳ��
	cout << "insert: (c, 4)" << endl; print(m);
	m.insert_or_assign("c", 4); // �Ḳ��
	cout << "insert_or_assign: (c, 4)" << endl; print(m);

	m.erase("c");
	cout << "erase: c" << endl; print(m);

	// �� �� ��
	cout << "modify" << endl;
	cout << "m['d']=" << m["d"] << "��d�����ڣ������һ��Ĭ��ֵ" << endl; // ��������ڣ������һ��Ĭ��ֵ
	print(m);

	cout << "m.count('e')=" << m.count("e") << endl; // e�����ڣ�����0
	print(m);

	// ���key���Զ������ͣ���Ҫ�Զ���hash����
	std::unordered_map<MyKey, int, HashFunction, KeyEqual> um;
	um.insert({ {1, "a"}, 1 });
	um.insert({ {2, "b"}, 2 });
	cout << "�Զ�������key��unordered_map" << endl;
	print(um);
}
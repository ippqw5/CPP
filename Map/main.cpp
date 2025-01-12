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

	// �������������ɾ�Ĳ� O(logn) //

	// �� �� ɾ
	cout << "insert" << endl;
	m.insert(make_pair("c", 3));
	m.insert({"c", 4}); // ���Ḳ��
	print(m);
	m.insert_or_assign("c", 4); // �Ḳ��
	print(m);

	cout << "erase" << endl;
	m.erase("c");
	print(m);

	// �� �� ��
	cout << "modify" << endl;
	cout << "m['d']=" << m["d"] << "��d�����ڣ������һ��Ĭ��ֵ" << endl; // ��������ڣ������һ��Ĭ��ֵ
	cout << "m.count('e')=" << m.count("e") << endl; // 0

	// ���
	cout << "clear" << endl;
	m.clear();
	print(m);

	// ��ʼ��д��
	cout << "init" << endl;
	map<string, int> m2 = { {"a",1}, {"b",2} };
	print(m2);
	print({ {"a",1}, {"b",2} });

	return 0;
}
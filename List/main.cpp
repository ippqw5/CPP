#include <list>
#include <iostream>

using namespace std;
void print(const list<int>& l) {
	for (auto& x : l) {
		cout << x << " ";
	}
	cout << endl << endl;
}
int main() {
	// list，双向链表
	// 适用于频繁插入删除，而不是遍历查找

	list<int> l = { 1,2,3,4,5 };

	// 增
	cout << "l.push_back(6)" << endl;
	l.push_back(6);
	print(l);

	cout << "l.push_front(0)" << endl;
	l.push_front(0);
	print(l);

	cout << "l.insert(l.begin(), -1)" << endl;
	l.insert(l.begin(), -1);
	print(l);

	cout << "l.insert(l.end(), 7)" << endl;
	l.insert(l.end(), 7);
	print(l);

	// 删

	cout << "l.pop_back()" << endl;
	l.pop_back();
	print(l);

	cout << "l.pop_front()" << endl;
	l.pop_front();
	print(l);

	cout << "l.erase(++l.begin())" << endl;
	l.erase(++l.begin());
	print(l);

	cout << "l.erase(--l.end())" << endl;
	l.erase(--l.end());
	print(l);

	// 专用成员函数 sort, reverse, merge
	cout << "l.sort()" << endl;
	l.sort();
	print(l);

	list<int> l2 = { 8,9,10 };
	cout << "l2 = {8,9,10}" << endl;
	cout << "合并两个有序链表 l.merge(l2)" << endl;
	l.merge(l2); 
	print(l);

	cout << "l.reverse()" << endl;
	l.reverse();
	print(l);

	list<int> l3 = { 11, 12 };
	cout << "l3 = {11, 12}" << endl;
	cout << "l.merge(l3)" << endl;
	cout << "error, sequence not ordered" << endl;
	//l.merge(l3); // error, sequence not ordered


}
#include <iostream>
#include <deque>

using namespace std;
int main()
{
	// deque : double-ended queue
	// 两头 插入删除 O(1)
	deque<int> d = { 1, 2, 3, 4, 5 };
	cout << "init d = {1, 2, 3, 4, 5}" << endl;

	// insert
	cout << "d.push_back(6)" << endl;
	d.push_back(6);
	for (auto& x : d) {
		cout << x << " ";
	}
	cout << endl;

	cout << "d.push_front(0)" << endl;
	d.push_front(0);
	for (auto& x : d) {
		cout << x << " ";
	}
	cout << endl;

	// delete
	cout << "d.pop_back()" << endl;
	d.pop_back();
	for (auto& x : d) {
		cout << x << " ";
	}
	cout << endl;

	cout << "d.pop_front()" << endl;
	d.pop_front();
	for (auto& x : d) {
		cout << x << " ";
	}
	cout << endl;

	// access
	cout << "d.front() = " << d.front() << endl;
	cout << "d.back() = " << d.back() << endl;
	cout << "deque支持随机访问，实现是分段连续的内存块，而不是vector的单一连续块" << endl;
	cout << "d[2] = " << d[2] << endl;

	// size
	cout << "d.size() = " << d.size() << endl;

}
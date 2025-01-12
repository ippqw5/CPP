#include <iostream>
#include <deque>

using namespace std;
int main()
{
	// deque : double-ended queue
	// ��ͷ ����ɾ�� O(1)
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
	cout << "deque֧��������ʣ�ʵ���Ƿֶ��������ڴ�飬������vector�ĵ�һ������" << endl;
	cout << "d[2] = " << d[2] << endl;

	// size
	cout << "d.size() = " << d.size() << endl;

}
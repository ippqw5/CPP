#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	v.resize(10);
	cout << "after resize(10)" << endl;
	cout << "v.size() = " << v.size() << endl; // 10
	cout << "v.capacity() = " << v.capacity() << endl << endl; // 10

	v.clear();
	v.reserve(10);
	cout << "after clear and reserve(10)" << endl;
	cout << "v.size() = " << v.size() << endl; // 0
	cout << "v.capacity() = " << v.capacity() << endl << endl; // 10
}
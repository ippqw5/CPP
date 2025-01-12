#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx;
int sum = 0;
void example() {
	//std::lock_guard<std::mutex> lock(mtx); 构造函数中调用 mtx.lock()
	for (int i = 0; i < 100000; i++) {
		sum++;
	}
}  // 作用域结束，析构函数中调用 mtx.unlock()

void example1() {
	std::unique_lock<std::mutex> lock(mtx); // 构造函数中调用 mtx.lock()
	lock.unlock(); //可以手动解锁 
	
	// 还可以转移锁，lock2拥有mtx的所有权，lock不再拥有mtx的所有权
	// 转移会保持mtx的上锁状态
	std::unique_lock<std::mutex> lock2 = std::move(lock); 
	lock2.lock(); // 重新上锁
	for (int i = 0; i < 100000; i++) {
		sum++;
	}
}  // 作用域结束，析构函数中调用 mtx.unlock()

int main()
{	
	for (int i = 0; i < 10; i++) {
		sum = 0;
		std::thread t1(example1); // t1开始执行example1
		std::thread t2(example1); // t2开始执行example1
		t1.join(); // 等待t1执行完
		t2.join(); // 等待t2执行完
		std::cout << sum << std::endl;
	}

	return 0;
}
#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx;
int sum = 0;
void example() {
	//std::lock_guard<std::mutex> lock(mtx); ���캯���е��� mtx.lock()
	for (int i = 0; i < 100000; i++) {
		sum++;
	}
}  // ��������������������е��� mtx.unlock()

void example1() {
	std::unique_lock<std::mutex> lock(mtx); // ���캯���е��� mtx.lock()
	lock.unlock(); //�����ֶ����� 
	
	// ������ת������lock2ӵ��mtx������Ȩ��lock����ӵ��mtx������Ȩ
	// ת�ƻᱣ��mtx������״̬
	std::unique_lock<std::mutex> lock2 = std::move(lock); 
	lock2.lock(); // ��������
	for (int i = 0; i < 100000; i++) {
		sum++;
	}
}  // ��������������������е��� mtx.unlock()

int main()
{	
	for (int i = 0; i < 10; i++) {
		sum = 0;
		std::thread t1(example1); // t1��ʼִ��example1
		std::thread t2(example1); // t2��ʼִ��example1
		t1.join(); // �ȴ�t1ִ����
		t2.join(); // �ȴ�t2ִ����
		std::cout << sum << std::endl;
	}

	return 0;
}
// struct bind

#include <iostream>
#include <map>
#include <string>
using namespace std;

struct MyStruct {
	int i = 0;
	std::string s = "hhh";
};


int main() {
	{
		MyStruct ms;
		auto [i, s] = ms; // C++17
		i = 1; s += "h";
		std::cout << ms.i << " " << ms.s << std::endl;
		std::cout << i << " " << s << std::endl;
	}
	std::cout << std::endl;
	{
		MyStruct ms;
		auto& [i, s] = ms; // C++17
		i = 1; s += "h";
		std::cout << ms.i << " " << ms.s << std::endl;
		std::cout << i << " " << s << std::endl;
	}
	std::cout << std::endl;
	{
		std::map<int, std::string> mymap = { {1, "el"}, {3, "tom"}, {4, "nic"} };
		for (auto& [key, value] : mymap) {
			std::cout << key << " " << value << std::endl;
		}
		/*
		for (const auto& elem : mymap) {
		  std::cout << elem.first << ": "  << elem.second << std::endl;
		}
		*/
	}
}
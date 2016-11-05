#include <string>
#include <iostream>
#include <windows.h>
#include <process.h>
#include <math.h>
#include <map>
#include <algorithm>

int RandomTime() {
	return rand() % 1000;
}

unsigned __stdcall func1(void *pArguments) {
	for (int i{ 0 }; i < 10; ++i) {
		std::cout << "A text string func 1" << std::endl;
		std::cout.flush();
		Sleep(RandomTime());
	}
	_endthreadex(0);
	return 0;
}

unsigned __stdcall func2(void *pArguments) {
	for (int i{ 0 }; i < 10; ++i) {
		std::cout << "A text string func 2" << std::endl;
		std::cout.flush();
		Sleep(RandomTime());
	}
	_endthreadex(0);
	return 0;
}

typedef std::pair<unsigned, HANDLE> my_pair;

void add_thread(std::map<unsigned, HANDLE> &pool, unsigned(__stdcall*func)(void*)) {
	unsigned threadID;
	pool[threadID] = (HANDLE)_beginthreadex(NULL, 0, func, NULL, 0, &threadID);
}

void wait(std::map<unsigned, HANDLE> &pool) {
	for (std::map<unsigned, HANDLE>::iterator it = pool.begin(); it != pool.end(); ++it) {
		WaitForSingleObject(it->second, INFINITE);
		CloseHandle(it->second);
	}
}

int main() {

	std::map<unsigned, HANDLE> pool;

	add_thread(pool, &func1);
	add_thread(pool, &func2);

	for (int i{ 0 }; i < 10; ++i) {
		std::cout << "Another text string 123456789" << std::endl;
		std::cout.flags();
		Sleep(RandomTime());
	}

	wait(pool);

	char c;
	std::cin >> c;

	return 0;
}

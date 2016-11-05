#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class Display {

public:

	Display() : n_(0)
	{}

	void operator()(const std::string& str) {
		std::cout << str << std::endl;
		n_++;
	}

	void showCount() {
		std::cout << "The count is " << n_ << std::endl;
	}

private:

	int n_;
};

class FunctorBase {

public:

	virtual float operator()(float x, float y) = 0;

};

class AddFunctor : public FunctorBase {

public:

	virtual float operator()(float x, float y) {
		return x + y;
	}

};

class SubtractFunctor : public FunctorBase {

public:

	virtual float operator()(float x, float y) {
		return x - y;
	}

};

class Process {

public:

	float operator()(FunctorBase* ptr, float x, float y) {
		return (*ptr)(x, y);
	}

};

class MyDelegate {

private:

	typedef void(*myDelegate)(const std::string&);

	myDelegate ptr_;
	std::string str_;

public:

	MyDelegate(myDelegate ptr, const std::string& str) : ptr_(ptr), str_(str)
	{}

	void operator()() {
		(*ptr_)(str_);
	}

};

void printDisplay(const std::string& str) {
	std::cout << "The string value is: " << str << std::endl;
}

void printReverse(const std::string& str) {
	std::string str_copy = str;
	std::reverse(str_copy.begin(), str_copy.end());
	std::cout << "The reversed string value is: " << str_copy << std::endl;
}

void callDelegate(MyDelegate& myDelegate) {
	myDelegate();
}

int main() {

	//Question 1 & 2
	std::cout << "Question 1\n";

	std::vector<std::string> vec{ "This", "is", "a", "string", "based", "vector" };
	Display dis = std::for_each(vec.cbegin(), vec.cend(), Display());
	dis.showCount();

	//Question 3
	std::cout << "\n\nQuestion 3\n";

	AddFunctor* ptr_af = new AddFunctor;

	std::cout << "the value returned from AddFunctor is " << Process()(ptr_af, 3.2, 7.6) << std::endl;

	delete ptr_af;
	ptr_af = nullptr;

	SubtractFunctor* ptr_sf = new SubtractFunctor;

	std::cout << "the value returned from SubtractFunctor is " << Process()(ptr_sf, 8.1, 2.4) << std::endl;

	delete ptr_sf;
	ptr_sf = nullptr;

	//Question 4
	std::cout << "\n\nQuestion 4\n";

	MyDelegate myDelegate1(printDisplay, "hola mundo");
	myDelegate1();

	MyDelegate myDelegate2(printReverse, "hello world");
	myDelegate2();

	callDelegate(myDelegate1);

	std::cout << "\n\n\n";
	system("PAUSE");

	return 0;
}

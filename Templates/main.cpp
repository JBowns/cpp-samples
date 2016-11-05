#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>

template <class A, class B, class C>
class Triple {

public:

	Triple(A a, B b, C c) : _a(a), _b(b), _c(c)
	{}

private:
    
	A _a;
	B _b;
	C _c;

};

typedef Triple<int, float, double> my_type;

template<class T>
class Manager {

public:

	typedef std::shared_ptr<T> vec_type;

	void operator()(vec_type& ptr_t) {
		vec.push_back(std::move(ptr_t));
	}

	~manager() {
		vec.at(0).reset();
		std::for_each(vec.begin(), vec.end(), std::default_delete<T>());
	}

	void remove_at(int n) {
		de_allocate(at(n));
	}

	vec_ptr operator[] (int n) {
        return std:move(vec[n]);
    }

	vec_ptr at(int n) {
        return std:move(vec.at(n));
    }

private:

	vec_type get(vec_type ptr_t) {
		return std::move(ptr_t);
	}

	void de_allocate(vec_type ptr_t) {
		delete ptr_t;
		ptr_t = nullptr;
	}

	std::vector<std::shared_ptr<T>> vec;
};

int main()
{
	Manager<my_type> mgr;
	mgr(std::shared_ptr<my_type>(new my_type(10, 10.8f, 45.1)));
	return 0;
}

#include <iostream>     // std::cout
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <deque>        // std::deque
#include <list>         // std::list
#include <set>          // std::set
#include <map>          // std::map

int funcA(int& val) {
	return val * 2;
}

int funcB(int& val) {
	if (val % 2 == 0)
		return 0;
	else
		return val;
}

bool funcC(int& val) {
	return val < 0;
}

int main()
{

	// 1 **********************************
	std::cout << "Part A" << std::endl;

	std::vector<int> v{ 0, -12, 23, -34, 45, -56 };
	std::transform(v.begin(), v.end(), v.begin(), funcA);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";

	// 2 **********************************
	std::cout << "\n\nPart B" << std::endl;

	std::deque<int> d{ 1, 2, 3, 4, 5, 5, 4, 3, 2, 1 };
	std::transform(d.begin(), d.end(), d.begin(), funcB);

	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		std::cout << *it << " ";

	// 3 **********************************
	std::cout << "\n\nPart C" << std::endl;

	std::list<int> l(v.capacity());
	std::copy(v.begin(), v.end(), l.begin());
	std::list<int>::iterator listEraseBegin = std::remove_if(l.begin(), l.end(), funcC);
	l.erase(listEraseBegin, l.end());

	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";

	for (std::list<int>::reverse_iterator r_it = l.rbegin(); r_it != l.rend(); ++r_it)
		std::cout << *r_it << " ";

	// 4 **********************************
	std::cout << "\n\nPart D" << std::endl;

	std::set<int> s{ 1, -5, 0, 3, -4, 3, 0 };
	std::vector<int> v2(s.size());

	std::copy(s.begin(), s.end(), v2.begin());

	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << " ";

	// 5 **********************************
	std::cout << "\n\nPart E" << std::endl;

	std::multiset<int> ms{ 1, -5, 0, 3, -4, 3, 0 };

	for (std::multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it)
	{
		if (std::find(ms.begin(), ms.end(), *it) == it)
			std::cout << *it;
	}

	// 6 **********************************
	std::cout << "\n\nPart F" << std::endl;

	std::multimap<int, std::string> mm{ { 3, "vector" }, { 1, "list" }, { 2, "deque" }, { 4, "map" }, { 2, "set" } };

	for (std::multimap<int, std::string>::iterator it = mm.begin(); it != mm.end(); ++it)
	{
		std::cout << "key: " << it->first << " value: " << it->second.c_str() << std::endl;
	}

	// 7 **********************************
	std::cout << "\n\nPart G" << std::endl;

	int count;
	std::map<std::string, int> ma{ { "Jacob", 4004 }, { "Monica", 6309 }, { "Monica", 5300 }, { "Jacob", 6309 }, { "Monica", 5305 } };

	for (std::map<std::string, int>::iterator it = ma.begin(); it != ma.end(); ++it)
	{
		count = ma.count(it->first.c_str());
		if (count > 0)
			std::cout << it->first.c_str() << " teaches " << count << " module" << (count > 1 ? "s" : "") << std::endl;
	}

	std::cout << std::endl << std::endl;
	system("PAUSE");

}

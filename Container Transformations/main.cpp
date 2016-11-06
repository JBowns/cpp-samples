#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <algorithm>    // std::transform
#include <vector>       // std::vector
#include <random>		// std::
#include <chrono>		// high_resolution_clock
#include <functional>   // std::bind
#include <string>		// std::string
#include <numeric>      // std::accumulate
#include <list>			// std::list

struct Class1 {
	float operator() (float x, float y){
		return x / y;
	}
	float static divide(float x, float y){
		return x / y;
	}
};

class Class2 {
public:
	float operator() (float x, float y){
		return x / y;
	}
	float static divide(float x, float y){
		return x / y;
	}
};

int main()
{

#define PRINT(section, output) std::cout << "Part " << section << (section > 9 ? " " : "  ") << "- " << output; (output != "" ? std::cout << std::endl : std::cout << "");
#define PRINT_VECTOR(section, v) PRINT(section, ""); copy(v.begin(), v.end(), std::ostream_iterator<float>(std::cout, " " )); std::cout << std::endl;
#define PRINT_VECTOR(section, v) std::cout << "Part " << section << (section > 9 ? " " : "  ") << "- "; copy(v.begin(), v.end(), std::ostream_iterator<float>(std::cout, " " )); std::cout << std::endl;

	typedef std::vector<float> VECTOR;

	// 1 **********************************

	VECTOR v1 { 1, 2, 3, 4, 5 };

	PRINT_VECTOR(1, v1);

	// 2 **********************************

	VECTOR v2(10);

	std::mt19937 engine;
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	engine.seed((unsigned long)seed);
	std::generate(v2.begin(), v2.end(), engine);

	PRINT_VECTOR(2, v2);

	// 3 **********************************

	v2.clear();

	PRINT_VECTOR(3, v2);

	// 4 **********************************

	VECTOR v3(10);
	std::uniform_int_distribution<int> distribution(0, 1000);
	std::generate(v3.begin(), v3.end(), std::bind(distribution, engine));

	PRINT_VECTOR(4, v3);

	// 5 **********************************

	auto p1 = std::minmax_element(v3.begin(), v3.end());

	PRINT(5, "min:" + std::to_string(*p1.first) + " - max:" std::to_string(*p1.second));

	// 6 **********************************

	std::transform(v3.begin(), v3.end(), v3.begin(), [](int n) { return n*-1; });
	std::transform(v3.begin(), v3.end(), v3.begin(), std::negate<int>());

	PRINT_VECTOR(6, v3);

	// 7 **********************************

	VECTOR v4 = { 0, 1, 2, 3, 4 };
	VECTOR v5 = { 5, 6, 7, 8, 9 };
	VECTOR v6;

	std::transform(v4.begin(), v4.end(), v5.begin(), std::back_inserter(v6), std::plus<int>());

	PRINT_VECTOR(7, v6);

	// 8 **********************************

	VECTOR v7 = { 5, 6, 7, 8, 9 };

    PRINT(8, "Sum of " + accumulate(v7.begin(), v7.end(), 0));

	// 9 **********************************

	VECTOR v8 = { 10, 7, 3, 8, 9 };

	//auto divide = [](float x, float y) -> float {return x / y; };
	auto p2 = std::minmax_element(v8.begin(), v8.end());
	auto callDivide = std::bind(Class1().divide, std::placeholders::_1, *p2.second);
	std::transform(v8.begin(), v8.end(), v8.begin(), callDivide);

	PRINT_VECTOR(9, v8);

	// 10 *********************************

	VECTOR v9 = { 100, 47, 23, 81, 97 };
	auto isOdd = [](int n) -> bool {return (n & 1) == 1; };
	std::cout << "Part 10 - " << std::count_if(v9.begin(), v9.end(), isOdd) << " values are odd." << std::endl;

	// 11 *********************************

	v9.erase(std::remove_if(v9.begin(), v9.end(), isOdd), v9.end());

	PRINT_VECTOR(11, v9);

	// 12 *********************************

	VECTOR v10 = { 2, 9, 7, 8, 1, 5 };
	std::list<double> l1;
	std::copy_if(v10.begin(), v10.end(), std::back_inserter(l1), isOdd);

	PRINT_VECTOR(12, l1);

	// 13 *********************************

	VECTOR v11 = { 2, 3, 9, 7, 8, 25, 12, 6, 8, 1, 5 };
	std::sort(v11.begin(), v11.end());

	PRINT_VECTOR(13, v11);

	// 14 *********************************

	std::sort(v11.begin(), v11.end(), std::greater<int>());

	PRINT_VECTOR(14, v11);

	// 15 *********************************

	std::list<int> l2;
	std::copy(v11.rbegin(), v11.rend() - 1, std::back_inserter(l2));
    std::reverse_copy(v11.begin(), v11.end(), std::back_inserter(l2));

	PRINT_VECTOR(15, l2);

	// 16 *********************************

	std::list<int> l3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	VECTOR v12(l3.begin(), l3.end());

	std::random_shuffle(v12.begin(), v12.end());
	std::copy(v12.begin(), v12.end(), l3.begin());

	PRINT_VECTOR(16, l3);

	// 17 *********************************

	PRINT_VECTOR(17, v9);

	// 18 *********************************

	VECTOR v13 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	auto newBind = std::bind(std::multiplies<float>(), std::placeholders::_1, 2);

	std::transform(v13.begin(), v13.end(), v13.begin(), newBind);

	PRINT_VECTOR(18, v13);

	// 19 *********************************

	std::vector<int> v14{ 0, 1, 2, 3, 4, 5 };
	std::vector<int>::iterator(v14.begin(), v14.end(), std::ostream_iterator<int>(std::cout, " "));
	auto clock = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	std::mt19937 eng;
	eng.seed(clock);

	std::vector<float> help(10);

	std::generate(help.begin(), help.end(), eng);
	std::transform(help.begin(), help.end(), help.begin(), [&eng](int element){return eng(); });

	for (std::vector<float>::iterator it = help.begin(); it == help.end(); ++it) {
		std::cout << *it << " ";
	}

	std::uniform_int_distribution<int> dist(0, 1000);
	std::generate(help.begin(), help.end(), std::bind(dist, eng));
	std::generate(help.begin(), help.end(), [&dist, &eng](){return dist(eng); });

	Tutorial tut1(1, null);

	std::cout << std::endl << std::endl;
	system("PAUSE");
}

#include <iostream>     // std::cout
#include <fstream>
#include <streambuf>
#include <sstream>
#include <iterator>     // std::ostream_iterator
#include <algorithm>    // std::transform
#include <numeric>      // std::accumulate
#include <random>
#include <chrono>       // high_resolution_clock
#include <functional>   // std::bind
#include <vector>       // std::vector
#include <string>       // std::string
#include <list>         // std::list

#define PRINT_LINE_BREAKS std::cout << std::endl << std::endl;
#define PRINT_TITLE(question) std::cout << "Question " << question << ": ";
#define PRINT_INT(question, container) PRINT_TITLE(question); std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " ")); PRINT_LINE_BREAKS;
#define PRINT_FLOAT(question, container) PRINT_TITLE(question); std::copy(container.begin(), container.end(), std::ostream_iterator<float>(std::cout, " ")); PRINT_LINE_BREAKS;
#define PRINT_DOUBLE(question, container) PRINT_TITLE(question); std::copy(container.begin(), container.end(), std::ostream_iterator<double>(std::cout, " ")); PRINT_LINE_BREAKS;
#define PRINT_STRING(question, container) PRINT_TITLE(question); std::cout << std::endl;

std::copy(container.begin(), container.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

struct Increment
{
    struct Factorial
    {
        int operator()() {
            return n++;
        }
        int n = 1;
    };

    Factorial(int n) {}

    n_ = n; v_ = n;

    int operator()() {
        v_ = v_ * (n_ - 1);
        n_ -= 1;
        return v_;
    }

};

int n_ { 1 };
int v_ { 1 };

struct BuildInt
{

    bool operator()(char c) {
        if (c == '\n') {
            return false;
        }
        char_.push_back(c);
        return true;
    }

    int get() {
        std::string str(char_.begin(), char_.end());
        char_.clear();
        return atoi(str.c_str());
    }

    std::vector<char> char_;

};

auto isOdd = [](int n) -> bool { return (n & 1) == 1; };

int main() {

    // Question 1
    std::vector<int> vQ1 { 12, 10, -3, 24, 45 };
    PRINT_INT(1, vQ1);

    // Question 2
    auto clock = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::vector<int> vQ2(10);
    std::mt19937 engine;
    engine.seed(clock);
    std::generate(vQ2.begin(), vQ2.end(), engine);

    PRINT_INT(2, vQ2);

    //Question 3

    vQ2.clear();

    PRINT_INT(3, vQ2);

    //Question 4

    std::vector<int> vQ4(10);
    auto dist = std::uniform_int_distribution<int>(0, 1000);
    std::generate(vQ4.begin(), vQ4.end(), std::bind(dist, engine));

    PRINT_INT(4, vQ4);

    //Question 5

    auto min_max = std::minmax_element(vQ4.begin(), vQ4.end());

    PRINT_INT(5, vQ4);

    std::cout << "mix: value (" << *(min_max.first) << ") position (" << std::find(vQ4.cbegin(), vQ4.cend(), *(min_max.first)) - vQ4.cbegin() << ")" << std::endl;
    std::cout << "max: value (" << *(min_max.second) << ") position (" << std::find(vQ4.cbegin(), vQ4.cend(), *(min_max.second)) - vQ4.cbegin() << ")" << std::endl << std::endl;

    //Question 6

    std::transform(vQ4.begin(), vQ4.end(), vQ4.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, -1));

    PRINT_INT(6, vQ4);

    //Question 7

    std::vector<int> v1Q7 { 32, 43, 72, 2, 53, 2, 65 }; std::vector<int> v2Q7 { 23, 6, 82, 21, 32, 1, 87 };
    std::vector<int> v3Q7;
    std::transform(v1Q7.begin(), v1Q7.end(), v2Q7.begin(), std::back_inserter(v3Q7), std::plus<int>());

    PRINT_INT(7, v3Q7);

    //Question 8

    std::vector<int> vQ8 { 43, 12, 21, 5, 54, 79, 20, 2 };

    PRINT_INT(8, vQ8);

    std::cout << "Sum of: " << std::accumulate(vQ8.begin(), vQ8.end(), 0);

    PRINT_LINE_BREAKS;

    //Question 9

    std::vector<float> vQ9 { 43, 12, 21, 5, 54, 79, 20, 2 };
    auto max = std::max_element(vQ9.begin(), vQ9.end());

    std::transform(vQ9.begin(), vQ9.end(), vQ9.begin(), std::bind(std::divides<float>(), std::placeholders::_1, *(max)));

    PRINT_FLOAT(9, vQ9);

    //Question 10

    std::vector<int> vQ10 { 43, -12, 21, 5, 54, -79, -20, 2 };
    int count = std::count_if(vQ10.begin(), vQ10.end(), isOdd);

    //Question 11

    std::vector<int> vQ11 { 43, -12, 21, 5, 54, -79, -20, 2 };
    auto to_remove = std::remove_if(vQ11.begin(), vQ11.end(), isOdd);
    vQ11.erase(to_remove, vQ11.end());

    //Question 12

    std::vector<int> vQ12 { 43, -12, 21, 5, 54, -79, -20, 2 };
    std::list<double> lQ12;
    std::copy_if(vQ12.begin(), vQ12.end(), std::back_inserter(lQ12), isOdd);

    PRINT_DOUBLE(12, lQ12);

    //Question 13

    std::vector<int> vQ13 { 3, -32, 21, 5, 4, 34, -79, 11, 27 };
    std::sort(vQ13.begin(), vQ13.end());

    PRINT_INT(13, vQ13);

    //Question 14

    std::vector<int> vQ14 { 3, -32, 21, 5, 4, 34, -79, 11, 27 };
    std::sort(vQ14.rbegin(), vQ14.rend());

    PRINT_INT(14, vQ14);

    //Question 15

    std::vector<int> vQ15 { 3, -32, 21, 5, 4, 34, -79, 11, 27 };
    std::list<int> lQ15;
    std::reverse_copy(vQ15.cbegin(), vQ15.cend(), std::back_inserter(lQ15));

    PRINT_INT(15, lQ15);

    //Question 16

    std::vector<int> vQ16;
    std::list<int> lQ16;
    std::generate_n(std::back_inserter(vQ16), 10, Increment());
    std::random_shuffle(vQ16.begin(), vQ16.end());
    std::copy(vQ16.begin(), vQ16.end(), std::back_inserter(lQ16));

    PRINT_INT(16, lQ16);

    //Question 17

    vQ16.erase(std::remove_if(vQ16.begin(), vQ16.end(), isOdd), vQ16.end());

    PRINT_INT(17, vQ16);

    //Question 18

    std::vector<int> vQ18 { 3, -32, 21, 5, 4, 34, -79, 11, 27 };
    std::transform(vQ18.begin(), vQ18.end(), vQ18.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

    PRINT_INT(18, vQ18);

    //Question 19

    std::vector<int> vQ19 { 34, 21, 654, 1, 3, 34, 654, 1 };
    std::sort(vQ19.begin(), vQ19.end());
    vQ19.erase(std::unique(vQ19.begin(), vQ19.end()), vQ19.end());

    PRINT_INT(19, vQ19);

    //Question 20

    int temp_value;
    std::vector<std::string> vQ20;
    std::ifstream file;
    file.open("file.txt", std::ifstream::in);
    if (file.is_open()) {

        //version 1
        int length = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
        file.seekg(0, std::ios::beg);
        std::generate_n(std::back_inserter(vQ20), length + 1, [&file]() -> std::string {
            std::string temp;
            std::getline(file, temp);
            return temp;
        });
        file.seekg(0, std::ios::beg);
        file.close();

        //version 2 (in progress...)
        std::vector<int> file_in;
        BuildInt bi;
        std::transform(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), std::back_inserter(file_in), bi);
    }

    //Question 21

    int initial_value = 10;
    std::vector<int> vQ21;
    std::generate_n(std::back_inserter(vQ21), initial_value - 2, Factorial(initial_value));

    PRINT_INT(21, vQ21);

    std::cout << "The factorial of " << initial_value << " is " << *(vQ21.end() - 1);
    PRINT_LINE_BREAKS;

    //Question 22

    std::cout << "Enter a word:";
    std::string input;
    std::cin >> input;
    std::vector<int> vQ22;
    std::generate_n(std::back_inserter(vQ22), (input.length() > 2 ? input.length() - 2 : input.length() - 1),
    Factorial(input.length()));
    std::vector<std::string> anagram_store;

    if (input.length() > 1) {

        std::sort(input.begin(), input.end());
        anagram_store.resize(*(vQ22.end() - 1), "");
        anagram_store[0] = input;
        std::generate(anagram_store.begin() + 1, anagram_store.end(), [&input]() -> std::string {
                std::next_permutation(input.begin(), input.end());
        });

        return input;

        std::sort(anagram_store.begin(), anagram_store.end());
        anagram_store.erase(std::unique(anagram_store.begin(), anagram_store.end()), anagram_store.end());

    } else {
        anagram_store.push_back(input);
    }

    PRINT_STRING(22, anagram_store);

    std::cout << std::endl << std::endl;
    system("PAUSE");
}

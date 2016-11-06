#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class BasicLogEntry {

public:

	std::string message;

};

class LogEntryWithDateTime : public BasicLogEntry {

public:

	std::string date;
	std::string time;

};

template <class T1, class T2>
class LogGenerator_v1 {

public:

	void add_entry(const T1& log_entry) {
		_logs.push_back(log_entry);
	}

private:

	T2 _logs;

};

template <class T, template <class, class> class N>
class LogGenerator_v2 {

public:

	void add_entry(const T& log_entry) {
		logs.push_back(log_entry);
	}

private:

	N<T, std::allocator<T>> logs;

};

template <class T1, class T2>
class SaveToFile {

public:

	void output_policy(std::string filename, T1& logs) {
		std::ofstream file(filename);
		if (!file) {
			exit(EXIT_FAILURE);
		} else {
			file << logs;
		}
	}

};

template <class T1, class T2>
class OutputToCout {

public:

	void output_policy(T1& logs) {
		std::for_each(logs.begin(), logs.end(), [](T2& entry) {
			std::cout << "Message:" << entry.message;
		});
	}

};

template <template <class, class> class SP, class T, template <class, class> class N>
class LogGenerator_v3 : public SP<N<T, std::allocator<T>>, T> {

public:

	void add_entry(const T& log_entry) {
		_logs.push_back(log_entry);
	}

	void output() {
		output_policy(_logs);
	}

	void output(std::string name) {
		output_policy(name, _logs);
	}

	N<T, std::allocator<T>> _logs;

};

int main() {
	
	LogGenerator_v1<BasicLogEntry, std::vector<BasicLogEntry>> log1;
	BasicLogEntry log_entry1;
	log_entry1.message = "This is a log entry";
	log1.add_entry(log_entry1);

	LogGenerator_v2<BasicLogEntry, std::vector> log2;

	LogGenerator_v3<SaveToFile, BasicLogEntry, std::vector> log3;
	BasicLogEntry log_entry2;
	log_entry2.message = "This is a log entry";
	log3.add_entry(log_entry2);
	log3.output("");

	LogGenerator_v3<OutputToCout, BasicLogEntry, std::deque> log4;
	BasicLogEntry log_entry3;
	log_entry3.message = "This is a log entry";
	log4.add_entry(log_entry3);
	log4.output();

	return 0;
}

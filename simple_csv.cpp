#include <simple_csv.h>
#include <cmath>
#include <thread>

std::vector<std::string> parser(const std::string& str, const std::string& delim) {
	std::regex regex{ delim };
	std::vector<std::string> out{ std::sregex_token_iterator(str.begin(), str.end(), regex, -1)
				, std::sregex_token_iterator() };
	std::vector<std::string> tempo;
	for (std::string i : out) {
		tempo.push_back(i);
	}
	return tempo;

}

std::vector<std::vector<std::string>> csv_reader(const std::string& file_path, const std::string& delim) {
	std::fstream f;
	std::string str;
	std::vector<std::string> temp;
	std::vector<std::vector<std::string>> result;
	f.open(file_path, std::ios::in);
	while (std::getline(f, str)) {
		temp = parser(str, delim);
		result.push_back(temp);
	}
	return result;
}

std::vector<std::string> col(const std::vector<std::vector<std::string>>& table, const int& loc) {
	std::vector<std::string> v1;
	std::vector<std::string> v2;
	std::vector<std::string> v3;
	std::vector<std::string> v4;
	int r_size = ceil(table.size() / 4.0);

	std::thread t1([&table, &loc, &v1, &r_size]() {
		for (int i {0}; i < r_size;++i) {
			v1.push_back(table[i][loc]);
		}
	});
	std::thread t2([&table, &loc, &v2, &r_size]() {
		for (int i {r_size}; i < r_size*2;++i) {
			v2.push_back(table[i][loc]);
		}
	});
	std::thread t3([&table, &loc, &v3, &r_size]() {
		for (int i {r_size*2}; i < r_size*3;++i) {
			v3.push_back(table[i][loc]);
		}
	});
	std::thread t4([&table, &loc, &v4, &r_size]() {
		for (int i {r_size*3}; i < table.size();++i) {
			v4.push_back(table[i][loc]);
		}
	});
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	v1.insert(v1.end(), v2.begin(), v2.end());
	v1.insert(v1.end(), v3.begin(), v3.end());
	v1.insert(v1.end(), v4.begin(), v4.end());
	return v1;
}
std::vector<std::string> row(const std::vector<std::vector<std::string>>& table, const int& loc) {
	return table[loc];
}

std::vector<double> to_double(std::vector<std::string> vect, const bool& header) {
	if (header) {
		vect.erase(vect.begin());
	}
	std::vector<double> temp(vect.size());
	std::transform(vect.begin(), vect.end(), temp.begin(), [](const std::string& val) {
		return std::stod(val);
		});
	return temp;
}

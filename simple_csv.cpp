#include <simple_csv.h>

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
	std::vector<std::string> temp;
	for (std::vector<std::string> i : table) {
		temp.push_back(i[loc]);
	}
	return temp;
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
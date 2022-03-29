#include <simple_csv.h>
#include <iostream>

int main() {
	std::vector<std::vector<std::string>> a{ csv_reader("btc_usdt_1d.csv") };
	std::vector<std::string> b{ col(a, 0) };
	std::vector<std::string> c{ row(a, 13) };
	std::vector<double> d{ to_double(b) };
	std::cout << "Everything is ok.\n" << std::endl;
	return 0;
}
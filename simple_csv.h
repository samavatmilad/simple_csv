#ifndef SIMPLE_CSV_H
#define SIMPLE_CSV_H

#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <algorithm>
#include <simple_csv.cpp>


std::vector<std::vector<std::string>> csv_reader(const std::string& file_path, const std::string& delim = "\\,");
std::vector<std::string> col(const std::vector<std::vector<std::string>>& table, const int& loc);
std::vector<std::string> row(const std::vector<std::vector<std::string>>& table, const int& loc);
std::vector<double> to_double(std::vector<std::string> vect, const bool& header = true);

#endif
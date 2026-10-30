#ifndef KARATSUBA
#define KARATSUBA
#include <vector>
#include <utility>
#include <string>

using BigNum = std::vector<int>;

std::vector<std::string> read_file(std::string fn);

BigNum from_string(const std::string& number_string);

std::string to_string(const BigNum& number_vector);

std::pair<BigNum, BigNum> split_number(const BigNum& number_vector, int split);

BigNum karatsuba(const BigNum& n1, const BigNum& n2);

BigNum add(BigNum n1, BigNum n2);

BigNum multiply(BigNum n, int number);



#endif
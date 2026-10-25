#include "module 1\week 1\Karatsuba.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
std::vector<std::string> read_file(std::string fn){
    std::ifstream infile(fn);
    std::string line;
    std::vector<std::string> numbers;
    while(std::getline(infile, line)){
        int pos = line.rfind(' ');
        std::string numbers_string = line.substr(pos+1);
        numbers.push_back(numbers_string);
    }
}

BigNum from_string(const std::string& number_string){
    BigNum number_vector;
    for(int i=0; i<number_string.length(); i++){
        number_vector.push_back(number_string[i]);
    }
    return number_vector;
};

std::string to_string(const BigNum& number_vector){
    std::string number_string;
    for(int i=0; i<number_vector.size(); i++){
        number_string += static_cast<char>(number_vector[i] + '0');
    }
    return number_string;
};

std::pair<BigNum, BigNum> split_number(const BigNum& number_vector, int split){
    BigNum a;
    BigNum b;
    int n=number_vector.size();
    for(int i=0; i<n; i++){
        if(i<n-split){
            a.push_back(number_vector[i]);
        }
        else{
            b.push_back(number_vector[i]);
        }
    }
    std::pair<BigNum, BigNum> result;
    result.first = a;
    result.second = b;

    return result;
};

BigNum karatsuba(const BigNum& n1, const BigNum& n2){
    int s1 = n1.size();
    int s2 = n2.size();
    
    if(s1 == 1 or s2 == 1){
        return;  // TODO 
    }


};
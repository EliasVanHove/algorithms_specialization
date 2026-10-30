#include "Karatsuba.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iterator>
std::vector<std::string> read_file(std::string fn){
    std::ifstream infile(fn);
    std::string line;
    std::vector<std::string> numbers;
    while(std::getline(infile, line)){
        int pos = line.rfind(' ');
        std::string numbers_string = line.substr(pos+1);
        numbers.push_back(numbers_string);
    }
    return numbers;
}

BigNum from_string(const std::string& number_string){
    BigNum number_vector;
    for(int i=0; i<number_string.length(); i++){
        number_vector.push_back(number_string[i] - '0');
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

BigNum add(BigNum n1, BigNum n2){
    int next = (0 - 0%10)/10;
    int g1 = 0;
    int g2 = 0;
    int g1g2_next = g1 + g2 + next;
    BigNum result;
    for(int i=0; i<std::max(n1.size(), n2.size()); i++){
        if(i<n1.size()){
            g1 = n1[n1.size() - 1 - i];}
        else{
            g1 = 0;
        }
        if(i<n2.size()){
            g2 = n2[n2.size() - 1 - i];}
        else{
            g2 = 0;
        }
        g1g2_next = g1 + g2 + next;
        result.push_back(g1g2_next%10);
        // std::cout<<"g1 is "<< g1 <<" g2 is "<<g2 <<" next is "<<next << " result is"<<g1g2_next%10<<std::endl;
        next = (g1g2_next-g1g2_next%10)/10;
    }

    if(next>0){
        result.push_back(next);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

BigNum multiply(BigNum n, int number){
    int next = (0 - 0%10)/10;
    int g1 = 0;
    int g1number_next = g1 * number + next;
    BigNum result;
    for(int i=0; i<n.size(); i++){
        g1 = n[n.size()-1-i];
        g1number_next = g1 * number + next;
        result.push_back(g1number_next%10);
        next = (g1number_next-g1number_next%10)/10;
    }
    if(next>0){
        result.push_back(next);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

BigNum karatsuba(const BigNum& n1, const BigNum& n2){
    int s1 = n1.size();
    int s2 = n2.size();
    
    if(s1 == 1 or s2 == 1){
        return n1;  // TODO 
    }

    return n1;
};
#include "Karatsuba.hpp"
#include <iostream>

int main(){
    std::vector<std::string> number_strings = read_file("numbers.txt");
    std::cout<<"read file"<<'\n'<<std::endl;
    BigNum n1 = from_string(number_strings[0]);
    BigNum n2 = from_string(number_strings[1]);
    std::cout<<"string to vector"<<'\n'<<std::endl;
    std::string number_string1 = to_string(n1);
    std::cout<<"vector to string"<<'\n'<<std::endl;
    std::cout<<number_string1<<'\n'<<std::endl;
    BigNum sum = add(n1, n2);
    std::string sum_string = to_string(sum);
    std::cout<<"sum to string successful"<<'\n'<<std::endl;
    std::cout<<sum_string<<'\n'<<std::endl;
    BigNum mult = multiply(n1, 3);
    std::string mult_string = to_string(mult);
    std::cout<<mult_string<<std::endl;
    std::cout<<"multiplication successful"<<'\n'<<std::endl;

    return 0;
}
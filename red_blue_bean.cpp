#include <iostream>
#include <string>
#include <sstream>
 
#define SZ 3 
 
void simple_tokenizer(std::string s, unsigned long long* arr_)
{
    std::stringstream ss(s);
    std::string word;
    int i = 0;
    while (ss >> word) {
        arr_[i++] = std::stoull(word);
    }
}
 
int main()
{
    int size;
    std::cin >> size ;
    std::cin.ignore();
    for (size_t i = 0; i < size; i++)
    {
        unsigned long long arr_[SZ];
 
        std::string str;
        getline(std::cin, str);

        simple_tokenizer(str, arr_);
 
        
        if(arr_[0] < arr_[1])
        {
            std::cout << ((/*arr_[0] + arr_[2] <= arr_[1] &&*/ arr_[0] * ( 1ul + arr_[2]) >= arr_[1]) ? "YES\n" : "NO\n" ); 
        }
        else 
        {
            std::cout << ((/*arr_[1] + arr_[2] <= arr_[0] &&*/ arr_[1] * ( 1ul + arr_[2]) >= arr_[0]) ? "YES\n" : "NO\n" ); 
        }
    }
    
}
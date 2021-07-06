#include <iostream>
#include <queue>
#include <string>
#include <regex>


// // this is very slow approach
class Solution {

public:

    bool repeatedSubstringPattern(std::string s) {
        std::regex self_regex("^(.*)\\1+$");
        return std::regex_match(s, self_regex);
    }
    
};


// this aproach don t work , maybe ı can search last and first simultuneously after first match ı run a loop.
// class Solution {
// public:
//     bool repeatedSubstringPattern(std::string s) {

//         int i, plt = 0;
//         std::queue<char> queue;
//         bool flag = false;

//         for( i = 0 ; i < s.length() ; i++ ) {

//             if( queue.front() == s[i] )
//             {
//                 if( !isMatch( queue, s.begin() + i, s.end() ) ) 
//                 {
//                      return false;
//                 }
//                 i+=queue.size()-1;
//                 flag = true;
//             }
//             else if( flag == true ) {
//                 return false;
//             }
//              else {
//                 queue.push(s[i]);
//             }

//         }

//         return flag;

//     }

// private:
//     bool isMatch( std::queue<char> queue, const std::string::iterator& begin, const std::string::iterator& end ) {

//         int i = 0;

//         while(!queue.empty())
//         {
//             char popped = queue.front();
//             queue.pop();
            
//             if( popped != *(begin + i ) ){
//                 return false;
//             }

//             i++;

//         }

//         return true;

//     }
// };


int main()
{

    Solution sol;  
    std::string str = "abcabcabcabc";

    bool test1 = sol.repeatedSubstringPattern(str);
    std::cout << test1 << std::endl;


    str = "abcab";
    bool test2 = sol.repeatedSubstringPattern(str);
    std::cout << test2 << std::endl;

    str = "ababc";
    bool test3 = sol.repeatedSubstringPattern(str);
    std::cout << test3 << std::endl;
 
    str = "ali";
    bool test4 = sol.repeatedSubstringPattern(str);
    std::cout << test4 << std::endl;
 
    str = "abaababaab";
    bool test5 = sol.repeatedSubstringPattern(str);
    std::cout << test5 << std::endl;

 


    return 0;

}
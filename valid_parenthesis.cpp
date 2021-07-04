#include <iostream>
#include <stack>

using namespace std;

class Solution {


public:

    bool isValid(string s) {

        stack<char> stk;
        stk.push(s.at(0));
        int i = 1;
        while(i < s.size())
        {
            if(isClosure(s[i]) ){
                if (!stk.empty() && isPair(stk.top(), s[i]))
                    stk.pop();
                else 
                    return false;
            }
            else {
                stk.push(s[i]);
            }
            i++;

        }
        return stk.empty();

    }

private:
    inline bool isClosure(char c){
        return c == '}' || c == ']' || c == ')';
    }
    inline bool isPair(char c, char& pair) {
        switch (c)
        {
        case '{':
            c = '}';
            break;
        case '[':
            c = ']';
            break;
        case '(':
            c = ')';
            break;
        default:
            c = '\0'; // EOF
            break;
        }
    
        return c == pair;
    }


};

int main(int argc, char* argv[]) {
    
    
    Solution sol;

    string s1 = "()[]{}";
    bool isValid1 = sol.isValid(s1);
    std::cout << isValid1 << std::endl;



    string s2 = "(){}}{";
    bool isValid2 = sol.isValid(s2);
    std::cout << isValid2 << std::endl;


    string s3 = "([)]";
    bool isValid3 = sol.isValid(s3);
    std::cout << isValid3 << std::endl;

    string s4 = "(((";

    bool isValid4 = sol.isValid(s4);
    std::cout << isValid4 << std::endl;


    string s5 = "((()(";
    bool isValid5 = sol.isValid(s5);
    std::cout << isValid5 << std::endl;


    string s6 = "((())";
    bool isValid6 = sol.isValid(s6);
    std::cout << isValid6 << endl;

    return 0;
}
/*
"()"
"()[]{}"
"(]"
"([)]"
"{[]}"
"((("
"((()("
"((())"
*/
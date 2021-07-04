
#include <iostream>
#include <math.h>
#define INTMAX 2147483647
#define INTMIN -2147483648

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INTMAX / 10 || (rev == INTMAX / 10 && pop > 7)) return 0;
            if (rev < INTMIN / 10 || (rev == INTMIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};


int main()
{

    // int x=73556;

    // std::cout << (int)pow(2,31)-1 << std::endl;


    Solution sol;
    int reverse = sol.reverse(123);
    std::cout << reverse << std::endl;


    return 0;

}
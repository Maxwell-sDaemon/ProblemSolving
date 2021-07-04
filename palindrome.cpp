#include<iostream>

class Solution {
public:
    bool isPalindrome(int x) {

        int rev=0; // this compare with is it palindrome
        int cmp = x;
        int msb;
        // asm("bsrl %1,%0" : "=r"(msb) : "r"(x));//bit reverse scan x86
        
        while(x!=0) {
            
            int p = x % 10;
            x = x / 10;
            rev = rev * 10 + p;
        }

        if(cmp == rev) return true;
        return false;
    }
};

int main (int,char**)
{
  Solution sol;
  std::cout << sol.isPalindrome(-121) << " " << sol.isPalindrome(1234567899) << std::endl ;
  return 0;
}
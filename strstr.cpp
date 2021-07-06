#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
	public:
	int strStr(string haystack, string needle)
	{

		// alternative dumb c++ code O(n*m) wtf??
		// return haystack.find(needle)

		// below code give error in leetcode, leetcode sucks c++20 standart
		auto it = search( haystack.begin() ,haystack.end(), boyer_moore_searcher( needle.begin(), needle.end() ));
		if(it != haystack.end())
        	return it - haystack.begin();
		return -1;
	}

};

int main()
{

	Solution sol;
	string haystack = "hello", needle = "ll";
	
	cout << sol.strStr( haystack, needle ) << endl;


	return 0;
}

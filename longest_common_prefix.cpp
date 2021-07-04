#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        string tmp;
        string sol = strs.at(0);
        
        int i, j = 0;
        
        for (i = 0; i < strs.size()-1; i+=2)
        {
            string str = strs.at(i);
            string str2 = strs.at(i+1);
            j = 0;
            
            while(j < str2.size() && j < sol.size() && str2.at(j) == str.at(j) && sol.at(j) == str.at(j)){
                tmp.push_back(str.at(j));
                j++;
            }

            sol = tmp;
            tmp = "";
        }
        
        if(strs.size()%2 == 1)
        {
            string _sol;
            tmp = strs.at(i);
            j=0;
            while(j < tmp.size() && j < sol.size() && sol.at(j) == tmp.at(j)){
                _sol.push_back(tmp.at(j));
                j++;
            }
            return _sol;
        }
        
        return sol;
    }
};

int main()
{
    vector<string> strs = {"dog", "racecar", "car"};
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}
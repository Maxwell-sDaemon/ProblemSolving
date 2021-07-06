#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {

        unordered_map<int,int> map;
        int sz = arr.size() / 2, i, j, count = 0;

        for( auto j : arr ) {

            map[j]++;
            if( map[j] >= sz )
            {
                return 1;
            }
        }

        // sort value of map
        vector<int> vals;
        for( auto j : map) {
            vals.push_back(j.second);
        }

        std::sort(vals.begin(), vals.end());
        int _c = 0;
        for( i = vals.size() - 1 ; i >= 0 && count < sz  ; i-- )
        {

            count += vals[i];
            _c++;

        }

        return _c;
    }

};



int main() {

    Solution sol;

    vector<int> vec1 = {3,3,3,3,5,5,5,2,2,7};
    int minSet = sol.minSetSize(vec1);
    std::cout << minSet << std::endl;

    vec1 = {7,7,7,7,7,7};
    minSet = sol.minSetSize(vec1);
    std::cout << minSet << endl;

    vec1 = {1,9};
    minSet = sol.minSetSize(vec1);
    std::cout << minSet <<  endl;

    vec1 = {1000,1000,3,7};
    minSet = sol.minSetSize(vec1);
    std::cout << minSet <<  endl;


    return 0;

}
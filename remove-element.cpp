#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // without free unused
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
        

        // with free unused
        // nums.erase(remove( nums.begin(), nums.end(), val ), nums.end() );      
        // return nums.size();
    }
};

int main() 
{

    std::cout << "removeElement " << std::endl;

    Solution sol ;

    vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;

    sol.removeElement(nums, val);

    for( auto i : nums ) {
        std::cout << i << std::endl;
    }    

    return 0;

}
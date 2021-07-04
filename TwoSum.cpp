#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> map;
        int i ;
        for(i = 0 ; i < nums.size() ; i++ ){
            auto elem = map.find(nums[i]);
            if(elem != map.end()){
                return { elem->second, i };
            }
            map.emplace(target-nums[i], i);
        }        
        return {-1,-1};    
    }
};

int main()
{

    Solution sol;

    cout<<"first test appliying" << endl;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> idx_tar = sol.twoSum(nums, target);
    cout << idx_tar[0] << " " << idx_tar[1] << endl;

    cout<<"second test appliying" << endl;
    vector<int> nums2 = {3,2,4};
    int target2 = 6;
    vector<int> idx_tar2 = sol.twoSum(nums2, target2);
    cout << idx_tar2[0] << " " << idx_tar2[1] << endl;

    cout<<"third test is applying" << endl;
    vector<int> nums3 = {3,3};
    int target3 = 6;
    vector<int> idx_tar3 = sol.twoSum(nums3, target3);
    cout << idx_tar3[0] << " " << idx_tar3[1] << endl;




    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// assume always vector size is larger than 1
    int removeDuplicates(vector<int>& nums) {

		if( nums.size() == 0){
			return 0;
		}

		int i, plt = nums.at(0), count = 1 ;
		
        for( i = 1 ; i < nums.size() ; i++ )
		{
			int num = nums[i];
			if( num != plt ) {
				nums[count++] = num ;
				plt = num;
			}

		}
		return count;
	}

};

int main() {

	int i, j ;
	Solution sol;

	vector<int> test = { 0, 0 ,1 ,1 ,1 ,2 ,2 ,3 ,3, 4 };

	int removed_element_count = sol.removeDuplicates( test );

	cout << removed_element_count << endl;

	for( i = 0 ; i < removed_element_count ; i++ )
	{
		cout << test[i] << " " ;
	}
	cout << endl;



	return 0;

}
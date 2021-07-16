#include <iostream>
#include <string>

/**
 *
 * abcdefghjklş
 * 6 
 * a    lş
 * b   k  
 * c  j
 * d h
 * eg
 * f
 *
 */
using namespace std;

class Solution {
	public:
	string convert(string s, int numRows) {
		
		int len = s.size();
		int big_step = 2*numRows-2;

		int zigzag_offset = len % ( big_step ) - numRows; 
		int numCols = (numRows-1)*( len / big_step ) + ( ( zigzag_offset > 0 ) ? zigzag_offset : 0);
		char * my_foo = new char[numCols * numRows];

		fill_n(my_foo, numCols*numRows, ' ');

		int i=0, j=0;
		bool zagging = false;

		while( j < len )
		{
			if(i / numCols == numRows)
			{
				zagging = true;
				i--;
			}
			else if( zagging == true && i/numCols == 0  )
			{
				zagging = false;
			}
			if(zagging != true)
			{
				my_foo[i] = s[j++];
				i += numCols;
			}
			else 
			{
				// move corner
				i = move_corner(i, numRows, numCols);
				my_foo[i] = s[j++];
			}
		}

		string word;

		for( i = 0 ; i < numCols * numRows; i++ )
		{
			const char& character = my_foo[i];
			if(character != ' ') {
				word.push_back(character);
			}

			cout << my_foo[i];
			if( i % numCols == numCols-1 ) {
				cout << my_foo[i] ;
				cout << endl ;	
			}
		}

		return word;

	}
	private:
	int move_corner(int i, int numRows, int numCols)
	{
		int row_idx, col_idx;
		row_idx = i / numCols;
		col_idx = i % numCols;
		col_idx++;
		row_idx--;
		return numCols * row_idx + col_idx;
	}
};

int main()
{
	Solution sol;

	string test_string1 = "PAYPALISHIRINGGG";
	int test_numrows = 3;	
	sol.convert(test_string1, 3);


	return 0;
}

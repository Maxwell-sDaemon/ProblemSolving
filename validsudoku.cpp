#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

class Solution
{

// this sudoku solver problem is constraint satisfaciton problem 
// give cosntrains are 3 by 3 square is have element of 1 to 9
// all rows are also be in 1 to 9
// all colums have 1 to 9 

private:

    bool check_duplicate(vector<int>& list) {

        char character; 

        for (auto i : list)
        {
            if( i > 1 ){
                std::fill(list.begin(), list.end(), 0);
                return true;
            }
                
        }
        std::fill(list.begin(), list.end(), 0);
        return false;
    }

    bool is_row_stable(vector<vector<char>>& board) {
        
        std::vector<int> nine_check{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        char character; 
        size_t i, j;

        for ( i = 0; i < board.size() ; i++)
        {
            for ( j = 0; j < board.size() ; j++)
            {
                character = board[i][j];
                if (character > 46)
                    nine_check[character-48]++;
            }
            if ( check_duplicate(nine_check) ) {
                cout << "row violation ..." << "(row,column,value)" << "(" << i << "," << j << "," << character << ")" << endl;
                return false;
            }
               
        }
        
        return true;

    }

    bool is_column_stable(vector<vector<char>>& board) {

        std::vector<int> nine_check{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        char character ;
        size_t i, j ;
        for (i = 0 ; i < board.size() ; i++)
        {
            for (j = 0 ; j < board.size() ; j++)
            {
                character = board[j][i];
                if (character > 46)
                    nine_check[character-48]++;
            }
            if ( check_duplicate(nine_check) )
            {
                cout << "column violation ..." << "(row,column,value)" << "(" << i << "," << j << "," << character << ")" << endl;
                return false;
            }
        }

        return true;
    }

    bool is_square_stable(vector<vector<char>>& board) {

        int size_triple_square = board.size() / 3;
        std::vector<int> nine_check{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        char character;
        size_t i, j, k, l;

        for ( i = 0; i < size_triple_square; i++)
        {
            for ( j = 0; j < size_triple_square; j++)
            {
                // 3 x 3 search 
                for ( k = 0; k < size_triple_square; k++)
                {
                    for ( l = 0; l < size_triple_square; l++)
                    {
                        character = board[i*3+k][j*3+l];
                        if( character > 46 ) {
                            nine_check[character-48]++;
                        }   
                    }
                    
                }
                if ( check_duplicate(nine_check) )
                {
                    cout << "SQUARE violation ..." << "square belong coordinate (squareX, squareY), (row,column,value)" << "(" << k << "," << l << ")" << "," << "(" << i << "," << j << "," << character << ")" << endl;
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // row, col, square  check
        bool row_stable = is_row_stable(board)
            , column_stable =  is_column_stable(board)
            , square_stable = is_square_stable(board);
        
        if( row_stable && column_stable && square_stable) {
            return true;
        }

        return false;

    }

};


int main()
{
    Solution sol;
    bool check_existence = false;
    vector<vector<char>> board;
    
    cout<< "test 1" << endl;
    board = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    check_existence = sol.isValidSudoku(board);

    cout << "sudoku validation checking ... " << endl;
    cout <<  check_existence << endl;
    cout << "this test must be true " << endl;

    assert(check_existence == true);
    check_existence=false;

    cout << "test 2" << endl;
    board  = {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'5','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    check_existence = sol.isValidSudoku(board);

    cout << "sudoku validation checking ... " << endl;
    cout <<  check_existence << endl;
    cout << "this test must be false " << endl;

    assert(check_existence == false);
    check_existence=false;


    cout << "test 3" << endl;
    board  = {                  {'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','6','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    check_existence = sol.isValidSudoku(board);

    cout << "sudoku validation checking ... " << endl;
    cout <<  check_existence << endl;
    cout << "this test must be false " << endl;

    assert(check_existence == false);
    check_existence=false;

    cout << "test 4" << endl;
    board  = {                  {'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','6','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};

    check_existence = sol.isValidSudoku(board);

    cout << "sudoku validation checking ... " << endl;
    cout <<  check_existence << endl;
    cout << "this test must be false " << endl;

    assert(check_existence == false);
    check_existence=false;

    cout << "test 5" << endl;
    board = {{'.','.','.','.','5','.','.','1','.'}
            ,{'.','4','.','3','.','.','.','.','.'}
            ,{'.','.','.','.','.','3','.','.','1'}
            ,{'8','.','.','.','.','.','.','2','.'}
            ,{'.','.','2','.','7','.','.','.','.'}
            ,{'.','1','5','.','.','.','.','.','.'}
            ,{'.','.','.','.','.','2','.','.','.'}
            ,{'.','2','.','9','.','.','.','.','.'}
            ,{'.','.','4','.','.','.','.','.','.'}};

    check_existence = sol.isValidSudoku(board);

    cout << "sudoku validation checking ... " << endl;
    cout <<  check_existence << endl;
    cout << "this test must be false " << endl;

    assert(check_existence == false);
    check_existence=false;


    return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		map <int,map <char,int>> rows;
		map <int,map <char,int>> cols;
		map <int,map <char,int>> grid;
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                        rows[i][board[i][j]]++;
                        cols[j][board[i][j]]++;
						int x = (i / 3) * 3;
						int y = j / 3;
                        grid[x + y][board[i][j]]++;
                        if(rows[i][board[i][j]] > 1 || cols[j][board[i][j]] > 1 || grid[x + y][board[i][j]] > 1)
                        	return false;
                }
            }
        }
        return true;
    }
};

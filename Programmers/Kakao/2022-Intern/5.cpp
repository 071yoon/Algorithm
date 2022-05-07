#include <string>
#include <vector>
#include <iostream>
using namespace std;

void shift(vector<vector<int>> &matrix){
    matrix.insert(matrix.begin(), matrix[matrix.size() - 1]);
    matrix.pop_back();
}

void rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int x1 = 0;
    int y1 = 0;
    
    int x2 = n - 1;
    int y2 = 0;
    
    int x3 = n - 1;
    int y3 = m - 1;
    
    int x4 = 0;
    int y4 = m - 1;
    int tmp = matrix[y1][x1];
    for(int j=0; j<x2; j++){
        matrix[j][0] = matrix[j + 1][0];
    }
    for(int j=0; j<y4; j++){
        matrix[n - 1][j] = matrix[n - 1][j + 1];
    }
    for(int j=x2; j>0; j--){
        matrix[j][m - 1] = matrix[j - 1][m - 1];
    }
    for(int j=y4; j>0; j--){
        matrix[0][j] = matrix[0][j - 1];
    }
    
    matrix[0][1] = tmp;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer = rc;   
    for(int i = 0; i < operations.size(); i++){
        if (operations[i] == "Rotate") rotate(answer);
        else shift(answer);
    }
    return answer;
}
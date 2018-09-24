/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> mark;
        vector<string> location;
        for(int i=0; i<n; i++){
            mark.push_back((vector<int>()));
            for(int j=0; j<n; j++){
                mark[i].push_back(0);
            }
            location.push_back("");
            location[i].append(n, '.');
        }
        generate(0, n, location, res, mark);
        return res;
    }
private:
    void put_down_the_queen(int x, int y, vector<vector<int>> &mark){
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        for(int i=1; i<mark.size(); i++){
            for (int j=0; j<8; j++){
                int new_x = x + i * dx[j];
                int new_y = y + i* dy[j];
                if(new_x >=0 && new_x<mark.size() && new_y>=0 && new_y<mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
    void generate(int k, int n, 
                 vector<string> &location,
                 vector<vector<string>> &res,
                 vector<vector<int>> &mark){
        if(k==n){
            res.push_back(location);
            return;
        }
        for(int i=0; i<n; i++){
            if(mark[k][i]==0){
                vector<vector<int>> temp_mark = mark;
                location[k][i] ='Q';
                put_down_the_queen(k, i, mark);
                generate(k+1, n, location, res, mark);
                mark = temp_mark;
                location[k][i] = '.';
            }
        }
    }
};

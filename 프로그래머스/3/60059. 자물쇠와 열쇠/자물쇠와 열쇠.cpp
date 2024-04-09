#include <string>
#include <vector>
//#include <iostream>

using namespace std;

int k, l, new_size;

void rotate_ninety(vector<vector<int>> &key) {
    vector<vector<int>> tmp(k, vector<int>(k, 0));
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < k; j ++) {
            tmp[i][j] = key[k - 1 - j][i];
        }
    }
    key = tmp;
}

bool solve(vector<vector<int>> &board, vector<vector<int>> &key, int x, int y) {
    bool tmp = true;
    
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < k; j ++) {
            board[i + x][j + y] += key[i][j];
        }
    }
    
    for(int i = k - 1; i < k -1 + l; i ++) {
        for(int j = k - 1; j < k -1 +l; j ++) {
            if(board[i][j] != 1) {
                tmp = false;
                break;
            }
            //cout << board[i][j] << " ";
        }
        //cout << "\n";
        if(!tmp) break;
    }
    
    for(int i = 0; i < k; i ++) {
        for(int j = 0; j < k; j ++) {
            board[i + x][j + y] -= key[i][j];
        }
    }
    
    return tmp;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    k = key.size();
    l = lock.size();
    new_size = 2*(k - 1) + l;
    
    vector<vector<int>> board(new_size, vector<int>(new_size, 0));
    
    for(int i = 0; i < l; i ++) {
        for(int j = 0; j < l; j ++) {
            board[i + k - 1][j + k - 1]  = lock[i][j];
        }
    }
    
    for(int rotate = 0; rotate < 4; rotate ++) {
        for(int i = 0; i <= new_size - k; i ++) {
            for(int j = 0; j <= new_size - k; j ++) {
                if(solve(board, key, i, j)) {
                    return true;
                }
            }
        }
        rotate_ninety(key);
    }
    
    return false;
}
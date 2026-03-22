#include<bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<int>>& board, int row, int col, int n){
    for(int i=0; i<row; i++){
        if (board[i][col]) return false;
    }

    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if (board[i][j]) return false;
    }

    for(int i=row, j=col; i>=0 && j<n; i--,j++){
        if (board[i][j]) return false;
    }

    return true;
}

bool solve_n_queen(vector<vector<int>>& board, int row, int n){
    if(row == n) return true;

    for(int col=0; col<n; col++){
        if(is_safe(board, row, col, n)){
            board[row][col] = 1;

            if(solve_n_queen(board, row+1, n)) return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void print_board(vector<vector<int>>& board, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main(){
    int n;
    cout<<"Enter 'n' for n queens problem: ";
    cin>>n; 

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve_n_queen(board, 0, n)){
        print_board(board, n);
    }
    else{
        cout<<"No solution exists!"<<endl;
    }

    return 0;
}
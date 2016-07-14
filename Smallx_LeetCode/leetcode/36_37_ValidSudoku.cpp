#ifdef __36_37__
#include <iostream>
#include <algorithm>

#define N 10
bool flag_row[N][N];
bool flag_col[N][N];
bool flag_box[N][N];

int data[N][N];
bool success;

bool is_set_flag(int x, int y, int key) {
    return flag_row[x][key] || flag_col[y][key] ||
        flag_box[(x / 3) * 3 + y / 3][key];
}

void set_flag(int x, int y, int key, bool flag) {
    flag_row[x][key] = flag;
    flag_col[y][key] = flag;
    flag_box[(x / 3) * 3 + y / 3][key] = flag;
}

void bfs_sudoku(int c, int s_x, int s_y, int total, int size) {
    if (c == total) {
        success = true;
        return;
    }
    if (success)
        return;
    if (s_x >= size || s_y >= size)
        return;
    int i = s_x, j = s_y;
    while (data[i][j]) {
        if (j + 1 >= size) {
            i = s_x + 1;
            j = 0;
            if (i >= size)
                return;
        } else {
            j++;
        }
    }
        
    for (int k = 1; k <= 9; ++k) {
        if (!is_set_flag(i, j, k)) {
            data[i][j] = k;
            set_flag(i, j, k, true);                        
            int n_x = j + 1 >= size ? i + 1 : i;
            int n_y = j + 1 >= size ? 0 : j + 1;
            bfs_sudoku(c + 1, n_x, n_y, total, size);
            if (success)
                return;
            data[i][j] = 0;
            set_flag(i, j, k, false);
        }
    }

    return;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int cnt = 0;
    memset(flag_row, 0, sizeof(flag_row));
    memset(flag_col, 0, sizeof(flag_col));
    memset(flag_box, 0, sizeof(flag_box));
    for (int i = 0; i < boardRowSize; i++)
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == '.') {
                data[i][j] = 0;
                cnt++;
            } else {
                data[i][j] = board[i][j] - '0';
                set_flag(i, j, data[i][j], true);
            }
        }
    success = false;
    bfs_sudoku(0, 0, 0, cnt, boardRowSize);
    
    for (int i = 0; i < boardRowSize; i++)
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == '.') {
                board[i][j] = data[i][j] + '0';
            }
        }
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int cnt = 0;
    if (boardRowSize != boardColSize)
        return false;
    memset(flag_row, 0, sizeof(flag_row));
    memset(flag_col, 0, sizeof(flag_col));
    memset(flag_box, 0, sizeof(flag_box));
    for (int i = 0; i < boardRowSize; i++)
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == '.') {
                data[i][j] = 0;
                cnt++;
            } else {
                data[i][j] = board[i][j] - '0';
                if (is_set_flag(i, j, data[i][j]))
                    return false;
                set_flag(i, j, data[i][j], true);
            }
        }
    //success = false;
    //unavailable = false;
    //bfs_sudoku(data, 0, 0, 0, cnt, boardRowSize);
    //return success;
    return true;
}

char* b[N] = {
    "..9748...",
    "7........",
    ".2.1.9...",
    "..7...24.",
    ".64.1.59.",
    ".98...3..",
    "...8.3.2.",
    "........6",
    "...2759.."
};//aaaa
int main(int argc, char** args) {    
    solveSudoku(b, 9, 9);
    for (int i = 0; i < 9; i++)
        printf("%s\n", b[i]);
    return 0;
}
#endif
/*
    Word Search

    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example 1:


    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
    Example 2:


    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true
    Example 3:


    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false


    Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.


    Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool dfs(int i, int j, int pos, int m, int n, string &word, vector<vector<char>> &board)
{
    if (pos == word.length())
        return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[pos])
        return false;

    char ch = board[i][j];
    board[i][j] = '#';

    // check neighbours
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        bool currAns = dfs(x, y, pos + 1, m, n, word, board);
        if (currAns)
            return true;
    }

    board[i][j] = ch; // backtrack
    return false;
}

// Character Frequency Pruning
bool isPossible(vector<vector<char>> &board, string &word)
{
    unordered_map<char, int> freqBoard, freqWord;
    for (vector<char> row : board)
        for (char c : row)
            freqBoard[c]++;

    for (char c : word)
        freqWord[c]++;

    unordered_map<char, int>::iterator it = freqWord.begin();
    while (it != freqWord.end())
    {
        char c = it->first, f = it->second;
        if (freqBoard[c] < f)
            return false;
        it++;
    }
    return true;
}

bool solveDFS(vector<vector<char>> &board, string word)
{
    int m = board.size(), n = board[0].size();

    // pruning by frequency
    if (!isPossible(board, word))
        return false;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                bool ans = dfs(i, j, 0, m, n, word, board);
                if (ans)
                    return true;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    return solveDFS(board, word);
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool ans = exist(board, word);
    if (ans)
        cout << "Yes, the word exixts in the board" << endl;
    else
        cout << "The word doesn't exixts in the board" << endl;
    return 0;
}
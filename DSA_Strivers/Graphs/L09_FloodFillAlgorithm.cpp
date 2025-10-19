/*
    Flood fill Algorithm

    An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value
    newColor, "flood fill" the image.
    To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel
    of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same
    color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.

    Examples:

    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2.
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same
                 color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because
                 it is not 4-directionally connected to the starting pixel.

    Expected Time Complexity: O(n*m)
    Expected Space Complexity: O(n*m)

    Constraints:
    1 <= n <= m <= 500
    0 <= pixel values <= 10
    0 <= sr <= (n-1)
    0 <= sc <= (m-1)
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int m, int n, int oldColor, int newColor, vector<vector<int>> &image)
{
    if ((x >= 0 && x < m) && (y >= 0 && y < n) && image[x][y] != newColor && image[x][y] == oldColor)
    {
        return true;
    }
    return false;
}

vector<vector<int>> usingBFS(int sr, int sc, int m, int n, int oldColor, int newColor, vector<int> &dx, vector<int> &dy, vector<vector<int>> &image)
{
    image[sr][sc] = newColor;
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            if (isValid(x, y, m, n, oldColor, newColor, image))
            {
                image[x][y] = newColor;
                q.push({x, y});
            }
        }
    }
    return image;
}

void usingDFS(int sr, int sc, int m, int n, int oldColor, int newColor, vector<int> &dx, vector<int> &dy, vector<vector<int>> &image)
{
    image[sr][sc] = newColor;

    for (int i = 0; i < 4; i++)
    {
        int x = sr + dx[i];
        int y = sc + dy[i];

        if (isValid(x, y, m, n, oldColor, newColor, image))
        {
            usingDFS(x, y, m, n, oldColor, newColor, dx, dy, image);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<vector<int>> newImage = image;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    int oldColor = image[sr][sc];
    int m = image.size();
    int n = image[0].size();

    // Using BFS
    // return usingBFS(sr, sc, m, n, oldColor, newColor, dx, dy, newImage);

    // Using DFS
    usingDFS(sr, sc, m, n, oldColor, newColor, dx, dy, newImage);
    return newImage;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> ff = floodFill(image, sr, sc, newColor);

    for (auto row : ff)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
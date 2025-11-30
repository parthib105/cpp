/*
    Maximum Points You Can Obtain from Cards

    There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

    In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

    Your score is the sum of the points of the cards you have taken.

    Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Example 1:

    Input: cardPoints = [1,2,3,4,5,6,1], k = 3
    Output: 12
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
    Example 2:

    Input: cardPoints = [2,2,2], k = 2
    Output: 4
    Explanation: Regardless of which two cards you take, your score will always be 4.
    Example 3:

    Input: cardPoints = [9,7,7,9,7,7,9], k = 7
    Output: 55
    Explanation: You have to take all the cards. Your score is the sum of points of all cards.
    
    Constraints:

    1 <= cardPoints.length <= 10^5
    1 <= cardPoints[i] <= 10^4
    1 <= k <= cardPoints.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // T.C. : O(N^2), S.C. : O(N)
    int maxScoreBrute(vector<int> &cardPoints, int k)
    {
        int maxSum = 0;
        int n = cardPoints.size();

        // Try taking i cards from the start and (k-i) from the end
        for (int i = 0; i <= k; i++)
        {
            int tempSum = 0;

            // Sum of i cards from the front
            for (int j = 0; j < i; j++)
                tempSum += cardPoints[j];

            // Sum of (k - i) cards from the back
            for (int j = 0; j < k - i; j++)
                tempSum += cardPoints[n - 1 - j];

            // Update max if this is a better combination
            maxSum = max(maxSum, tempSum);
        }

        return maxSum;
    }

    int maxScoreOptimal(vector<int> &cardPoints, int k)
    {
        int currSum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++)
            currSum += cardPoints[i];

        int maxScore = currSum;
        for (int i = k - 1; i >= 0; i--)
        {
            currSum -= cardPoints[i];
            currSum += cardPoints[n - k + i];
            maxScore = max(maxScore, currSum);
        }
        return maxScore;
    }

public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // Brute force
        // return maxScoreBrute(cardPoints, k);

        // Optimal
        return maxScoreOptimal(cardPoints, k);
    }
};

int main()
{
    int k = 3;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};

    Solution sol;
    cout << sol.maxScore(cardPoints, k) << endl;
    return 0;
}
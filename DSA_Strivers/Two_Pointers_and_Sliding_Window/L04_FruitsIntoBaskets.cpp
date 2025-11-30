/*
    Fruit Into Baskets

    You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

    You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

    You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
    Given the integer array fruits, return the maximum number of fruits you can pick.

    Example 1:

    Input: fruits = [1,2,1]
    Output: 3
    Explanation: We can pick from all 3 trees.
    Example 2:

    Input: fruits = [0,1,2,2]
    Output: 3
    Explanation: We can pick from trees [1,2,2].
    If we had started at the first tree, we would only pick from trees [0,1].
    Example 3:

    Input: fruits = [1,2,3,2,2]
    Output: 4
    Explanation: We can pick from trees [2,3,2,2].
    If we had started at the first tree, we would only pick from trees [1,2].


    Constraints:

    1 <= fruits.length <= 10^5
    0 <= fruits[i] < fruits.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int totalFruitBrute(vector<int> &fruits)
    {
        unordered_map<int, int> mp;
        int maxFruits = 0, n = fruits.size();
        for (int i = 0; i < n; i++)
        {
            mp.clear();
            int curFruits = 0;
            for (int j = i; j < n; j++)
            {
                mp[fruits[j]]++;

                if (mp.size() > 2)
                    break;

                curFruits++;
            }
            maxFruits = max(maxFruits, curFruits);
        }
        return maxFruits;
    }

    int totalFruitOpt(vector<int> &fruits)
    {
        unordered_map<int, int> mp;
        int l = 0, maxFruit = 0, n = fruits.size();

        for (int r = 0; r < n; r++)
        {
            mp[fruits[r]]++;

            if (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);

                l++;
            }

            maxFruit = max(maxFruit, r - l + 1);
        }
        return maxFruit;
    }

public:
    int totalFruit(vector<int> &fruits)
    {
        // Brute force
        // return totalFruitBrute(fruits);

        // Optimal
        return totalFruitOpt(fruits);
    }
};

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};

    Solution sol;
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}
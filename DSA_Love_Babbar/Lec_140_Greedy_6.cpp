/*
    Fractional Knapsack

    Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value
    in the knapsack. Return a double value representing the maximum value in knapsack.

    Note: Unlike 0/1 knapsack, you are allowed to break the item here. The details of structure/class is defined in the
    comments above the given function.

    Examples :

    Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
    Output: 240.000000
    Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120
                 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes
                60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack.

    Input: n = 2, w = 50, value[] = [60,100], weight[] = [10,20]
    Output: 160.000000
    Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the
                 given capacity of sack.

    Expected Time Complexity : O(n log n)
    Expected Auxilliary Space: O(1)

    Constraints:
    1 <= n <= 10^5
    1 <= w <= 10^9
    1 <= valuei, weighti <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;

    Item(int v, int w)
    {
        this->value = v;
        this->weight = w;
    }
};

static bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}

double fractionalKnapsack(int w, Item arr[], int n)
{
    vector<pair<double, Item>> items;
    for (int i = 0; i < n; i++)
    {
        double frac = double(arr[i].value) / arr[i].weight;
        items.push_back({frac, arr[i]});
    }

    sort(items.begin(), items.end(), cmp);

    double maxItems = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].second.weight > w)
        {
            maxItems += w * items[i].first;
            w = 0;
        }
        else
        {
            maxItems += items[i].second.value;
            w = w - items[i].second.weight;
        }
    }
    return maxItems;
}

int main()
{
    int n = 3, w = 50;
    Item arr[3] = {Item(60, 10), Item(100, 20), Item(120, 30)};
    cout << fractionalKnapsack(w, arr, n) << endl;
    return 0;
}
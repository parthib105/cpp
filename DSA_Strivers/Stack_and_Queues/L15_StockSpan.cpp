/*
    Online Stock Span

    Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

    The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

    For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
    Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
    Implement the StockSpanner class:

    StockSpanner() Initializes the object of the class.
    int next(int price) Returns the span of the stock's price given that today's price is price.
    

    Example 1:

    Input
    ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
    [[], [100], [80], [60], [70], [60], [75], [85]]
    Output
    [null, 1, 1, 1, 2, 1, 4, 6]

    Explanation
    StockSpanner stockSpanner = new StockSpanner();
    stockSpanner.next(100); // return 1
    stockSpanner.next(80);  // return 1
    stockSpanner.next(60);  // return 1
    stockSpanner.next(70);  // return 2
    stockSpanner.next(60);  // return 1
    stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    stockSpanner.next(85);  // return 6
    

    Constraints:

    1 <= price <= 10^5
    At most 104 calls will be made to next.
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(no. of days), S.C. : O(total number of next calls)
class StockSpannerBrute
{
private:
    vector<int> st;
public:
    StockSpannerBrute() {
        
    }
    
    int next(int price) 
    {
        int span = 1, i = st.size() - 1;
        while (i >= 0 && st[i] <= price)
        {
            span += 1;
            i -= 1;
        }
        
        this->st.push_back(price);
        return span;
    }
};

// T.C. : O(2N), S.C. : O(N), N = total number of next calls
class StockSpannerOpt 
{
private:
    stack<pair<int, int>> st;
    int ind;
public:
    StockSpannerOpt() {
        this->ind = -1;
        while (!this->st.empty())
            this->st.pop();
    }
    
    int next(int price) 
    {
        this->ind += 1;
        while (!this->st.empty() && this->st.top().first <= price)
            this->st.pop();

        int ans = this->ind - (this->st.empty() ? -1 : this->st.top().second);
        this->st.push({price, this->ind});
        return ans;
    }
};


int main()
{
    
    return 0;
}
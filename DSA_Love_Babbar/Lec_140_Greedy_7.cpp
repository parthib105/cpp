/*
    Job Sequencing Problem

    Given a set of n jobs where each jobi has a deadline and profit associated with it.

    Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with 
    a job if and only if the job is completed by its deadline.

    Find the number of jobs done and the maximum profit.

    Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time 
          on or before which job needs to be completed to earn the profit.

    Examples :

    Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
    Output: 2 60
    Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

    Input: Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
    Output: 2 127
    Explanation: 2 jobs can be done with maximum profit of 127 (100+27).

    Expected Time Complexity: O(nlogn)
    Expected Auxilliary Space: O(n)

    Constraints:
    1 <= n <= 10^5
    1 <= Deadline,id <= n
    1 <= Profit <= 500
*/

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline

    Job(int i, int d, int p)
    {
        this->id = i;
        this->dead = d;
        this->profit = p;
    } 
};

static bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheculing(Job arr[], int n)
{
    sort(arr, arr + n, cmp);

    int maxDL = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxDL = max(maxDL, arr[i].dead);
    }

    vector<int> schd(maxDL + 1, -1);

    int maxProfit = 0, jobs = 0;
    for (int i = 0; i < n; i++)
    {
        int currDead = arr[i].dead;
        int currProfit = arr[i].profit;
        int currId = arr[i].id;
        for (int k = currDead; k > 0; k--)
        {
            if (schd[k] == -1)
            {
                jobs ++;
                maxProfit += currProfit;
                schd[i] = currId;
                break;
            }
        }
    }

    return {jobs, maxProfit};
}

int main()
{
    int n = 5;
    Job arr[5] = {Job(1, 2, 100), Job(2, 1, 19), Job(3, 2, 27), Job(4, 1, 25), Job(5, 1, 15)};
    vector<int> ans = JobScheculing(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// structure of the job
struct Job
{
    char id;
    int profit;
    int deadline;
};

// this funtion compares two jobs with max profit
bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

//  function for selecting the more profitable jobs
void jobSequencing(Job arr[], int n)
{
    //  sort the jobs according to the highest profits
    sort(arr, arr + n, compare);

    // this arr tracks the number of free slots available and sets false as default (i.e false repreasent available slot )
    char result[5];
    bool slot[5] = {false};

    // iterate over every job and assign the perfect slot for it
    for (int i = 0; i < n; i++)
    {
        /**
         * the logic behind comparing n and current job deadline is the deadline of any job should not be nore than the total number of jobs
         */
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            //  if the slot at j is false it means it is avilable
            if (!slot[j])
            {
                slot[j] = true;
                result[j] = arr[i].id;
                break;
            }
        }
    }

    //  printing the selected jobs
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << result[i] << " ";
        }
    }
}

int main()
{
    Job arr[] = {{'A', 20, 2}, {'B', 15, 2}, {'C', 10, 1}, {'D', 5, 3}, {'E', 1, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);

    jobSequencing(arr, n);
    return 0;
}
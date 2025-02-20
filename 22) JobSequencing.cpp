//Implement job sequencing with deadlines.

#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a job
class Job
{
public:
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit from the job
};

// Function to compare jobs based on profit (in descending order)
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(Job jobs[], int n)
{
    // Step 1: Sort jobs in descending order based on profit
    sort(jobs, jobs + n, compare);

    // Step 2: Find the maximum deadline to create the scheduling array
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Step 3: Create an array to keep track of scheduled jobs
    int* schedule = new int [maxDeadline + 1]; // Using 1-based indexing
    for (int i = 0; i <= maxDeadline; i++)
    {
        schedule[i] = -1; // -1 means the slot is empty
    }

    int totalProfit = 0; // To store the total profit
    int jobsDone = 0;    // To count the number of scheduled jobs

    // Step 4: Try to schedule each job
    for (int i = 0; i < n; i++)
    {
        // Find a free slot from the job's deadline to 1
        for (int j = jobs[i].deadline; j > 0; j--)
        {
            if (schedule[j] == -1)
            { 
                // If slot is free
                schedule[j] = jobs[i].id; // Assign the job
                totalProfit += jobs[i].profit; // Add the profit
                jobsDone++; // Increase job count
                break;
            }
        }
    }

    // Step 5: Display the scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (schedule[i] != -1)
        {
            cout << "J" << schedule[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main()
{
    int n;

    // Taking input from user
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job* jobs = new Job[n];

    cout << "Enter job details (deadline and profit) for each job:\n";
    for (int i = 0; i < n; i++) 
    {
        jobs[i].id = i + 1; // Assigning job ID
        cout << "Job " << jobs[i].id << " -> Deadline: ";
        cin >> jobs[i].deadline;
        cout << "      -> Profit: ";
        cin >> jobs[i].profit;
    }

    // Call the job sequencing function
    jobSequencing(jobs, n);

    return 0;
}

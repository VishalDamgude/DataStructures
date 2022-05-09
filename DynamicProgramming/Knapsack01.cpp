#include <iostream>
#include <cstring>
using namespace std;

int count = 0;
int KnapSack(int capacity, int weight[], int val[], int currentItem, int n)
{
    count++;
    if(currentItem == n || capacity == 0)
    {
        return 0;
    }
    if(weight[currentItem] <= capacity)
    {
        //either include value of currentitem or not, return maximum of profit in both cases
        return max(val[currentItem] + KnapSack(capacity-weight[currentItem], weight, val, currentItem+1, n), 
            KnapSack(capacity, weight, val, currentItem+1, n));

    }
   
    return KnapSack(capacity, weight, val, currentItem+1, n);
}

int KnapSackMemoization(int capacity, int weight[], int val[], int currentItem, int n, int **dp)
{
    count++;
    if(currentItem == n || capacity == 0)
    {
        return 0;
    }
    if(dp[currentItem][capacity] != -1)
        return dp[currentItem][capacity];

    if(weight[currentItem] <= capacity)
    {
        //either include value of currentitem or not, return maximum of profit in both cases
        dp[currentItem][capacity] = max(val[currentItem] + KnapSackMemoization(capacity-weight[currentItem], weight, val, currentItem+1, n, dp), 
            KnapSackMemoization(capacity, weight, val, currentItem+1, n, dp));
        return dp[currentItem][capacity];
    }
   
    dp[currentItem][capacity] = KnapSackMemoization(capacity, weight, val, currentItem+1, n, dp);
    return dp[currentItem][capacity];
}

void DisplayMatrix(int n, int W, int **dp)
{
    cout << endl;
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}


//Here I have changed the base condition
int KnapSackDP(int W, int weight[], int val[], int n)
{
    int **dp;
    dp = new int *[n+1];
    for(int i = 0; i <n+1; i++)
        dp[i] = new int[W+1];

    //Base condition becomes initialization 
    /* if(n == 0 || W == 0)
    {
        return 0;
    } */

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    DisplayMatrix(n, W, dp);

    // i => currentItem, j => currentWeight
    for(int currentItem=1; currentItem<=n; currentItem++)
    {
        for(int currentWeight=1; currentWeight<=W; currentWeight++)
        {
            //Since weight and val array are 0 index, use currentItem -1 to access.
            if(weight[currentItem-1] <= currentWeight)
            {
                dp[currentItem][currentWeight] = max(val[currentItem-1] + dp[currentItem-1][currentWeight-weight[currentItem-1]], 
                                                    dp[currentItem-1][currentWeight]);
            } 
            else {
                dp[currentItem][currentWeight] = dp[currentItem-1][currentWeight];
            }
        }
    }
    DisplayMatrix(n, W, dp);
    return dp[n][W];

}

int main()
{

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 40;
    int n = sizeof(val) / sizeof(val[0]);
    cout << "Max Profit: " << KnapSack(W, wt, val, 0, n) << endl;;
    cout << "Function calls: " << count << endl;
    // int dp[n+1][41];
    // memset(dp, -1, sizeof(dp));

    int **dp;
    dp = new int *[n+1];
    for(int i = 0; i <n+1; i++)
        dp[i] = new int[W+1];
    
    //memset(dp, -1, sizeof(dp));
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            dp[i][j] = -1;
        }
    }
    // count = 0;
    // cout << "Max Profit: " << KnapSackMemoization(W, wt, val, 0, n, dp) << endl;;
    // cout << "Function calls: " << count << endl;

    cout << "Max Profit: " << KnapSackDP(W, wt, val, n) << endl;;
    return 0;
}
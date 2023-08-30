#include <bits/stdc++.h>

using namespace std;

int solveRec(vector<int> &coins, int ammount)
{
    // base case
    if (ammount == 0)
        return 0;

    if (ammount < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {

        int ans = solveRec(coins, ammount - coins[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    return mini;
}

// use DP array in coin chnage problem
int solveMem(vector<int> &coins, int ammount, vector<int> &dp)
{
    // base case
    if (ammount == 0)
    {
        dp[0] = 0;
        return 0;
    }

    // 2nd edge case
    if (ammount < 0)
    {

        return INT_MAX;
    }
    if (dp[ammount] != -1)
    {
        return dp[ammount];
    }
    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {

        int ans = solveMem(coins, ammount - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[ammount] = mini;
}

int minimumelement(vector<int> &coins, int ammount)
{
    vector<int> dp(ammount + 1, -1);

    // int result = solveRec(coins, ammount);
    int result = solveMem(coins, ammount,dp);


    if (result != INT_MAX)
    {
        return result;
    }
    else
    {
        return -1;
    }
}

int main()
{

    vector<int> coins;
    int n_coin;
    cin >> n_coin;
    while (n_coin--)
    {
        int n;
        cin >> n;

        coins.push_back(n);
    }
    int ammount;
    cin >> ammount;

    cout << minimumelement(coins, ammount) << endl;

    return 0;
}

//[1,2,3] ammount 5
// 1- 1,4 |1,3|2,2|3,1
// 2- 2,3 |1,2|2,1|3,0|--condision hist find ans;
// 3-3,2

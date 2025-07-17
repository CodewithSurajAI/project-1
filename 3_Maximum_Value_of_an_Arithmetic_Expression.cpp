#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;
vector<int> operands;
vector<char> operators;
vector<vector<long long>> minValues;
vector<vector<long long>> maxValues;

pair<long long, long long> minAndmax(int i, int j)
{
    long long minVal = INT_MAX, maxVal = INT_MIN;
    for (int k = i; k < j; k++)
    {
        long long a, b, c, d;
        switch (operators[k])
        {
        case '+':
            a = maxValues[i][k] + maxValues[k + 1][j];
            b = maxValues[i][k] + minValues[k + 1][j];
            c = minValues[i][k] + maxValues[k + 1][j];
            d = minValues[i][k] + minValues[k + 1][j];
            break;
        case '-':
            a = maxValues[i][k] - maxValues[k + 1][j];
            b = maxValues[i][k] - minValues[k + 1][j];
            c = minValues[i][k] - maxValues[k + 1][j];
            d = minValues[i][k] - minValues[k + 1][j];
            break;
        case '*':
            a = maxValues[i][k] * maxValues[k + 1][j];
            b = maxValues[i][k] * minValues[k + 1][j];
            c = minValues[i][k] * maxValues[k + 1][j];
            d = minValues[i][k] * minValues[k + 1][j];
            break;
        }
        minVal = min(minVal, min(a, min(b, min(c, d))));
        maxVal = max(maxVal, max(a, max(b, max(c, d))));
    }
    return make_pair(minVal, maxVal);
}

long long placing_parentheses()
{
    for (int i = 1; i < operands.size(); i++)
    {
        minValues[i][i] = operands[i];
        maxValues[i][i] = operands[i];
    }
    for (int s = 1; s < operands.size() - 1; s++)
    {
        for (int i = 1; i < operands.size() - s; i++)
        {
            int j = i + s;
            pair<long long, long long> tempPair = minAndmax(i, j);
            minValues[i][j] = tempPair.first;
            maxValues[i][j] = tempPair.second;
        }
    }
    return maxValues[1].back();
}

int main()
{
    string expression;
    cin >> expression;
    operators.push_back(0);
    operands.push_back('0');
    for (int i = 0; i < expression.size(); i++)
    {
        if (i % 2 != 0)
            operators.push_back(expression[i]);
        else
            operands.push_back(expression[i] - '0');
    }
    minValues = vector<vector<long long>>(operands.size(), vector<long long>(operands.size()));
    maxValues = vector<vector<long long>>(operands.size(), vector<long long>(operands.size()));

    cout << placing_parentheses();

    return 0;
}
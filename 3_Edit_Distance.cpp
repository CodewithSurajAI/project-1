#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
#include <limits>
#include <sstream>
#include <limits.h>
#include <float.h>
#include <stack>
using namespace std;
int edit_distance(string string_A, string string_B)
{
    vector<vector<int>> Distance(string_A.size() + 1, vector<int>(string_B.size() + 1));
    for (int i = 0; i <= string_A.size(); i++)
        Distance[i][0] = i;
    for (int j = 0; j <= string_B.size(); j++)
        Distance[0][j] = j;
    for (int i = 1; i <= string_A.size(); i++)
    {
        for (int j = 1; j <= string_B.size() ; j++)
        {
            int inserstion = Distance[i][j - 1] + 1;
            int Deletion = Distance[i - 1][j] + 1;
            int match = Distance[i - 1][j - 1];
            int mismatch = Distance[i - 1][j - 1] + 1;
            if (string_A[i-1] == string_B[j-1])
                Distance[i][j] = min(match, min(inserstion, Deletion));
            else
                Distance[i][j] = min(mismatch, min(inserstion, Deletion));
        }
    }
    return Distance[string_A.size()][string_B.size()];
}
int main()
{
    string string_A, string_B;
    cin >> string_A >> string_B;
    cout << edit_distance(string_A, string_B);
    return 0;
}
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
int edit_distance(vector<int> vec_A, vector<int> vec_B)
{
    vector<vector<int>> Distance(vec_A.size() + 1, vector<int>(vec_B.size() + 1));
    //Longest common subsequence with empty string is zero
    for (int i = 0; i <= vec_A.size(); i++)
        Distance[i][0] = 0;
    for (int j = 0; j <= vec_B.size(); j++)
        Distance[0][j] = 0;
    
    for (int i = 1; i <= vec_A.size(); i++)
    {
        for (int j = 1; j <= vec_B.size(); j++)
        {
            if (vec_A[i - 1] == vec_B[j - 1])
                Distance[i][j] = Distance[i - 1][j - 1] + 1;
            else
                Distance[i][j] = max(Distance[i][j - 1], Distance[i - 1][j]);
        }
    }
    return Distance[vec_A.size()][vec_B.size()];
}
int main()
{
    int sizeA, sizeB;

    cin >> sizeA;
    vector<int> vec_A(sizeA);
    for (int &x : vec_A)
        cin >> x;

    cin >> sizeB;
    vector<int> vec_B(sizeB);
    for (int &x : vec_B)
        cin >> x;
    cout << edit_distance(vec_A, vec_B);
    return 0;
}
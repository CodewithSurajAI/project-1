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
#include <float.h>
#include <ctime>
using namespace std;
bool compareX(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first < p2.first;
}
bool compareY(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}

double calculateDistance(pair<int, int> &p1, pair<int, int> &p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
double getMinDistance(vector<pair<int, int>> points)
{
    double minD = DBL_MAX;
    for (auto it1 = points.begin(); it1 != points.end(); it1++)
        for (auto it2 = it1 + 1; it2 != points.end(); it2++)
            minD = min(calculateDistance(*it1, *it2), minD);
    return minD;
}
double getMinDistanceOverlap(vector<pair<int, int>> points, double D)
{
    double minD = DBL_MAX;
    for (auto it1 = points.begin(); it1 != points.end(); it1++)
        for (auto it2 = it1 + 1; it2 != points.end() && it2 != it1 + 8 && abs((*it2).second - (*it1).second) < D; it2++)
            minD = min(calculateDistance(*it1, *it2), minD);
    return minD;
}
double closestPoints(vector<pair<int, int>> points)
{
    if (points.size() <= 3)
        return getMinDistance(points);
    int midIndex = points.size() / 2;
    int middle = points[midIndex].first;

    double minLeft = closestPoints(vector<pair<int, int>>(points.begin(), points.begin() + midIndex));
    double minRight = closestPoints(vector<pair<int, int>>(points.begin() + midIndex + 1, points.end()));

    double MinDistance = min(minLeft, minRight);

    vector<pair<int, int>> middleSecion;
    for (auto it = points.begin(); it != points.end(); it++)
        if (abs((*it).first - middle) < MinDistance)
            middleSecion.push_back(*it);
    sort(middleSecion.begin(), middleSecion.end(), compareY);
    double middleMinDistance = getMinDistanceOverlap(middleSecion, MinDistance);
    return min(middleMinDistance, MinDistance);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points)
        cin >> p.first >> p.second;
    sort(points.begin(), points.end(), compareX);
    cout.precision(5);
    cout << fixed << closestPoints(points);
    return 0;
}

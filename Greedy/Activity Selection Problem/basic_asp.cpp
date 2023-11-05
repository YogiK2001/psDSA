#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareActivities(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

/**
 * @brief Selects a set of non-overlapping activities with maximum count.
 *
 * @param activities A vector of pairs representing the start and end times of activities.
 * @return vector<pair<int, int>> A vector of pairs representing the start and end times of selected activities.
 */
vector<pair<int, int>> activitySelection(vector<pair<int, int>> &activities)
{
    sort(activities.begin(), activities.end(), compareActivities);

    vector<pair<int, int>> selectedActivities;
    selectedActivities.push_back(activities[0]);
    int previousActivityEndTime = activities[0].second;

    for (int i = 1; i < activities.size(); ++i)
    {
        if (activities[i].first >= previousActivityEndTime)
        {
            selectedActivities.push_back(activities[i]);
            previousActivityEndTime = activities[i].second;
        }
    }

    return selectedActivities;
}

int main()
{
    vector<pair<int, int>> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}};
    vector<pair<int, int>> selectedActivities = activitySelection(activities);

    cout << "Selected Activities: ";
    for (const auto &activity : selectedActivities)
    {
        cout << "(" << activity.first << ", " << activity.second << ") ";
    }
    cout << endl;

    return 0;
}

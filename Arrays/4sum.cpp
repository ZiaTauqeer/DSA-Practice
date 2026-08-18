#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++) {

            if (j != (i + 1) && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l) {

                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target) {

                    vector<int> temp = {
                        nums[i],
                        nums[j],
                        nums[k],
                        nums[l]
                    };

                    ans.push_back(temp);

                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                        k++;

                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }

                else if (sum < target) {
                    k++;
                }

                else {
                    l--;
                }
            }
        }
    }

    return ans;
}


int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "\nQuadruplets whose sum is " << target << ":\n";

    if (result.empty()) {
        cout << "No quadruplets found." << endl;
    }
    else {
        for (int i = 0; i < result.size(); i++) {

            cout << "[ ";

            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }

            cout << "]" << endl;
        }
    }

    return 0;
}
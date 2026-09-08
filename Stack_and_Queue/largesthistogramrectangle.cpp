#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // left[i]  = index of nearest smaller element on the left
        // right[i] = index of nearest smaller element on the right
        vector<int> left(n), right(n);

        stack<int> st;


        // =====================================================
        // FIND NEAREST SMALLER ELEMENT TO THE LEFT
        // =====================================================

        for (int i = 0; i < n; i++) {

            // Remove elements that are greater than or equal
            // to the current height.
            //
            // They cannot be the nearest smaller element
            // for heights[i].
            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, there is no smaller element
            // on the left.
            //
            // Otherwise, the top of the stack is the nearest
            // smaller element.
            left[i] = st.empty() ? -1 : st.top();

            // Store the current index for future elements.
            st.push(i);
        }


        // Clear the stack before finding smaller elements
        // on the right.
        while (!st.empty()) {
            st.pop();
        }


        // =====================================================
        // FIND NEAREST SMALLER ELEMENT TO THE RIGHT
        // =====================================================

        for (int i = n - 1; i >= 0; i--) {

            // Remove elements that are greater than or equal
            // to the current height.
            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, there is no smaller element
            // on the right.
            //
            // We use n because n represents the position
            // just after the last element.
            right[i] = st.empty() ? n : st.top();

            // Store the current index.
            st.push(i);
        }


        // =====================================================
        // CALCULATE MAXIMUM RECTANGLE
        // =====================================================

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            // Width of the rectangle:
            //
            // left[i]  = first smaller element on the left
            // right[i] = first smaller element on the right
            //
            // So the valid width is:
            //
            // right[i] - left[i] - 1
            int width = right[i] - left[i] - 1;

            // Height = heights[i]
            // Width  = calculated above
            //
            // Area = height * width
            int area = heights[i] * width;

            // Keep the largest area found so far.
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};


int main() {

    Solution sol;

    // Test case
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Largest Rectangle Area: "
         << sol.largestRectangleArea(heights)
         << endl;

    return 0;
}
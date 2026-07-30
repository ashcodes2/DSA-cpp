class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Max-heap storing pair<abs(num - x), num>
        priority_queue<pair<int, int>> maxHeap;

        for (int num : arr) {
            maxHeap.push({abs(num - x), num});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        // The problem requires output sorted in ascending order
        sort(result.begin(), result.end());
        return result;
    }
};
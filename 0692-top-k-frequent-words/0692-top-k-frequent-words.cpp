class Solution {
public:
    struct Comparator {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first) {
                return a.first > b.first; // Min-heap based on frequency
            }
            return a.second < b.second;   // Max-heap based on lexicographical order for tie-breaking
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (const string& word : words) {
            freqMap[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> minHeap;

        for (const auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.top().second;
            minHeap.pop();
        }

        return result;
    }
};
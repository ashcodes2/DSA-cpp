class Solution {
public:
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        int next = (i + nums[i]) % n;
        if (next < 0) {
            next += n;
        }
        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continue;
            }

            int slow = i;
            int fast = i;
            bool isForward = nums[i] > 0;

            while (true) {
                int nextSlow = getNext(nums, slow);
                if ((nums[nextSlow] > 0) != isForward) {
                    break;
                }

                int nextFast = getNext(nums, fast);
                if ((nums[nextFast] > 0) != isForward) {
                    break;
                }

                int nextFast2 = getNext(nums, nextFast);
                if ((nums[nextFast2] > 0) != isForward) {
                    break;
                }

                slow = nextSlow;
                fast = nextFast2;

                if (slow == fast) {
                    if (slow == getNext(nums, slow)) {
                        break;
                    }
                    return true;
                }
            }

            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == isForward) {
                int next = getNext(nums, curr);
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};
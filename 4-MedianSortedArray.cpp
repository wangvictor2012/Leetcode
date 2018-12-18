#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        vector<int> nums;
        Merge(nums1, nums2, nums);
        size_t count = nums.size();
        if  (count % 2 != 0) {
            return (nums[count / 2]);
        } else {
            return (nums[count/2-1]+ nums[count/2]) / 2.;
        }
    }

    void Merge(vector<int> &nums1, vector<int> &nums2, vector<int> &res) {
        int i = 0, j = 0;
        int size1 = static_cast<int>(nums1.size());
        int size2 = static_cast<int>(nums2.size());
        while (i < size1 || j < size2) {
            if (i == size1) {
                res.insert(res.end(), nums2.begin() + j, nums2.end());
                return;
            }

            if (j == size2) {
                res.insert(res.end(), nums1.begin() + i, nums1.end());
                return;
            }

            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i ++]);
            } else {
                res.push_back(nums2[j ++]);
            }
        }
    }
};
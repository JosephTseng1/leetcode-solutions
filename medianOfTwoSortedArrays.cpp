class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int num = nums1.size() + nums2.size();
        if (num == 0) {
            return 0.0;
        }
        int array[num];
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                array[k] = nums1[i];
                i++;
            } else {
                array[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < n) {
            array[k] = nums1[i];
            i++;
            k++;
        }
        while (j < m) {
            array[k] = nums2[j];
            j++;
            k++;
        }
        if (num % 2) {
            return array[num/2];
        }
        return (array[num/2] + array[(num/2)-1])/2.0;
    }
};

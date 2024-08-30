double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array
    if (nums1Size> nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int imin = 0, imax = nums1Size, half_len = (nums1Size +nums2Size+ 1) / 2;
    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        if (i < nums1Size && nums1[i] < nums2[j - 1]) {
            imin = i + 1;  // i is too small, must increase it
        } else if (i > 0 && nums1[i - 1] > nums2[j]) {
            imax = i - 1;  // i is too big, must decrease it
        } else {  // i is perfect
            int max_of_left;
            if (i == 0) { 
                max_of_left = nums2[j - 1]; 
            } else if (j == 0) { 
                max_of_left = nums1[i - 1]; 
            } else { 
                max_of_left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1]; 
            }

            if ((nums1Size + nums2Size) % 2 == 1) {
                return max_of_left;  // Odd case
            }

            int min_of_right;
            if (i == nums1Size) { 
                min_of_right = nums2[j]; 
            } else if (j == nums2Size) { 
                min_of_right = nums1[i]; 
            } else { 
                min_of_right = nums1[i] < nums2[j] ? nums1[i] : nums2[j]; 
            }

            return (max_of_left + min_of_right) / 2.0;  // Even case
        }
    }

    return 0.0;  // If input arrays are not sorted, which is not expected in this problem
}



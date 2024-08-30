int maxArea(int* height, int heightSize) {
        int left = 0;
    int right = heightSize - 1;
    int max_area = 0;
    while (left < right) {
        int current_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = current_height * (right - left);

        if (current_area > max_area) {
            max_area = current_area;
        }

        // Move the pointer that points to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}
#define MAX_WIDTH 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int* result = (int*)malloc(2 * sizeof(int)); // Allocate memory for result[2]
    int lines = 1, currentWidth = 0; // Start with one line

    for (int i = 0; s[i] != '\0'; i++) {
        int charWidth = widths[s[i] - 'a']; // Get the width of the current character

        if (currentWidth + charWidth > MAX_WIDTH) {
            lines++;  // Move to the next line
            currentWidth = charWidth; // Start new line with current character
        } else {
            currentWidth += charWidth; // Add character width to current line
        }
    }
result[0] = lines;      // Total lines used
result[1] = currentWidth; // Width of the last line
*returnSize = 2;        // Set returnSize to 2
return result;
}
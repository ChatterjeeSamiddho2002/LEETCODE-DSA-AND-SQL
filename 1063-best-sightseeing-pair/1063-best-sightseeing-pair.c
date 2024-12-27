int maxScoreSightseeingPair(int* values, int valuesSize) {
     int maxScore = 0;
    int maxValuesPlusI = values[0] + 0;  // Initial value for values[i] + i
    
    // Start from j=1 since we need i < j
    for (int j = 1; j < valuesSize; j++) {
        // Calculate current score using maxValuesPlusI from previous iterations
        int currentScore = maxValuesPlusI + values[j] - j;
        
        // Update maximum score if current score is higher
        if (currentScore > maxScore) {
            maxScore = currentScore;
        }
        
        // Update maxValuesPlusI if current position gives higher value
        if (values[j] + j > maxValuesPlusI) {
            maxValuesPlusI = values[j] + j;
        }
    }
    
    return maxScore;
}
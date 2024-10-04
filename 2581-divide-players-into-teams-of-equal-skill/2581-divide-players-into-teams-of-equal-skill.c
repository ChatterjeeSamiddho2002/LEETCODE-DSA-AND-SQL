int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
long long dividePlayers(int* skill, int skillSize) {
    long long totalSkill = 0;
    for (int i = 0; i < skillSize; i++) {
        totalSkill += skill[i];
    }
    
    // Total teams are skillSize / 2
    int numTeams = skillSize / 2;
    
    // Target sum for each team
    if (totalSkill % numTeams != 0) {
        return -1;  // Not possible to divide teams equally
    }
    int targetSum = totalSkill / numTeams;
    
    // Sort the skill array
    qsort(skill, skillSize, sizeof(int), compare);
    
    long long totalChemistry = 0;
    int i = 0, j = skillSize - 1;
    
    // Two-pointer approach to form pairs
    while (i < j) {
        // Check if the sum of the current pair matches the target sum
        if (skill[i] + skill[j] != targetSum) {
            return -1;  // Impossible to form a valid team
        }
        // Add the chemistry of the current pair
        totalChemistry += (long long)skill[i] * skill[j];
        i++;
        j--;
    }
    
    return totalChemistry;
}
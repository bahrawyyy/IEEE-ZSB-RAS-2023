int lengthOfLongestSubstring(char *s) {
    int freqArray[256] = {0}; 
    int maxLength = 0;
    int i = 0;
    
    for (int j = 0; s[j] != '\0'; j++) {
        while (freqArray[s[j]] > 0) {
            freqArray[s[i]]--;
            i++;
        }
        freqArray[s[j]]++;
        int currentLength = j - i + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}
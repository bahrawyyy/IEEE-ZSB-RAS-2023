#include <stdio.h>
#include <string.h>


// This function is to check if the string from index start to index end is palindromic or not
bool checkIfPalindromic(char *s,int start, int end)
{
    while(start<=end)
    {
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void copySubstring(const char *s, int start, int end, char *dest)
{
    int index = 0;
    for (int i = start; i <= end; i++)
    {
        dest[index++] = s[i];
    }
    dest[index] = '\0'; // Null-terminate the destination substring
}


char* longestPalindrome(char* s) {
    int n = strlen(s);    
    int MaxLength = 0;
    int StartingIndex = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(checkIfPalindromic(s,i,j))
            {
                if(j-i+1 > MaxLength){
                    MaxLength = j-i+1;
                    StartingIndex = i;
                }
            }
        }
    }
    char* result = (char*)malloc((MaxLength + 1) * sizeof(char));
    if (result == NULL)
    {
        // Memory allocation failed
        return NULL;
    }

    int index = 0;
    for (int i = StartingIndex; i <= StartingIndex + MaxLength - 1; i++)
    {
        result[index] = s[i];
        index++;
    }
    result[index] = '\0'; // Null-terminate the result string
    return result;

}
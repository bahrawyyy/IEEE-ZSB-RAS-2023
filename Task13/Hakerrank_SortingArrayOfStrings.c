#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// A function to return the number of distinct characters in the string
int charactersCounter(const char *s)
{
    int count[126] = {0};   // Frequency array to hold the count of each character
    int countDistinct = 0;
    if(s == NULL)
        return -1;
    int n = 0;
    while(*s != '\0')
    {
        if(!count[*s]){
            count[*s]++;
            countDistinct++;
        }
        s++;
    }
    return countDistinct;
}



int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int countDifference = charactersCounter(a)-charactersCounter(b);
    return (countDifference ? countDifference : lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
    int lengthDiffernce = strlen(a) - strlen(b);
    return (lengthDiffernce ? lengthDiffernce : lexicographic_sort(a, b));
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* p = arr[i];
        while(j > 0){
            if((*cmp_func)(arr[j-1],p) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = p;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
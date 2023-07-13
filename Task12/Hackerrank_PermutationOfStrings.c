#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char **s,int i, int j)
{
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp; 
}



// Reverseing the order of strings in the array s from index start to index end

void reverseString(char **s, int start, int end)
{
    while(start<end)
    {
        swap(s,start++,end--);
    }
}



int next_permutation(int n, char **s)
{
	int i,j;
    // Loop from the last string to the first one
    for(i=n-2;i>=0;i--)
    {
        // If the next string is greater than the current one
        // Then there exists a lexicographically greater permutation
        if(strcmp(s[i+1], s[i]) > 0){
            // Find the minimum string
            for(j=n-1;j>i;j--)
            {
                if(strcmp(s[j], s[i]) > 0)
                {
                    // Swap these two elements
                    swap(s,i,j);
                    reverseString(s, i+1, n-1);
                    return 1;
                }
            }
        }
    }
    return 0;

}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
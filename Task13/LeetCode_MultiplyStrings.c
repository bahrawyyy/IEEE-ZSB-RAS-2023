char * multiply(char * a, char * b)
{
    if(strcmp(a,"0") == 0 || strcmp(b,"0") == 0)
        return "0";

    if(strcmp(a,"1") == 0)
        return b;

    if(strcmp(b,"1") == 0)
        return a;

    int m = strlen(a), n = strlen(b);
    int* Product = (int*)calloc(m+n,sizeof(int));
    int i = m - 1, j;
    int value_1 , value_2, Power_Factor = 0, product, carry, k;
    char* Result = (char*)malloc((m+n+1)*sizeof(char));
    int flag = 0;

    while(i >= 0)
    {
        value_1 = *(a + i) - '0';
        j = n - 1;
        carry = 0;
        k = m + n - Power_Factor - 1;
        while(j >= 0 || carry != 0)
        {
            value_2 = j >= 0 ? *(b + j)-'0' : 0;
            product = value_1*value_2 + carry + *(Product + k);
            *(Product + k) = product % 10;
            carry = product / 10;
            
            k--;
            j--;
        }
        i--;
        Power_Factor++;
    }
    j = 0;
    for(i = 0; i < (m+n); i++)
    {
        if(*(Product + i) == 0 && flag == 0) 
        {
        continue; 
        }
        else{
            flag = 1;
            *(Result + j++) = (char)(*(Product + i)+'0');
        }
    }
    free(Product);
    *(Result + j) = '\0';
return Result;
}
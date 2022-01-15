#include<stdio.h>
#include<string.h>
#define size 200
int longest_palindrom_substring(char *str);
void output(char *str, int start, int end);



void main(){
	
	char str[size];
	
	printf("\nEnter string: ");
	scanf("%s",str);
	
	longest_palindrom_substring(str);
	
	return;
}

int longest_palindrom_substring(char *str)
{
    
    int i,j,k, flag, len;
    int n = strlen(str);
    if(n<=1)   //corner case is cover here.
    {
    	printf("longest palindrom is:%s",str);
    	return 0;
	}

    int maxlen = 1, init = 0,end;		// initial maximum length as 1

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            flag = 1;
			
			len = j - i + 1;
            for (k = 0; k < len / 2; k++)	// Check palindrome
                if (str[i + k] != str[j - k])
                    flag = 0;

            if (flag && len > maxlen) {		            // If palindrome, then check for length
                init = i;
                maxlen = len;
            }
        }
    }
	end=init+maxlen-1;	
    output(str, init,end);
    return 0;
}

void output(char *str, int start, int end)
{	
	int i;
	printf("\n....Longest palindromic substring is :");
    for (i = start; i <= end; ++i)
        printf("%c",str[i]);
}



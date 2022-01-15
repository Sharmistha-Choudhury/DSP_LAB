//........................RADIX SORT.....................................
#include<stdio.h>
#define size 10
void radix_sort (int *arr, int n);
int max_element (int *arr, int n);


int main (){
   int i, n, arr[size];
   printf ("Enter the number of elements: ");
   scanf ("%d", &n);
   printf ("\nEnter elements: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &arr[i]);
   }
   radix_sort (arr, n);
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
   {
   
      printf ("%d ", arr[i]);
   }
   return 0;
}

void radix_sort (int *arr, int n)
{
   int bucket[10][size], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass,div;
   lar = max_element(arr, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 1; pass <=NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
        div=arr[i]/divisor;
        r=div%10;
        bucket[r][bucket_cnt[r]] = arr[i];
         bucket_cnt[r] += 1;
      }
      //After pass result is stored into array
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            arr[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
   }
}
int max_element (int *arr, int n)
{
   int max = arr[0];
   int i;
   for (i = 1; i < n; i++)
      if (arr[i] > max)
         max = arr[i];
   return max;
}

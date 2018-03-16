#include<stdio.h>
#include<stdlib.h>

int arr[1001]={0};

void combnum(int orz, int a, int n, int k, int *A, FILE *ofp)
{
  int b,c;
  if(orz==k)
  {
      for(c=0 ; c<k ; c++){
        //螢幕印出結果
        printf("%d ", arr[c]);
        //寫入檔案結果
        fprintf(ofp, "%d ",arr[c]);  
      }
      printf("\n");
      putc('\n',ofp);
  }
  else
  {
    	for(b=a;b<n;b++)
        {
           arr[orz]=A[b];
           combnum(orz+1, b+1, n, k, A,ofp);
        }
  }

}

int main(int argc, char *argv[])
{
	int n, k, i;
	n = atoi(argv[1]);
	k = atoi(argv[2]);
	FILE *ofp;
  ofp = fopen("output.txt" , "w");
	int *A = NULL;
    A = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; ++i)
    {
    	A[i] = 0;
    }
    for (i = 0; i < n; ++i)
    {
    	scanf("%d", &A[i]);
    }
    for (i = 0; i < k; ++i)
    {
    	arr[i] = 0;
    }
    fprintf(ofp, "%d ", n);
    fprintf(ofp, "%d ", k);
    putc('\n',ofp);
    for (i = 0; i < n; ++i)
    {
      fprintf(ofp, "%d ", A[i]);
    }
    putc('\n',ofp);
    putc('\n',ofp);
    combnum(0,0,n,k,A, ofp);
    fclose(ofp);
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 300
int main(char* fileName)
{
  // Open file
  FILE * fp;
  fileName = "Sequence";
  fp = fopen(fileName, "r");
  if(fp == NULL)
  {
      printf("Unable to open file '%s'.\nExiting.", fileName);
      return -1;
  }

  // Alllocate memory for strings
  char* A = malloc(sizeof(char)*(MAX_LENGTH));
  char* B = malloc(sizeof(char)*(MAX_LENGTH));

  // Get strings
  fscanf(fp, "%s", A);
  fscanf(fp, "%s", B);

  // Get lengths of strings
  int A_length, B_length;
  for(A_length=0;  A[A_length] != NULL;A_length++);
  for(B_length=0;  B[B_length] != NULL;B_length++);
  printf("A_length: %d\nB_length: %d\n", A_length, B_length);

  // Allocate memory for scoring matrix
  int* scoring = malloc(sizeof(int)*A_length+1*B_length+1);

  // Fill first row and column with zeroes
  int i, j, k;
  for(i=0;i<A_length;i++) scoring[i] = 0;
  for(i=0;i<B_length;i++) scoring[i*(A_length+1)] = 0;

  // Allocate memory for traceback matrix
  int* traceback = malloc(sizeof(scoring));

  // Fill traceback matrix with zeroes
  for(i=0;i<(A_length+1)*(B_length+1);i++) traceback[i] = 0;

  // For each cell:
  int largestCell = 0;
  int curPos, index;
  for(i=1;i<=B_length;i++)
  {
      for(j=1;j<=A_length;j++)
      {

          // Get diagonal(top left) value
          int diag = scoring[(i-1)*(A_length+1) + j-1] + (A[i] == B[j])?3:-3;

          // Get left value
          for(k=0;scoring[i*(A_length+1)+j-k]==0 && k < j;k++);
          int left = scoring[i*(A_length+1)+j-(k-1)]-2*(k-1);

          // Get top value
          for(k=0;scoring[(i-k)*(A_length+1)+j]==0 && k < i;k++);
          int top = scoring[(i-(k-1))*(A_length+1)+j]-2*(k-1);

          // Find the max of the above three values and
          //  fill traceback matrix
          // 0 for first row/column or if 0 was max value
          // 1 if diagonal was max value
          // 2 if left was max value
          // 3 if top was max value
          int max = 0;
          if(diag > max){
            max = diag;
            traceback[i*(A_length+1) + j] = 1;
          }
          if(left > max){
            max = left;
            traceback[i*(A_length+1) + j] = 2;
          }
          if(top > max){
            max = top;
            traceback[i*(A_length+1) + j] = 3;
          }

          // If current cell is larger than current largestCell, update largestCell
          if(max > scoring[largestCell]) largestCell = i*(A_length+1) + j;
          printf("%d ", max);
        }
        printf("\n");
      }

  // Traceback, starting from largestCell using the traceback matrix
  curPos = largestCell;
  char* Sol1 = malloc(sizeof(char) * (A_length+B_length));
  char* Sol2 = malloc(Sol1);
  while(scoring[curPos]!=0)
  {
    if(traceback[curPos] == 1)
    {
      Sol1[index] = A[curPos%(A_length+2)];
      Sol2[index] = B[curPos/(A_length+1)];
      curPos -= A_length+2;
    }
    else if(traceback[curPos] == 2)
    {
      Sol1[index] = A[curPos%(A_length+1)];
      Sol2[index] = '-';
      curPos -= 1;
    }
    else if(traceback[curPos] == 3)
    {
      Sol1[index] = '-';
      Sol2[index] = B[curPos/(A_length+1)];
      curPos -= A_length+1;
    }
    else break;
  }

  //print solutions
  for(i=A_length+B_length; i>0;i--)
  {
    if(Sol1[i] != NULL) printf("%c", Sol1[i]);
  }
  printf("\n");
  for(i=A_length+B_length; i>0;i--)
  {
    if(Sol2[i] != NULL) printf("%c", Sol2[i]);
  }
  free(A);
  free(B);
  free(scoring);
  free(traceback);
  free(Sol2);
  free(Sol1);
}

#include <stdio.h>
int main(){
  FILE *in_file;
  FILE *out_file;

  //open file and make sure it is valid
  in_file = fopen("in_matrix.txt", "r");
  if(in_file == NULL)
    return -1;

  //creates a matrix "matrix" whose dimensions are the first 2 numbers
  int m, n, temp;
  fscanf(in_file, "%d %d", &m, &n);
  int matrix[m][n];

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      fscanf(in_file, " %d", &matrix[i][j]);
    }
  }

  fclose(in_file);
  out_line = fopen("out_matrix.txt", "r");
  fprintf(out_file, "%d %d", n, m);
  int temp[m][n];
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      temp[i][j] = matrix[j][i];
    }
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      fprintf(out_file, " %d", temp[i][j]);
    }
  }
  fclose(out_line);
  return 0;
}

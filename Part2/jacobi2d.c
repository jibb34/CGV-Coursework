#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // create file to open
  FILE *csv;
  csv = fopen("correct.csv", "w+");
  int m;
  int n;
  double tol; // = 0.0001;

  int i, j, iter;

  m = atoi(argv[1]);
  n = atoi(argv[2]);
  tol = atof(argv[3]);

  double t[m + 2][n + 2], tnew[m + 1][n + 1], diff, difmax;

  // printf("%d %d %lf\n", m, n, tol);

  // initialise temperature array
  for (i = 0; i <= m + 1; i++) {
    for (j = 0; j <= n + 1; j++) {
      t[i][j] = 30.0;
    }
  }

  // fix boundary conditions
  for (i = 1; i <= m; i++) {
    t[i][0] = 15.0;
    t[i][n + 1] = 60.0;
  }
  for (j = 1; j <= n; j++) {
    t[0][j] = 47.0;
    t[m + 1][j] = 100.0;
  }

  // main loop
  iter = 0;
  difmax = 1000000.0;
  while (difmax > tol) {
    iter++;

    // update temperature for next iteration
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        tnew[i][j] =
            (t[i - 1][j] + t[i + 1][j] + t[i][j - 1] + t[i][j + 1]) / 4.0;
      }
    }

    // work out maximum difference between old and new temperatures
    difmax = 0.0;
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        diff = fabs(tnew[i][j] - t[i][j]);
        if (diff > difmax) {
          difmax = diff;
        }
        // copy new to old temperatures
        t[i][j] = tnew[i][j];
      }
    }
  }

  // print results
  printf("iter = %d  difmax = %9.11lf", iter, difmax);
  for (i = 0; i <= m + 1; i++) {
    fprintf(csv, "%3.5lf", t[i][0]);
    for (j = 1; j <= n + 1; j++) {
      fprintf(csv, ",%3.5lf", t[i][j]);
    }
    fprintf(csv, "\n");
  }
  printf("\n");
}

#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int n, m;
  double tol; // = 0.0001;
  FILE *csv;
  csv = fopen("computationTime.csv", "a");
  int i, j, iter, tn;
  double time;

  m = atoi(argv[1]);
  n = atoi(argv[2]);
  tol = atof(argv[3]);
  tn = atof(argv[4]);
  omp_set_num_threads(tn);
  double t[m + 2][n + 2], tnew[m + 1][n + 1], diff, difmax;

  // printf("%d %d %lf\n", m, n, tol);

  // initialise temperature array
  for (i = 0; i <= m + 1; i++) {
    for (j = 0; j <= n + 1; j++) {
      t[i][j] = 30.0;
    }
  }
  // start timer
  time = omp_get_wtime();
  // fix boundary conditions
  for (i = 1; i <= m; i++) {
    t[i][0] = 15.0;
    t[i][n + 1] = 60.0;
  }
  for (j = 1; j <= n; j++) {
    t[0][j] = 47.0;
    t[m + 1][j] = 100.0;
  }
  int s_stop, t_stop, t_iter;
  s_stop = 0;
  // main loop
  iter = 0;
  difmax = 1000000.0;
#pragma omp parallel private(tn, tj, t_stop)
  {
    while (difmax > tol) {
#pragma omp critical
      {
        iter++;
        t_iter = iter;
      }
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
  }
  fclose(csv);

  // print results
  // printf("iter = %d  difmax = %9.11lf", iter, difmax);
  // for (i = 0; i <= m + 1; i++) {
  //   printf("\n");
  //   for (j = 0; j <= n + 1; j++) {
  //     printf("%3.5lf ", t[i][j]);
  //   }
  // }
  // printf("\n");
}

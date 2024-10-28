#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int m;
  int n;
  double tol; // = 0.0001;
  FILE *csv, *csv2;
  csv = fopen("computationTime.csv", "a");
  csv2 = fopen("jacobiResult.csv", "w+");
  int i, j, iter, num_threads;
  int t_count = 0;
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  tol = atof(argv[3]);
  num_threads = atof(argv[4]);
  omp_set_num_threads(num_threads);

  double t[m + 2][n + 2], tnew[m + 1][n + 1], diff, difmax;

  // start timer
  double time = omp_get_wtime();

#pragma omp parallel private(i, j)
  {

    // initialise temperature array
#pragma omp for schedule(auto)
    for (i = 0; i <= m + 1; i++) {
      for (j = 0; j <= n + 1; j++) {
        t[i][j] = 30.0;
      }
    }

// fix boundary conditions
#pragma omp for schedule(auto)
    for (i = 1; i <= m; i++) {
      t[i][0] = 15.0;
      t[i][n + 1] = 60.0;
    }

#pragma omp for schedule(auto)
    for (j = 1; j <= n; j++) {
      t[0][j] = 47.0;
      t[m + 1][j] = 100.0;
    }

  } // END PARALLEL REGION

  // main loop
  iter = 0;
  difmax = 1000000.0;
#pragma omp parallel private(i, j, diff) // BEGIN PARALLEL REGION
  {
    while (difmax > tol) {
      iter++;

      // update temperature for next iteration
#pragma omp for schedule(auto)
      for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
          tnew[i][j] =
              (t[i - 1][j] + t[i + 1][j] + t[i][j - 1] + t[i][j + 1]) / 4.0;
        }
      }

      // work out maximum difference between old and new temperatures
      difmax = 0.0;
#pragma omp for schedule(auto)
      for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
          diff = fabs(tnew[i][j] - t[i][j]);
          if (diff > difmax) {
#pragma omp critical
            difmax = diff;
          }
          // copy new to old temperatures
          t[i][j] = tnew[i][j];
        }
      }
    }
  } // END PARALLEL REGION

  time = omp_get_wtime() - time;
  fprintf(csv, "%f,", time);

  // print results
  // printf("iter = %d  difmax = %9.11lf", iter, difmax);
  for (i = 0; i <= m + 1; i++) {
    fprintf(csv2, "%3.5lf", t[i][0]);
    for (j = 1; j <= n + 1; j++) {
      fprintf(csv2, ",%3.5lf", t[i][j]);
    }
    fprintf(csv2, "\n");
  }
  printf("\n");
  fclose(csv);
  fclose(csv2);
}

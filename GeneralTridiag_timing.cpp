#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
ofstream ofile;

// Genearl Tridiagonal solver takes in size of matricies as n and other
// variables D,E,F,B that describe the matrix problem
int GeneralTridiagonal(int n, int loopnum){
  double h = 1 / (double)n;

  double timeused = 0.0;
  for(int j = 0; j < loopnum; j++){
    double *D = new double[n+1];
    for(int i = 0; i < n+1; i++){D[i] = (rand() %10) + 1;}
    double *E = new double[n];
    for(int i = 0; i < n+1; i++){D[i] = (rand() %10) + 1;}
    double *F = new double[n];
    for(int i = 0; i < n+1; i++){D[i] = (rand() %10) + 1;}
    double *B = new double[n+1];
    for(int i = 0; i < n; i++){B[i] = h*h*100*exp(-10*i*h);}

    double *x = new double[n+1];
    double *ans = new double[n+1];
    D[0] = D[1] = D[n] = -2; ans[0] = ans[n] = 0.0;

    for(int i = 0; i <=n; i++){
      x[i] = i*h;
    }

    clock_t start, stop;
    start = clock();
    //Gaussian elimination for the main matrix or forward substitution
    for(int i = 2; i <= n; i++){
      double temp = E[i-1]/D[i-1];
      D[i] = D[i] - E[i-1]*temp;
      B[i] = B[i] - B[i-1]*temp;
    }

    //Backward substitution
    ans[n-1] = -B[n-1]/D[n-1];
    for(int i = n-2; i > 0; i--){
      ans[i] = -(B[i] + F[i]*ans[i+1])/D[i];
    }

    stop = clock();
    timeused += (double) (stop - start)/(CLOCKS_PER_SEC );

    delete [] D;
    delete [] E;
    delete [] F;
    delete [] x;
    delete [] B;
    delete [] ans;
  }
  cout << "timing: " << timeused/ (float) loopnum << endl;
  return 0;
}
//=============================================================================
// Main Start
//=============================================================================
int main(int argc, char* argv[]){
  srand(time(NULL));
  int n = atoi(argv[1]);
  int loopnum = atoi(argv[2]);

  GeneralTridiagonal(n, loopnum);

}

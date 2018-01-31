//g++ -o Project1.x Project1.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int RelativeError(int n, double ans[]){
  double h = 1 / (double)n;
  double *real = new double[n];
  for(int i = 0; i < n; i++){real[i] = 1.0-(1-exp(-10))*i*h - exp(-10*i*h);}

  double maxE = 0;
  double E = 0;

  for(int i = 1; i < n; i++){
    E = abs((ans[i] - real[i])/real[i]);
    if(E > maxE){
      maxE = E;
    }
  }

  maxE = log10(maxE);

  cout << "The max error is: " << maxE << endl;

  delete [] real;
  return 0;
}

int SimpleTridiagonal(int n){
  double h = 1 / (double)n;

  double *B = new double[n];
  for(int i = 0; i < n; i++){B[i] = h*h*100.0*exp(-10.0*i*h);}
  double *D = new double[n];
  D[0] = -2;

  double *X = new double[n];

  //precalculated D_new
  for(int i = 1; i <= n; i++){
    D[i] = ((double)i+1.0)/((double)i);
  }

  clock_t start, stop;
  start = clock();

  //Gaussian elimination for the main matrix or forward substitution
  for(int i = 2; i < n; i++){
    B[i] = B[i] + B[i-1]/D[i-1];
  }
  //Backward substitution
  X[n-1] = B[n-1]/D[n-1];
  for(int i = n-2; i > 0; i--){
    X[i] = (B[i] + X[i+1])/D[i];
  }

  // cout << "x" <<endl;
  // for(int i = 0; i < n; i++){
  //   cout << X[i] << ", ";
  // }
  // cout << endl;

  stop = clock();
  double timeused = (double) (stop - start)/(CLOCKS_PER_SEC );

  cout << "Time used for SimpleTridiagonal: " << timeused << endl;

  RelativeError(n, X);

  delete [] B;
  delete [] D;
  delete [] X;
  return 0;
}



//=============================================================================
// Main Start
//=============================================================================
int main(int argc, char* argv[]){
  srand(time(NULL));
  int n = atoi(argv[1]);
  SimpleTridiagonal(n);
}

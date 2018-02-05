//g++ -o Project1.x Project1.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

ofstream ofile;


double real(double x){return 1.0-(1-exp(-10))*x - exp(-10*x);}
double RelativeError(double calc, double real){return fabs((real-calc)/real);}

//=============================================================================
// Main Start
//=============================================================================
int main(int argc, char* argv[]){
  srand(time(NULL));
  int n = atoi(argv[2]);
  char* name = argv[1];

  double h = 1 / (double)n;
  double *B = new double[n+1];
  double *D = new double[n+1];
  D[0] = D[n] = 2;
  double *x = new double[n+1];
  double *ans = new double[n+1];
  ans[0] = ans[n] = 0.0;
  //precalculated D_new
  for(int i = 1; i < n; i++){
    D[i] = ((double)i+1.0)/((double)i);
  }
  for(int i = 0; i <= n; i++){
    B[i] = h*h*100.0*exp(-10.0*i*h);
    x[i] = i*h;
  }
  clock_t start, stop;
  start = clock();

  //Gaussian elimination for the main matrix or forward substitution
  for(int i = 2; i < n; i++){
    B[i] = B[i] + B[i-1]/D[i-1];
  }

  //Backward substitution
  ans[n-1] = B[n-1]/D[n-1];
  for(int i = n-2; i > 0; i--){
    ans[i] = (B[i] + ans[i+1])/D[i];
  }

  stop = clock();
  double timeused = (double) (stop - start)/(CLOCKS_PER_SEC );

  cout << "Time used for SimpleTridiagonal: " << timeused << endl;

  double LargestError = 0;
  for(int i = 0; i < n; i++){
    double exact = real(x[i]);
    double Error = RelativeError(ans[i],exact);
    if(Error > LargestError){
      LargestError = Error;
    }
  }
  cout << setprecision(8) << "Error" << LargestError << log10(LargestError) << endl;

  ofile.open(name);
  for(int i = 0; i < n; i++){
    double exact = real(x[i]);
    double Error = RelativeError(ans[i],exact);
    ofile << setw(15) << setprecision(8) << x[i];
    ofile << setw(15) << setprecision(8) << ans[i];
    ofile << setw(15) << setprecision(8) << exact;
    ofile << setw(15) << setprecision(8) << log10(Error) << endl;
  }
  ofile.close();

  delete [] B;
  delete [] D;
  delete [] ans;
  delete [] x;
  return 0;
}

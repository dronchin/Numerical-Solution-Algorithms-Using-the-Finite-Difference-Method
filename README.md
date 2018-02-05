Project 1 for PHY 480 with proffesor Morten Hjorth

Program source files can be found in the program source folder. This includes the GeneralTridiag.cpp, GeneralTridiag_timing.cpp, LUdecompsolver.cpp, SimpleTridiag.cpp, SimpleTridiag_timing.cpp

For all programs except LUdecompsolver.cpp, g++ -O3 -o filename.x filename.cpp was used for compiling. LUdecomplsolver requires -larmadillo -llapack -lblas.

The input for non timing programs is filename.x outputfile.txt sizeofarray where the size of the array is not in powers of 10 but absolute size according to nxn.

Python files used for plotting the error and timing are included in Program source files.

Compiled programs were also included but not all of them, only the main 3. The timing ones are left for you if you decided to compile them.

The report source code and pdf can be found in the Report file.

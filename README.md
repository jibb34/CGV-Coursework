# CGV-Coursework
Final Coursework Project for Clouds, Grids, and Virtualization. 


To complete this assignment you will need the source code provided at the following URL.
https://moodlecurrent.gre.ac.uk/mod/resource/view.php?id=2163909
You are provided with a C program code (called jacobi2d.c) that solves a rectangular 2 dimensional heat conductivity
problem using the Jacobi iterative method.
This code can be compiled and linked to produce a conventional executable file called jacobiSerial by using the
following commands:
gcc jacobi2d.c –o jacobiSerial
To run the executable type in the executable name: jacobiSerial
As you implement each of the following 4 steps make sure that you retain and do not overwrite previous versions of
your solutions.
Compile and execute the codes using the University HPC. Note this is a shared resource with a queue may become
busy near the hand in date so make sure you give plenty of time to run your code and don’t leave it to the last
minute. If you are unsure how to use the HPC please check the lab notes and the instructions on Moodle.

Step 1 (10 Marks)
You are required to compute a temperature distribution for a rectangular 2D problem with boundary conditions set
at top 15°C, bottom 60°C, left 47°C and right 100°C with a range of problem sizes. To do this you are required to
modify the codes to:
• reflect the boundary conditions described above
• report the execution time Record the run-time of your code under a range of problem sizes greater than
100x100 using different levels of compiler optimization.
Be advised that:
• it is possible that aggressive optimization will break the code
• you will need to stop the results from printing if you are to obtain realistic measurements of the execution
time.
Step 2 (20 Marks)
You are then required to modify the applications you created in step 1 to produce a basic parallel version of the
codes using OpenMP. The following commands will compile your parallel version on a platform that has OpenMP
installed:
gcc -fopenmp jacobiOpenmp.c –o jacobiOpenmp
The parallel codes must include timers to report the parallel run-time of the code. This version must be tested to
establish correct operation using 1, 2, 4 and 8 threads/processors, regardless of performance. (These versions may
run on any platform you choose as performance is not an issue at this stage.)
Include in your report, the result for a 20x20 problem size for 1,2,4 and 8 processors to demonstrate the code works
correctly. This should be as a screen shot of the outputted grid.
Step 3 (20 Marks)
Using the HPC and the SLURM queue you are to run performance tests with the OpenMP implementation you
created in step 2. This will require that you remove most of the print output from the code and increase the
problem size to provide sufficient work to demonstrate useful speedup. You are expected to provide speedup
results:
• for a range of problem sizes, you are unlikely to see much speedup for small domains, use the same problem size
as step 1
• for a range of number of threads (from 2 up to 8 threads) In calculating the speedup of your parallel code you
should use the optimized single processor version of your code you produced in step 1 and compare to this. You will
need to apply similar compiler optimizations to your parallel code. Please list your runtimes in a suitable unit.
This section is required to provide details of your implementation of steps 1 to 3 as described above. You should
include discussion of your solutions and provide a clear description of; the code changes you have implemented
including code snippets, your compilation and execution processes and your test cases. For step 3 you are expected
to provide tabular and graphical results. Your zip file should provide suitably named source code files for each of
your implementations (e.g. step 1, step 2, step 3).
This section should be approximately 1500 words.
A further 10 marks will be awarded for your use of English in the report.

This project implements the Successive Over-Relaxation (SOR) method for solving systems of linear equations of the form $Ax = b$, where A is a sparse symmetric matrix with a banded structure, x is the solution vector, and $\omega$ is the right-hand side vector. It utilizes the iterative technique that builds upon the Gauss-Seidel method to accelerate convergence by introducing a relaxation parameter 𝜔, which allows the iterative updates to over-relax or under-relax, depending on the problem structure and choice of parameter value.
The program utilizes the iterative formula:

$x_i^{(k+1)}=(1-\omega) x_i^{(k)}+\frac{\omega}{a_{i i}}\left(b_i-\sum_{j<i} a_{i j} x_j^{(k+1)} \sum_{j>i} a_{i j} x_j^{(k)}\right)$

for the $i$-th component of the solution vector in the SOR method, where: 

- ω $∈ (0,2)$ is the relaxation parameter,
- $k$ is the iteration count,
- $a_{ij}$ are elements of the matrix $A$

The relaxation parameter 𝜔 determines the speed of convergence:
* 𝜔 $= 1$ : equivalent to the Gauss-Seidel method
* 𝜔 $< 1$ : under-relaxation
* 𝜔 $> 1$: over-relaxation (faster convergence in many cases)

__Input format__\
The program expects input in the following format:
* $N$ (size of the matrix) and $M$ (number of nonzero bands above or below the diagonal)
* $M$ lines representing the banded structure of matrix $A$
* $N$ elements of the diagonal od $A$
* $N$ elements of the right-hand side vector
* $N$ elements of the initial guess vector $x(0)$
* relaxation parameter 𝜔 and the number of iterations $L$

Example input:
```
10
1
1 -1 2 1 3 -1 1 2 2
8 9 10 9 8 5 10 9 7 5 
7 -8 5 -7 3 -5 7 -5 4 -3
2 1 2 1 2 1 2 1 2 1
1.3
5
```
Expected output:
```
9.9940568551471820e-01 
-9.0904662229329669e-01 
6.0991796223201045e-01 
-1.0130102944878934e+00 
1.0831324689900357e+00 
-1.5137961825745920e+00 
6.1540772283026224e-01 
-8.7787343355916414e-01 
1.1233322463475970e+00 
-1.0523066239504728e+00 
```


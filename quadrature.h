#ifndef QUADRATURE_H
#define QUADRATURE_H

template <typename Func>
inline double computeSimpson(Func f, int* evalCounter, double a, double b);

template <typename Func>
double simpsonAdaptive(Func f, int* evalCounter, double a, double b, double tol, int depth = 0, int maxDepth = 1000);

#endif
#ifndef RESOURCE_H
#define RESOURCE_H

#include <vector>

void init_resource(int N, int Q, std::vector<int> A, std::vector<int> U, std::vector<int> V, int G);

long long need_help(int X, int C, int K);

#endif
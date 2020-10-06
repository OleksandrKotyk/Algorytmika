#ifndef ALGORYTMIKA_NIEOPTYMALNY_H
#define ALGORYTMIKA_NIEOPTYMALNY_H

#include <iostream>
#include "structs_and_funcs.h"

using namespace std;

void nie_optymalny() {
    unsigned long long N;
    auto *arr = readPoint(N);
    result r;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            double l = arr[i].length(arr[j]);
            if (l > r.max)
                r = result{arr + j, arr + i, l};
        }
    cout<<r<<endl;
    cout<<(10/2*9) * 2<<" operacij dla 10 wierzchołków  w najgorszym wypadku"<<endl;
    cout<<(20/2*19) * 2<<" operacij dla 20 wierzchołków  w najgorszym wypadku"<<endl;
}

#endif //ALGORYTMIKA_NIEOPTYMALNY_H

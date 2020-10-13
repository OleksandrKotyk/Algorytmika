#ifndef ALGORYTMIKA_OPTYMALNY_H
#define ALGORYTMIKA_OPTYMALNY_H

#include <iostream>
#include "structs_and_funcs.h"

using namespace std;

struct res{
    res(const line &l1, const line &l2) : l1(l1), l2(l2) {}

    line l1;
    line l2;
    double max = -1;
};

void optymalny() {
    unsigned long long N;
    auto *arr = readPoint(N);

    if(N == 1) return;
    else if(N == 2) cout<<arr[0].length(arr[1]);

    line mn(arr[0], arr[1], 0, 1);

    line *l;
    line *l1 = new line(mn);
    double max = 0;

    for (int i = 2; i < N; ++i) {
        l = mn.line_from_point(arr[i], i);
        if(max < abs(mn.b - l->b)){
            max = abs(mn.b - l->b);
            l1 = l;
        }
    }



    line f = mn;
    line s = *l1;

    res res(f, s);

    while(true){
        if(abs(f.b - s.b) > res.max){
            res.max = abs(f.b - s.b);
            res.l1 = f;
            res.l2 = s;
        }

        if(f.n2 == N -1 or s.n2 == N - 1){
            break;
        }

        line helpLine1(arr[f.n2], arr[f.n2 + 1], f.n2, f.n2 + 1);
        line helpLine2(arr[s.n2], arr[s.n2 + 1], s.n2, s.n2 + 1);

        if(abs(helpLine1.a - f.a) < abs(helpLine2.a - s.a)){
            f = line(arr[f.n2], arr[f.n2 + 1], f.n2, f.n2 + 1);
            if(s.n1 == s.n2){
                s = *f.line_from_point(arr[s.n2 + 1], s.n2 + 1);
            }else {
                s = *f.line_from_point(arr[s.n2], s.n2);
            }
        }else{
            s = line(arr[s.n2], arr[s.n2 + 1], s.n2, s.n2 + 1);
            if(f.n1 == f.n2){
                f = *s.line_from_point(arr[f.n2 + 1], f.n2 + 1);
            }else{
                f = *s.line_from_point(arr[f.n2], f.n2);
            }
        }
    }

    if(res.l1.n1 == res.l1.n2){
        cout<<arr[res.l1.n1]<<" ";
        cout<<(arr[res.l1.n1].length(arr[res.l2.n1]) > arr[res.l1.n1].length(arr[res.l2.n1])? arr[res.l2.n1] : arr[res.l2.n2]);
    }else{
        cout<<arr[res.l2.n1]<<" ";
        cout<<(arr[res.l2.n1].length(arr[res.l1.n1]) > arr[res.l2.n1].length(arr[res.l1.n1])? arr[res.l1.n1] : arr[res.l1.n2]);
    }

//    cout<<(10/2*9) * 2<<" operacij dla 10 wierzchołków  w najgorszym wypadku"<<endl;
//    cout<<(20/2*19) * 2<<" operacij dla 20 wierzchołków  w najgorszym wypadku"<<endl;
}

#endif //ALGORYTMIKA_OPTYMALNY_H

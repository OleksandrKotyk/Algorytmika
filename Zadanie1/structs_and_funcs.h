#ifndef ALGORYTMIKA_STRUCTS_AND_FUNCS_H
#define ALGORYTMIKA_STRUCTS_AND_FUNCS_H

#include <ostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;

    double length(point a) const {
        return sqrt(pow(a.x - x, 2) + pow(a.y - y, 2) * 1.0);
    }

    ostream &operator<<(ostream &os) const {
        os << "(" << x << ", " << y << ")";
        return os;
    }

    friend ostream &operator<<(ostream &os, const point &p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

struct result {
    point *p1 = nullptr;
    point *p2 = nullptr;
    double max = -1;

    result() = default;

    result(point *p1, point *p2, double max) : p1(p1), p2(p2), max(max) {}

    friend ostream &operator<<(ostream &os, const result &r) {
        os << *r.p1 << " " << *r.p2 << " " << r.max;
        return os;
    }
};

struct line {
    double a, b;

    bool if_in(point &p) const {
        return p.y - p.x * this->a == b;
    }

    line(point &p1, point &p2) {
        a = (p2.y - p1.y) / (p2.x - p1.x);
        b = p1.y - a * p1.x;
    }
};

point *readPoint(unsigned long long &N) {
    cin >> N;
    auto *arr = new point[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i].x >> arr[i].y;
    return arr;
}

#endif //ALGORYTMIKA_STRUCTS_AND_FUNCS_H

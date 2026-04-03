#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class cTamGiac {
private:
    Point A, B, C;
public:
    cTamGiac() {}
    cTamGiac(Point a, Point b, Point c) : A(a), B(b), C(c) {}

    void nhap() {
        cout << "A: "; cin >> A.x >> A.y;
        cout << "B: "; cin >> B.x >> B.y;
        cout << "C: "; cin >> C.x >> C.y;
    }

    void xuat() {
        cout << "A(" << A.x << "," << A.y << ") B(" << B.x << "," << B.y << ") C(" << C.x << "," << C.y << ")" << endl;
    }

    double dist(Point p1, Point p2) {
        return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    }

    string loai() {
        double ab = dist(A, B), bc = dist(B, C), ca = dist(C, A);
        double a2 = ab*ab, b2 = bc*bc, c2 = ca*ca;
        if (abs(ab - bc) < EPS && abs(bc - ca) < EPS) return "deu";
        bool vuong = abs(a2 + b2 - c2) < EPS || abs(a2 + c2 - b2) < EPS || abs(b2 + c2 - a2) < EPS;
        bool can = abs(ab - bc) < EPS || abs(bc - ca) < EPS || abs(ca - ab) < EPS;
        if (vuong && can) return "vuong can";
        if (vuong) return "vuong";
        if (can) return "can";
        return "thuong";
    }

    double chuVi() { return dist(A,B) + dist(B,C) + dist(C,A); }

    double dienTich() { return 0.5 * abs(A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)); }

    void tinhTien(double dx, double dy) {
        A.x += dx; A.y += dy;
        B.x += dx; B.y += dy;
        C.x += dx; C.y += dy;
    }

    void quay(double goc, Point tam) {
        double rad = goc * M_PI / 180.0, c = cos(rad), s = sin(rad);
        auto rot = [&](Point& p) {
            double x = p.x - tam.x, y = p.y - tam.y;
            p.x = x*c - y*s + tam.x;
            p.y = x*s + y*c + tam.y;
        };
        rot(A); rot(B); rot(C);
    }

    void phongTo(double k) {
        A.x *= k; A.y *= k;
        B.x *= k; B.y *= k;
        C.x *= k; C.y *= k;
    }

    void thuNho(double k) { phongTo(1.0 / k); }

    void ve() { cout << "Ve tam giac" << endl; }
};

int main() {
    cTamGiac t;
    t.nhap();
    t.xuat();
    cout << "Loai: " << t.loai() << " Chu vi: " << t.chuVi() << " Dien tich: " << t.dienTich() << endl;
    t.tinhTien(1,1); t.xuat();
    t.quay(90, {0,0}); t.xuat();
    t.phongTo(2); t.xuat();
    t.thuNho(2); t.xuat();
    t.ve();
    return 0;
}

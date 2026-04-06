#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 1e-5; 
const double PI = 3.14159265358979323846;

class cTamGiac {
private:
    double xA, yA, xB, yB, xC, yC;

    double KhoangCach(double x1, double y1, double x2, double y2) const;
    bool BangNhau(double a, double b) const;

public:
    cTamGiac();
    bool HopLe() const;
    void Nhap();
    void Xuat() const;
    double ChuVi() const;
    double DienTich() const;
    void PhanLoai() const;
    void TinhTien(double dx, double dy);
    void Quay(double gocDegree);
    void PhongToThuNho(double k);
};

double cTamGiac::KhoangCach(double x1, double y1, double x2, double y2) const {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool cTamGiac::BangNhau(double a, double b) const {
    return abs(a - b) < EPSILON;
}

cTamGiac::cTamGiac() : xA(0), yA(0), xB(0), yB(0), xC(0), yC(0) {}

bool cTamGiac::HopLe() const {
    double a = KhoangCach(xB, yB, xC, yC);
    double b = KhoangCach(xA, yA, xC, yC);
    double c = KhoangCach(xA, yA, xB, yB);
    return (a + b > c) && (b + c > a) && (c + a > b);
}

void cTamGiac::Nhap() {
    do {
        cout << "Nhap toa do dinh A (x y): "; cin >> xA >> yA;
        cout << "Nhap toa do dinh B (x y): "; cin >> xB >> yB;
        cout << "Nhap toa do dinh C (x y): "; cin >> xC >> yC;
        if (!HopLe()) {
            cout << "3 diem khong tao thanh tam giac! Vui long nhap lai.\n";
        }
    } while (!HopLe());
}

void cTamGiac::Xuat() const {
    cout << "Tam giac tao boi: A(" << xA << ", " << yA << "), "
         << "B(" << xB << ", " << yB << "), C(" << xC << ", " << yC << ")\n";
}

double cTamGiac::ChuVi() const {
    return KhoangCach(xB, yB, xC, yC) + 
           KhoangCach(xA, yA, xC, yC) + 
           KhoangCach(xA, yA, xB, yB);
}

double cTamGiac::DienTich() const {
    double a = KhoangCach(xB, yB, xC, yC);
    double b = KhoangCach(xA, yA, xC, yC);
    double c = KhoangCach(xA, yA, xB, yB);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::PhanLoai() const {
    double a = KhoangCach(xB, yB, xC, yC);
    double b = KhoangCach(xA, yA, xC, yC);
    double c = KhoangCach(xA, yA, xB, yB);

    bool vuong = BangNhau(a*a + b*b, c*c) || BangNhau(a*a + c*c, b*b) || BangNhau(b*b + c*c, a*a);
    bool can = BangNhau(a, b) || BangNhau(a, c) || BangNhau(b, c);
    bool deu = BangNhau(a, b) && BangNhau(b, c);

    cout << "Loai tam giac: ";
    if (deu) cout << "Tam giac deu\n";
    else if (vuong && can) cout << "Tam giac vuong can\n";
    else if (vuong) cout << "Tam giac vuong\n";
    else if (can) cout << "Tam giac can\n";
    else cout << "Tam giac thuong\n";
}

void cTamGiac::TinhTien(double dx, double dy) {
    xA += dx; yA += dy;
    xB += dx; yB += dy;
    xC += dx; yC += dy;
}

void cTamGiac::Quay(double gocDegree) {
    double rad = gocDegree * PI / 180.0;
    double cosA = cos(rad), sinA = sin(rad);
    
    double nxA = xA * cosA - yA * sinA; double nyA = xA * sinA + yA * cosA;
    double nxB = xB * cosA - yB * sinA; double nyB = xB * sinA + yB * cosA;
    double nxC = xC * cosA - yC * sinA; double nyC = xC * sinA + yC * cosA;

    xA = nxA; yA = nyA;
    xB = nxB; yB = nyB;
    xC = nxC; yC = nyC;
}

void cTamGiac::PhongToThuNho(double k) {
    if (k == 0) return;
    xA *= k; yA *= k;
    xB *= k; yB *= k;
    xC *= k; yC *= k;
}

int main() {
    cTamGiac tg;
    cout << "--- KHOI TAO TAM GIAC ---\n";
    tg.Nhap();
    tg.Xuat();

    cout << "\n--- THONG TIN TAM GIAC ---\n";
    tg.PhanLoai();
    cout << "Chu vi: " << tg.ChuVi() << "\n";
    cout << "Dien tich: " << tg.DienTich() << "\n";

    cout << "\n--- PHEP BIEN DOI ---\n";
    cout << "1. Tinh tien theo vector (2, 3):\n";
    tg.TinhTien(2, 3);
    tg.Xuat();

    cout << "2. Quay 90 do quanh goc toa do:\n";
    tg.Quay(90);
    tg.Xuat();

    cout << "3. Phong to gap 2 lan:\n";
    tg.PhongToThuNho(2);
    tg.Xuat();

    return 0;
}

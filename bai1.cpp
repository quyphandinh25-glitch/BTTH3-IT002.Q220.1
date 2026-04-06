#include <iostream>
#include <cmath>
using namespace std;

const double EPSILON = 1e-5; 
const double PI = 3.14159265358979323846;

class cDiem {
private:
    double x, y;
public:
    cDiem(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    void Nhap() {
        cin >> x >> y;
    }

    void Xuat() const {
        cout << "(" << x << ", " << y << ")";
    }

    double KhoangCach(const cDiem& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    void TinhTien(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void Quay(double gocDegree) {
        double rad = gocDegree * PI / 180.0;
        double newX = x * cos(rad) - y * sin(rad);
        double newY = x * sin(rad) + y * cos(rad);
        x = newX;
        y = newY;
    }

    void PhongToThuNho(double k) {
        x *= k;
        y *= k;
    }
};

class cTamGiac {
private:
    cDiem A, B, C;
    bool BangNhau(double a, double b) const {
        return abs(a - b) < EPSILON;
    }

public:
    cTamGiac() {}
    cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}

    bool HopLe() const {
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);
        return (a + b > c) && (b + c > a) && (c + a > b);
    }

    void Nhap() {
        do {
            cout << "Nhap toa do dinh A (x y): "; A.Nhap();
            cout << "Nhap toa do dinh B (x y): "; B.Nhap();
            cout << "Nhap toa do dinh C (x y): "; C.Nhap();
            if (!HopLe()) {
                cout << "3 diem khong tao thanh tam giac! Vui long nhap lai.\n";
            }
        } while (!HopLe());
    }

    void Xuat() const {
        cout << "Tam giac tao boi 3 dinh: ";
        A.Xuat(); cout << ", "; B.Xuat(); cout << ", "; C.Xuat(); cout << "\n";
    }

    double ChuVi() const {
        return B.KhoangCach(C) + A.KhoangCach(C) + A.KhoangCach(B);
    }

    double DienTich() const {
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void PhanLoai() const {
        double a = B.KhoangCach(C);
        double b = A.KhoangCach(C);
        double c = A.KhoangCach(B);

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

    void TinhTien(double dx, double dy) {
        A.TinhTien(dx, dy);
        B.TinhTien(dx, dy);
        C.TinhTien(dx, dy);
    }

    void Quay(double gocDegree) {
        A.Quay(gocDegree);
        B.Quay(gocDegree);
        C.Quay(gocDegree);
    }

    void PhongToThuNho(double k) {
        if (k == 0) return;
        A.PhongToThuNho(k);
        B.PhongToThuNho(k);
        C.PhongToThuNho(k);
    }
};

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

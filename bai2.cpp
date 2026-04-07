#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

class cDaGiac {
private:
    int n;
    double *x, *y;

public:
    cDaGiac();                             
    ~cDaGiac();                           
    void Nhap();                         
    void Xuat() const;                    
    double ChuVi() const;                  
    double DienTich() const;               
    void TinhTien(double dx, double dy);  
    void Quay(double gocDegree);           
    void PhongToThuNho(double k);          
};
cDaGiac::cDaGiac() {
    n = 0;
    x = nullptr;
    y = nullptr;
}

cDaGiac::~cDaGiac() {
    delete[] x;
    delete[] y;
}

void cDaGiac::Nhap() {
    do {
        cout << "Nhap so luong dinh cua da giac (n >= 3): ";
        cin >> n;
        if (n < 3) cout << "Khong hop le! Da giac phai co it nhat 3 dinh.\n";
    } while (n < 3);

    x = new double[n];
    y = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
}

void cDaGiac::Xuat() const {
    cout << "Toa do cac dinh: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << x[i] << ", " << y[i] << ")";
        if (i < n - 1) cout << " - ";
    }
    cout << endl;
}

double cDaGiac::ChuVi() const {
    double p = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        p += sqrt(pow(x[i] - x[next], 2) + pow(y[i] - y[next], 2));
    }
    return p;
}

double cDaGiac::DienTich() const {
    double s = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        s += (x[i] * y[next]) - (x[next] * y[i]);
    }
    return abs(s) / 2.0;
}

void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        x[i] += dx;
        y[i] += dy;
    }
}

void cDaGiac::Quay(double gocDegree) {
    double rad = gocDegree * PI / 180.0;
    for (int i = 0; i < n; i++) {
        double oldX = x[i];
        double oldY = y[i];
        x[i] = oldX * cos(rad) - oldY * sin(rad);
        y[i] = oldX * sin(rad) + oldY * cos(rad);
    }
}

void cDaGiac::PhongToThuNho(double k) {
    if (k == 0) return;
    for (int i = 0; i < n; i++) {
        x[i] *= k;
        y[i] *= k;
    }
}

int main() {
    cDaGiac dg;
    cout << "=== KHOI TAO DA GIAC ===\n";
    dg.Nhap();
    dg.Xuat();

    cout << "\n=== KET QUA TINH TOAN ===\n";
    cout << fixed << setprecision(2);
    cout << "Chu vi da giac: " << dg.ChuVi() << endl;
    cout << "Dien tich da giac: " << dg.DienTich() << endl;

    cout << "\n=== BIEN DOI HINH HOC ===\n";
    cout << "1. Tinh tien vector (2, 3):\n";
    dg.TinhTien(2, 3);
    dg.Xuat();

    cout << "2. Quay 90 do quanh goc toa do:\n";
    dg.Quay(90);
    dg.Xuat();

    cout << "3. Phong to gap 2 lan:\n";
    dg.PhongToThuNho(2);
    dg.Xuat();

    return 0;
}

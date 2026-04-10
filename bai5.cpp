#include <iostream>
#include <cmath>

using namespace std;

class cDaThuc {
private:
    int n;             
    double a[100];     

public: 
    cDaThuc();
    void Nhap();
    void Xuat();
    double TinhGiaTri(double x);
    cDaThuc Cong(cDaThuc dt2);
    cDaThuc Tru(cDaThuc dt2);
};


cDaThuc::cDaThuc() {
    n = 0;
    for (int i = 0; i < 100; i++) {
        a[i] = 0;
    }
}

void cDaThuc::Nhap() {
    cout << "Nhap bac cua da thuc n = ";
    cin >> n;
    
    for (int i = n; i >= 0; i--) {
        cout << "He so cua x^" << i << " = ";
        cin >> a[i];
    }
}

void cDaThuc::Xuat() {
    for (int i = n; i >= 0; i--) {
        cout << a[i] << "x^" << i;
        if (i > 0) {
            cout << " + "; 
        }
    }
    cout << "\n";
}

double cDaThuc::TinhGiaTri(double x) {
    double ketQua = 0;
    for (int i = 0; i <= n; i++) {
        ketQua += a[i] * pow(x, i); 
    }
    return ketQua;
}

cDaThuc cDaThuc::Cong(cDaThuc dt2) {
    cDaThuc kq;
    kq.n = max(this->n, dt2.n); 

    for (int i = 0; i <= kq.n; i++) {
        kq.a[i] = this->a[i] + dt2.a[i];
    }
    return kq;
}

cDaThuc cDaThuc::Tru(cDaThuc dt2) {
    cDaThuc kq;
    kq.n = max(this->n, dt2.n);

    for (int i = 0; i <= kq.n; i++) {
        kq.a[i] = this->a[i] - dt2.a[i];
    }
    return kq;
}

int main() {
    cDaThuc P, Q, Tong, Hieu;

    cout << "--- NHAP DA THUC P(x) ---\n";
    P.Nhap();
    
    cout << "\n--- NHAP DA THUC Q(x) ---\n";
    Q.Nhap();

    cout << "\n--- KET QUA ---\n";
    cout << "P(x) = "; P.Xuat();
    cout << "Q(x) = "; Q.Xuat();

    double x;
    cout << "\nNhap x de tinh P(x): ";
    cin >> x;
    cout << "Gia tri P(" << x << ") = " << P.TinhGiaTri(x) << "\n";

    Tong = P.Cong(Q);
    cout << "\nP(x) + Q(x) = ";
    Tong.Xuat();

    Hieu = P.Tru(Q);
    cout << "P(x) - Q(x) = ";
    Hieu.Xuat();

    return 0;
}

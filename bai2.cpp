#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class cDiem {
private:
    double x, y;
public:
    cDiem(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    double getX() const { return x; }
    double getY() const { return y; }

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

class cDaGiac {
private:
    int n;          
    cDiem* dinh;   

public:
    
    cDaGiac() {
        n = 0;
        dinh = nullptr;
    }

    ~cDaGiac() {
        if (dinh != nullptr) {
            delete[] dinh;
        }
    }

    void Nhap() {
        do {
            cout << "Nhap so luong dinh cua da giac (n >= 3): ";
            cin >> n;
            if (n < 3) cout << "Da giac phai co it nhat 3 dinh. Vui long nhap lai!\n";
        } while (n < 3);

        if (dinh != nullptr) delete[] dinh; 
        dinh = new cDiem[n];

        for (int i = 0; i < n; i++) {
            cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
            dinh[i].Nhap();
        }
    }

    void Xuat() const {
        cout << "Da giac " << n << " dinh co toa do: ";
        for (int i = 0; i < n; i++) {
            dinh[i].Xuat();
            if (i < n - 1) cout << " - ";
        }
        cout << "\n";
    }

    double ChuVi() const {
        if (n < 3) return 0;
        double p = 0;
        for (int i = 0; i < n; i++) {
            p += dinh[i].KhoangCach(dinh[(i + 1) % n]);
        }
        return p;
    }

    double DienTich() const {
        if (n < 3) return 0;
        double s = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n; 
            s += (dinh[i].getX() * dinh[next].getY()) - (dinh[next].getX() * dinh[i].getY());
        }
        return abs(s) / 2.0;
    }

    void TinhTien(double dx, double dy) {
        for (int i = 0; i < n; i++) {
            dinh[i].TinhTien(dx, dy);
        }
    }

    void Quay(double gocDegree) {
        for (int i = 0; i < n; i++) {
            dinh[i].Quay(gocDegree);
        }
    }

    void PhongToThuNho(double k) {
        if (k == 0) return;
        for (int i = 0; i < n; i++) {
            dinh[i].PhongToThuNho(k);
        }
    }
};


int main() {
    cDaGiac dg;
    cout << "--- KHOI TAO DA GIAC ---\n";
    dg.Nhap();
    dg.Xuat();

    cout << "\n--- THONG TIN DA GIAC ---\n";
    cout << "Chu vi: " << dg.ChuVi() << "\n";
    cout << "Dien tich: " << dg.DienTich() << "\n";

    cout << "\n--- PHEP BIEN DOI ---\n";
    cout << "1. Tinh tien theo vector (-1, 2):\n";
    dg.TinhTien(-1, 2);
    dg.Xuat();

    cout << "2. Phong to gap 3 lan quanh goc toa do:\n";
    dg.PhongToThuNho(3);
    dg.Xuat();

    cout << "3. Quay 180 do quanh goc toa do:\n";
    dg.Quay(180);
    dg.Xuat();

    // Khi kết thúc hàm main, đối tượng dg sẽ tự động gọi hàm hủy ~cDaGiac() để giải phóng RAM
    return 0;
}

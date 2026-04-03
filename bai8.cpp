#include <iostream>
#include <string>

using namespace std;

class cNgay {
private:
    int ngay, thang, nam;

public:
    cNgay() {
        ngay = 1;
        thang = 1;
        nam = 2000;
    }

    void Nhap() {
        cout << "Nhap ngay, thang, nam (cach nhau boi khoang trang): ";
        cin >> ngay >> thang >> nam;
    }

    void Xuat() {
        cout << ngay << "/" << thang << "/" << nam;
    }

    bool NhoHon(cNgay khac) {
        if (nam != khac.nam) return nam < khac.nam;      
        if (thang != khac.thang) return thang < khac.thang; 
        return ngay < khac.ngay;                            
    }
};

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    cNgay ngaySinh; 
    int soSP;
    double donGia;

public:
    
    cNhanVienSX() {
        maNV = "";
        hoTen = "";
        soSP = 0;
        donGia = 0;
    }

    double TinhLuong() {
        return soSP * donGia;
    }
    
    cNgay getNgaySinh() {
        return ngaySinh;
    }
    
    string getHoTen() {
        return hoTen;
    }

    void Nhap() {
        cout << "Nhap ma NV: ";
        cin >> maNV;
        cout << "Nhap ho ten: ";
        cin.ignore(); 
        getline(cin, hoTen);
        
        ngaySinh.Nhap(); 
        
        cout << "Nhap so san pham da gia cong: ";
        cin >> soSP;
        cout << "Nhap don gia 1 san pham: ";
        cin >> donGia;
    }

    void Xuat() {
        cout << "Ma NV: " << maNV 
             << " | Ten: " << hoTen 
             << " | Ngay sinh: ";
        ngaySinh.Xuat(); // Gọi hàm xuất của lớp cNgay
        cout << " | Luong: " << TinhLuong() << endl;
    }
};


int main() {
    cNhanVienSX ds[100]; 
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    double tongLuong = 0;
    double luongMin = ds[0].TinhLuong();
    int indexMinLuong = 0;

    for (int i = 0; i < n; i++) {
        double luongHT = ds[i].TinhLuong();
        tongLuong += luongHT;
        
        if (luongHT < luongMin) {
            luongMin = luongHT;
            indexMinLuong = i;
        }
    }
    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;
    cout << "Nhan vien co luong thap nhat la: " << ds[indexMinLuong].getHoTen() 
         << " (" << luongMin << ")" << endl;

    cNgay ngaySinhMin = ds[0].getNgaySinh();
    int indexTuoiCao = 0;
    
    for (int i = 1; i < n; i++) {
        if (ds[i].getNgaySinh().NhoHon(ngaySinhMin)) {
            ngaySinhMin = ds[i].getNgaySinh();
            indexTuoiCao = i;
        }
    }
    cout << "Nhan vien lon tuoi nhat la: " << ds[indexTuoiCao].getHoTen() << " (Sinh ngay ";
    ngaySinhMin.Xuat();
    cout << ")" << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                cNhanVienSX temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\n=== DANH SACH SAU KHI SAP XEP LUONG TANG DAN ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    return 0;
}

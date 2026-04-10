#include <iostream>
#include <string>

using namespace std;

class cNgay {
private:
    int ngay, thang, nam;

public:
    cNgay();
    void Nhap();
    void Xuat();
    bool NhoHon(cNgay khac);
};

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    cNgay ngaySinh; 
    int soSP;
    double donGia;

public:
    cNhanVienSX();
    double TinhLuong();
    cNgay getNgaySinh();
    string getHoTen();
    void Nhap();
    void Xuat();
};

class cDanhSachNV {
private:
    cNhanVienSX ds[100];
    int n;

public:
    void NhapDanhSach();
    void XuatDanhSach();
    void ThongKe();
    void SapXepTangTheoLuong();
};

cNgay::cNgay() {
    ngay = 1; 
    thang = 1; 
    nam = 2000;
}

void cNgay::Nhap() {
    cout << "Nhap ngay, thang, nam (cach nhau boi khoang trang): ";
    cin >> ngay >> thang >> nam;
}

void cNgay::Xuat() {
    cout << ngay << "/" << thang << "/" << nam;
}

bool cNgay::NhoHon(cNgay khac) {
    if (nam != khac.nam) return nam < khac.nam;      
    if (thang != khac.thang) return thang < khac.thang; 
    return ngay < khac.ngay;                            
}

cNhanVienSX::cNhanVienSX() {
    maNV = ""; 
    hoTen = ""; 
    soSP = 0; 
    donGia = 0;
}

double cNhanVienSX::TinhLuong() { 
    return soSP * donGia; 
}

cNgay cNhanVienSX::getNgaySinh() { 
    return ngaySinh; 
}

string cNhanVienSX::getHoTen() { 
    return hoTen; 
}

void cNhanVienSX::Nhap() {
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

void cNhanVienSX::Xuat() {
    cout << "Ma NV: " << maNV << " | Ten: " << hoTen << " | Ngay sinh: ";
    ngaySinh.Xuat();
    cout << " | Luong: " << TinhLuong() << endl;
}

void cDanhSachNV::NhapDanhSach() {
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

void cDanhSachNV::XuatDanhSach() {
    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

void cDanhSachNV::ThongKe() {
    if (n == 0) return;

    double tongLuong = 0;
    double luongMin = ds[0].TinhLuong();
    int indexMinLuong = 0;
    cNgay ngaySinhMin = ds[0].getNgaySinh();
    int indexTuoiCao = 0;

    for (int i = 0; i < n; i++) {
        double luongHT = ds[i].TinhLuong();
        tongLuong += luongHT;
        
        if (luongHT < luongMin) {
            luongMin = luongHT;
            indexMinLuong = i;
        }

        if (ds[i].getNgaySinh().NhoHon(ngaySinhMin)) {
            ngaySinhMin = ds[i].getNgaySinh();
            indexTuoiCao = i;
        }
    }

    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;
    cout << "Nhan vien co luong thap nhat: " << ds[indexMinLuong].getHoTen() << " (" << luongMin << ")\n";
    cout << "Nhan vien lon tuoi nhat: " << ds[indexTuoiCao].getHoTen() << " (Sinh ngay ";
    ngaySinhMin.Xuat();
    cout << ")\n";
}

void cDanhSachNV::SapXepTangTheoLuong() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                swap(ds[i], ds[j]); 
            }
        }
    }
    cout << "\n=== DANH SACH SAU KHI SAP XEP LUONG TANG DAN ===\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }
}

int main() {
    cDanhSachNV congTy;

    congTy.NhapDanhSach();
    congTy.XuatDanhSach();
    congTy.ThongKe();
    congTy.SapXepTangTheoLuong();

    return 0;
}

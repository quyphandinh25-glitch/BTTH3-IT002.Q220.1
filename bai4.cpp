#include <bits/stdc++.h>

using namespace std;

class cArray {
private:
    int* arr;
    int n;

    bool isPrime(int num) const;
    void quickSort(int left, int right);

public:  
    cArray();
    ~cArray();

    void nhapMang(int size);
    void taoMangNgauNhien(int size);
    void xuatMang() const;
    int demSoLanXuatHien(int x) const;
    bool kiemTraTangDan() const;
    bool timPhanTuLeNhoNhat(int& res) const;
    bool timSoNguyenToLonNhat(int& res) const;
    void sapXepTangDan();
    void sapXepGiamDan();
};

bool cArray::isPrime(int num) const {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void cArray::quickSort(int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(left, j);
    quickSort(i, right);
}

cArray::cArray() {
    arr = nullptr;
    n = 0;
}

cArray::~cArray() {
    if (arr != nullptr) {
        delete[] arr;
    }
}

void cArray::nhapMang(int size) {
    if (arr != nullptr) {
        delete[] arr;
    }
    n = size;
    arr = new int[n];
    cout << "Moi nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

void cArray::taoMangNgauNhien(int size) {
    if (arr != nullptr) {
        delete[] arr;
    }
    n = size;
    arr = new int[n];
    
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }
}

void cArray::xuatMang() const {
    if (n == 0) {
        cout << "Mang rong!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int cArray::demSoLanXuatHien(int x) const {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

bool cArray::kiemTraTangDan() const {
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool cArray::timPhanTuLeNhoNhat(int& res) const {
    bool found = false;
    int minOdd = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            found = true;
        }
    }
    if (found) res = minOdd;
    return found;
}

bool cArray::timSoNguyenToLonNhat(int& res) const {
    bool found = false;
    int maxPrime = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i]) && arr[i] > maxPrime) {
            maxPrime = arr[i];
            found = true;
        }
    }
    if (found) res = maxPrime;
    return found;
}

void cArray::sapXepTangDan() {
    if (n > 1) {
        quickSort(0, n - 1);
    }
}

void cArray::sapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

void hienThiMenu() {
    cArray a;
    int luaChon;
    int size = 0;

    do {
        cout << "\n================= MENU =================\n";
        cout << "1. Nhap mang thu cong\n";
        cout << "2. Tao mang ngau nhien\n";
        cout << "3. Xuat mang\n";
        cout << "4. Dem so lan xuat hien cua x\n";
        cout << "5. Kiem tra mang co tang dan khong\n";
        cout << "6. Tim so le nho nhat\n";
        cout << "7. Tim so nguyen to lon nhat\n";
        cout << "8. Sap xep mang TANG DAN (Quick Sort)\n";
        cout << "9. Sap xep mang GIAM DAN (Selection Sort)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "========================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "Nhap so luong phan tu: ";
                cin >> size;
                a.nhapMang(size);
                cout << "=> Nhap mang thanh cong!\n";
                break;
            case 2:
                cout << "Nhap so luong phan tu can tao ngau nhien: ";
                cin >> size;
                a.taoMangNgauNhien(size);
                cout << "=> Da tao mang ngau nhien!\n";
                break;
            case 3:
                cout << "Cac phan tu trong mang: ";
                a.xuatMang();
                break;
            case 4: {
                int x;
                cout << "Nhap gia tri x can dem: ";
                cin >> x;
                cout << "So lan xuat hien cua " << x << " la: " << a.demSoLanXuatHien(x) << " lan\n";
                break;
            }
            case 5:
                if (a.kiemTraTangDan()) cout << "=> Mang dang sap xep tang dan.\n";
                else cout << "=> Mang KHONG tang dan.\n";
                break;
            case 6: {
                int minOdd;
                if (a.timPhanTuLeNhoNhat(minOdd)) cout << "=> So le nho nhat trong mang: " << minOdd << "\n";
                else cout << "=> Khong co so le nao trong mang.\n";
                break;
            }
            case 7: {
                int maxPrime;
                if (a.timSoNguyenToLonNhat(maxPrime)) cout << "=> So nguyen to lon nhat trong mang: " << maxPrime << "\n";
                else cout << "=> Khong co so nguyen to nao trong mang.\n";
                break;
            }
            case 8:
                a.sapXepTangDan();
                cout << "=> Da sap xep TANG DAN.\n";
                break;
            case 9:
                a.sapXepGiamDan();
                cout << "=> Da sap xep GIAM DAN.\n";
                break;
            case 0:
                cout << "Thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    } while (luaChon != 0);
}
int main() {
    hienThiMenu();
    return 0;
}

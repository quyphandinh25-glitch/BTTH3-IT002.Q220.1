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

int main() {
    cArray a;
    int size, x;
    int minOdd, maxPrime;
    
    cout << "Nhap kich thuoc mang: ";
    cin >> size;
    cout << "Nhap so x can dem: ";
    cin >> x;

    a.taoMangNgauNhien(size);

    cout << "\n[Mang ban dau]: ";
    a.xuatMang();

    cout << "[Tinh chat] -> Tang dan: " << (a.kiemTraTangDan() ? "Co" : "Khong") 
         << " | Le Min: " << (a.timPhanTuLeNhoNhat(minOdd) ? to_string(minOdd) : "Khong") 
         << " | SNT Max: " << (a.timSoNguyenToLonNhat(maxPrime) ? to_string(maxPrime) : "Khong") 
         << " | Dem x(" << x << "): " << a.demSoLanXuatHien(x) << " lan\n";
    
    a.sapXepTangDan();
    cout << "[Xep tang dan]: "; 
    a.xuatMang();

    a.sapXepGiamDan();
    cout << "[Xep giam dan]: "; 
    a.xuatMang();

    return 0;
}

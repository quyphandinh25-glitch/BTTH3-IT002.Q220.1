#include <bits/stdc++.h>

using namespace std;

class cArray {
private:
    int* arr;
    int n;

    bool isPrime(int num) const {
        if (num < 2) return false;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    
    void quickSort(int left, int right) {
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

public:
 
    cArray() {
        arr = nullptr;
        n = 0;
    }

    ~cArray() {
        if (arr != nullptr) {
            delete[] arr;
        }
    }

    void taoMangNgauNhien(int size) {
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

    void xuatMang() const {
        if (n == 0) {
            cout << "Mang rong!\n";
            return;
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int demSoLanXuatHien(int x) const {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                count++;
            }
        }
        return count;
    }

    bool kiemTraTangDan() const {
        if (n <= 1) return true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    bool timPhanTuLeNhoNhat(int& res) const {
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

    bool timSoNguyenToLonNhat(int& res) const {
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

    void sapXepTangDan() {
        if (n > 1) {
            quickSort(0, n - 1);
        }
    }

    void sapXepGiamDan() {
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
};

int main() {
    cArray a;
    int size = 10;
    
    cout << "--- KHOI TAO MANG NGAU NHIEN ---\n";
    a.taoMangNgauNhien(size);
    cout << "Cac phan tu trong mang: ";
    a.xuatMang();

    cout << "\n--- XU LY CAC THAO TAC ---\n";
   
    int x;
    cout << "Nhap gia tri x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << a.demSoLanXuatHien(x) << " lan\n";

    
    if (a.kiemTraTangDan()) {
        cout << "Mang dang sap xep tang dan.\n";
    } else {
        cout << "Mang KHONG tang dan.\n";
    }

    
    int minOdd;
    if (a.timPhanTuLeNhoNhat(minOdd)) {
        cout << "So le nho nhat trong mang: " << minOdd << "\n";
    } else {
        cout << "Khong co so le nao trong mang.\n";
    }

    int maxPrime;
    if (a.timSoNguyenToLonNhat(maxPrime)) {
        cout << "So nguyen to lon nhat trong mang: " << maxPrime << "\n";
    } else {
        cout << "Khong co so nguyen to nao trong mang.\n";
    }

    cout << "\n--- SAP XEP MANG ---\n";
    
    a.sapXepTangDan();
    cout << "Mang sau khi sap xep TANG DAN (Quick Sort): ";
    a.xuatMang();

    cout << "Kiem tra lai: Mang co tang dan khong? -> " << (a.kiemTraTangDan() ? "Co" : "Khong") << "\n";

    a.sapXepGiamDan();
    cout << "Mang sau khi sap xep GIAM DAN (Selection Sort): ";
    a.xuatMang();

    return 0;
}

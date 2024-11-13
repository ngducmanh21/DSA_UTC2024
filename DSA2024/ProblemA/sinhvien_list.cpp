#include "sinhvien.cpp"
#include <iostream>
#include <list>
#include <iomanip>

#ifndef _SINH_VIEN_LIST_CPP_
#define _SINH_VIEN_LIST_CPP_

using namespace std;

class ListSinhVien {
    list<SinhVien> a;

public:
    ListSinhVien() {}
    ListSinhVien(list<SinhVien> a) {
        this->a = a;
    }
    size_t size() {
        return a.size();
    }
    bool _filter(SinhVien x) {
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (x._msv() == it->_msv()) {
                cout << "Ma sinh vien da ton tai trong danh sach!" << endl;
                return false;
            }
        }
        return true;
    }
    void create() {
        while (true) {
            SinhVien x;
            cin >> x;
            if (_filter(x)) {
                a.push_back(x);
            } else {
                cout << "Xin vui long nhap lai!\n";
                continue;
            }
            string t;
            while (true) {
                cout << "Ban co muon nhap them khong (y/n): ";
                cin >> t;
                if (t == "y" || t == "n") break;
                else cout << "Khong hop le. Xin vui long nhap lai\n";
            }
            if (t == "n") break;
        }
    }
    list<SinhVien>::iterator search(int msv) {
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (msv == it->_msv()) {
                return it;
            }
        }
        return a.end();
    }

    list<list<SinhVien>::iterator> searchTheoTen(string name) {
        list<list<SinhVien>::iterator> x;
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (name == it->_hoTen()) {
                x.push_back(it);
            }
        }
        return x;
    }

    list<SinhVien>::iterator _end() {
        return a.end();
    }
    void remove(list<SinhVien>::iterator it) {
        a.erase(it);
    }

    void edit(list<SinhVien>::iterator it) {
        while (true) {
            cout << "Sua doi thong tin sinh vien ma so: " << it->_msv() << ":\n\t1. Ho va ten\n\t2. Ngay sinh\n\t3. Gioi Tinh\n\t4. Lop\n\t5. Thoat sua thong tin\nXin vui long nhap so: ";
            int n;
            cin >> n;
            cin.ignore();
            if (n == 1) {
                string name;
                cout << "Nhap ten moi: ";
                getline(cin, name);
                it->_set_hoTen(name);
            } else if (n == 2) {
                string ngaySinh;
                cout << "Nhap ngay sinh moi: ";
                getline(cin, ngaySinh);
                it->_set_ngaySinh(ngaySinh);
            } else if (n == 3) {
                string gioiTinh;
                cout << "Nhap gioi tinh moi: ";
                getline(cin, gioiTinh);
                it->_set_gioiTinh(gioiTinh);
            } else if (n == 4) {
                string lop;
                cout << "Nhap lop moi: ";
                getline(cin, lop);
                it->_set_lop(lop);
            } else if (n == 5) {
                break;
            } else {
                cout << "Khong hop le xin vui long nhap lai\n";
                continue;
            }
            char t;
            cout << "Ban co muon sua lai thong tin khach hang nay (y de tiep tuc sua): ";
            cin >> t;
            if (t != 'y') break;
        }
    }

    void display() {
        cout << left << setw(20) << "Ma Sinh Vien" << setw(30) << "Ho va Ten" << setw(20) << "Ngay Sinh" << setw(20) << "Gioi Tinh" << setw(20) << "Lop" << '\n';
        for (auto it = a.begin(); it != a.end(); ++it) {
            cout << (*it);
        }
        cout << "\n-------------------------------------------------------------------------------------------------------\n";
        system("pause");
    }
    void del() {
        a.clear();
        cout << "Da xoa danh sach sinh vien cu. Hay nhap danh sach moi\n";
    }
    inline void sort() {
        a.sort([](SinhVien &sv1, SinhVien &sv2) {
            if (sv1._lop() != sv2._lop())
                return sv1._lop() < sv2._lop();
            return sv1._hoTen() < sv2._hoTen();
        });

        cout << left << setw(20) << "Ma Sinh Vien" << setw(30) << "Ho va Ten" << setw(20) << "Ngay Sinh" << setw(20) << "Gioi Tinh" << setw(20) << "Lop" << '\n';
        for (auto it = a.begin(); it != a.end(); ++it) {
            cout << (*it);
        }
        cout << "\n-------------------------------------------------------------------------------------------------------\n";
        system("pause");
    }
};
#endif

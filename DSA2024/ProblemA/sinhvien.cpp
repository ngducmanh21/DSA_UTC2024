#include <bits/stdc++.h>
#ifndef SINH_VIEN_CPP
#define SINH_VIEN_CPP

using namespace std;

class SinhVien {
    private:
        int msv;
        string hoTen, ngaySinh, gioiTinh, lop;
    public:
        SinhVien(int msv, string hoTen, string ngaySinh, string gioiTinh, string lop) {
            this->msv = msv;
            this->hoTen = hoTen;
            this->ngaySinh = ngaySinh;
            this->lop=lop;
        }
        SinhVien() {}
        int _msv() {
            return this->msv;
        }
        string _hoTen() {
            return hoTen;
        }
        string _ngaySinh() {
            return ngaySinh;
        }
        string _lop() {
            return lop;
        }
        void _set_msv(int msv) {
            this->msv = msv;
        }
        void _set_hoTen(string name) {
            this->hoTen = name;
        }
        void _set_ngaySinh(string ngaySinh) {
            this->ngaySinh = ngaySinh;
        }
        void _set_gioiTinh(string gioiTinh) {
            this->gioiTinh = gioiTinh;
        }
        void _set_lop(string lop) {
            this->lop = lop;
        }
        friend istream &operator>>(istream& is, SinhVien& a) {
            cout << "\tNhap ma sinh vien: ";
            is >> a.msv;
            is.ignore();
            cout << "\tNhap ten sinh vien: ";
            getline(is, a.hoTen);
            cout << "\tNhap ngay sinh cua sinh vien: ";
            getline(is, a.ngaySinh);
            cout << "\tNhap gioi tinh cua sinh vien: ";
            getline(is, a.gioiTinh);
            cout << "\tLop cua sinh vien: ";
            getline(is, a.lop);
            return is;
        }
        friend ostream &operator<<(ostream& out,const SinhVien& a) {
            out << left << setw(20) << a.msv << setw(30) << a.hoTen << setw(20) << a.ngaySinh << setw(20) << a.gioiTinh << setw(20) << a.lop << '\n';
            return out;
        }       
        SinhVien &operator=(const SinhVien &x) {
            this->msv = x.msv;
            this->gioiTinh = x.gioiTinh;
            this->hoTen = x.hoTen;
            this->lop = x.lop;
            this->ngaySinh = x.ngaySinh;
            return *this;
        }
};

#endif
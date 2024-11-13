#include <iostream>
#include "sinhvien_list.cpp"
#ifndef APP_CPP
#define APP_CPP

class App {
    ListSinhVien a;

public:
    void run() {
        home();
        end();
    }

private:
    void home() {
        while (true) {
            system("cls");
            cout << "\t--------------------------^-^------------------------------\n";
            cout << "\t1. Tao danh sach sinh vien moi\n";
            cout << "\t2. Them mot sinh vien moi\n";
            cout << "\t3. Xem danh sach sinh vien\n";
            cout << "\t4. Tim kiem sinh vien\n";
            cout << "\t5. Xoa mot sinh vien\n";
            cout << "\t6. Sap xep sinh vien\n";
            cout << "\t7. Thoat chuong trinh\n";
            cout << "\t-----------------------------------------------------------\n";
            cout << "Chon thao tac: ";
            int n;
            cin >> n;

            switch (n) {
                case 1: create(); break;
                case 2: add(); break;
                case 3: show(); break;
                case 4: search(); break;
                case 5: remove(); break;
                case 6: sort(); break;
                case 7: return; // Thoát chương trình
                default: 
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    break;
            }
        }
    }

    void create() {
        a.create();
    }

    void add() {
        a.create();
    }

    void show() {
        system("cls");
        a.display();
        system("pause");
    }

    void search() {
        system("cls");
        int choice;
        cout << "Tim kiem theo:\n1. Ma sinh vien\n2. Ten sinh vien\nChon: ";
        cin >> choice;
        if (choice == 1) {
            int msv;
            cout << "Nhap ma sinh vien: ";
            cin >> msv;
            auto it = a.search(msv);
            if (it != a._end()) {
                system("cls");
                cout << "Thong tin sinh vien:\n";
                cout << *it;
            } else {
                cout << "Khong tim thay sinh vien\n";
            }
        } else if (choice == 2) {
            string name;
            cin.ignore();
            cout << "Nhap ten sinh vien: ";
            getline(cin, name);
            auto results = a.searchTheoTen(name);
            if (!results.empty()) {
                for (auto it : results) {
                    cout << *it;
                }
            } else {
                cout << "Khong tim thay sinh vien\n";
            }
        }
        system("pause");
    }

    void remove() {
        system("cls");
        int msv;
        cout << "Nhap ma sinh vien muon xoa: ";
        cin >> msv;
        auto it = a.search(msv);
        if (it != a._end()) {
            a.remove(it);
            cout << "Xoa thanh cong!\n";
        } else {
            cout << "Khong tim thay sinh vien\n";
        }
        system("pause");
    }

    void sort() {
        system("cls");
        a.sort();
        system("pause");
    }

    void end() {
        system("cls");
        cout << "\t\t    __        __" << endl;
        cout << "\t\t ********  ********" << endl;
        cout << "\t\t****____________****" << endl;
        cout << "\t\t****| Goodbye! |***" << endl;
        cout << "\t\t ***------------**" << endl;
        cout << "\t\t   *************" << endl;
        cout << "\t\t      *******" << endl;
        cout << "\t\t         *" << endl;
    }
};

#endif

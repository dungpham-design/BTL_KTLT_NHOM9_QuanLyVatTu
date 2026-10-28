#ifndef SUPPLIER_MENU_H
#define SUPPLIER_MENU_H

// Tac gia: Mai Tat Dat
#include "Supplier.h"
#include "../Repository.h"
#include "../InputHelper.h"

#include <cctype>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

// Lop menu dieu khien cac thao tac CRUD cho use case UC03.
class SupplierMenu {
private:
    Repository<Supplier>& repo;

    // Doc mot truong co the bo trong; chuoi rong duoc dung de giu nguyen gia tri.
    std::string getOptionalString(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::getline(std::cin, value);
        return value;
    }

    // Nhap va cap nhat mot truong tuy chon, bao loi neu gia tri khong hop le.
    template <typename Setter>
    void updateOptionalField(const std::string& prompt, Setter setter) {
        while (true) {
            std::string value = getOptionalString(prompt);
            if (value.empty()) {
                return;
            }
            try {
                setter(value);
                return;
            } catch (const std::exception& loi) {
                std::cout << "Loi: " << loi.what() << " Vui long nhap lai hoac Enter de giu nguyen.\n";
            }
        }
    }

    // Them nha cung cap va khong chap nhan ma da ton tai.
    void addSupplier() {
        while (true) {
            Supplier supplier;
            supplier.input();

            if (repo.findById(supplier.getId()) != nullptr) {
                std::cout << "Loi: Ma nha cung cap da ton tai. Vui long nhap lai thong tin.\n\n";
                continue;
            }

            repo.add(supplier);
            std::cout << "Them nha cung cap thanh cong.\n";
            return;
        }
    }

    // Hien thi toan bo danh sach nha cung cap.
    void showSuppliers() const {
        const std::vector<Supplier>& danhSach = repo.getAll();
        if (danhSach.empty()) {
            std::cout << "Danh sach nha cung cap dang rong.\n";
            return;
        }

        Supplier::printHeader();
        for (const Supplier& supplier : danhSach) {
            supplier.display();
        }
        std::cout << "Tong so nha cung cap: " << danhSach.size() << '\n';
    }

    // Tim va hien thi nha cung cap theo ma chinh xac.
    void searchSupplier() {
        std::string ma = InputHelper::getString("Nhap ma nha cung cap can tim: ");
        Supplier* supplier = repo.findById(ma);
        if (supplier == nullptr) {
            std::cout << "Khong tim thay nha cung cap co ma " << ma << ".\n";
            return;
        }
        Supplier::printHeader();
        supplier->display();
    }

    // Cap nhat thong tin; bo trong mot truong se giu nguyen gia tri cu.
    void updateSupplier() {
        std::string ma = InputHelper::getString("Nhap ma nha cung cap can cap nhat: ");
        Supplier* current = repo.findById(ma);
        if (current == nullptr) {
            std::cout << "Khong tim thay nha cung cap co ma " << ma << ".\n";
            return;
        }

        std::cout << "Thong tin hien tai:\n";
        Supplier::printHeader();
        current->display();
        std::cout << "Nhap gia tri moi; nhan Enter de giu nguyen gia tri cu.\n";

        Supplier updated = *current;
        updateOptionalField("Ten nha cung cap moi: ",
            [&updated](const std::string& value) { updated.setTenNhaCungCap(value); });
        updateOptionalField("Dia chi moi: ",
            [&updated](const std::string& value) { updated.setDiaChi(value); });
        updateOptionalField("So dien thoai moi: ",
            [&updated](const std::string& value) { updated.setSoDienThoai(value); });
        updateOptionalField("Email moi: ",
            [&updated](const std::string& value) { updated.setEmail(value); });

        if (repo.update(ma, updated)) {
            std::cout << "Cap nhat nha cung cap thanh cong.\n";
        } else {
            std::cout << "Cap nhat that bai. Vui long thu lai.\n";
        }
    }

    // Xoa nha cung cap sau khi nguoi dung xac nhan.
    void deleteSupplier() {
        std::string ma = InputHelper::getString("Nhap ma nha cung cap can xoa: ");
        Supplier* supplier = repo.findById(ma);
        if (supplier == nullptr) {
            std::cout << "Khong tim thay nha cung cap co ma " << ma << ".\n";
            return;
        }

        std::cout << "Nha cung cap se bi xoa:\n";
        Supplier::printHeader();
        supplier->display();
        std::string xacNhan = InputHelper::getString("Xac nhan xoa (y/n): ");
        if (xacNhan == "y" || xacNhan == "Y") {
            if (repo.remove(ma)) {
                std::cout << "Xoa nha cung cap thanh cong.\n";
            } else {
                std::cout << "Xoa that bai. Vui long thu lai.\n";
            }
        } else {
            std::cout << "Da huy thao tac xoa.\n";
        }
    }

public:
    // Khoi tao menu voi Repository quan ly du lieu nha cung cap.
    explicit SupplierMenu(Repository<Supplier>& repository) : repo(repository) {}

    // Chay menu CRUD cho UC03 - Quan ly Nha cung cap.
    void run() {
        int luaChon;
        do {
            std::cout << "\n========== UC03 - QUAN LY NHA CUNG CAP ==========\n";
            std::cout << "1. Them nha cung cap\n";
            std::cout << "2. Xem danh sach nha cung cap\n";
            std::cout << "3. Tim kiem theo ma\n";
            std::cout << "4. Cap nhat thong tin nha cung cap\n";
            std::cout << "5. Xoa nha cung cap\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "=================================================\n";

            luaChon = InputHelper::getInt("Nhap lua chon: ");
            try {
                switch (luaChon) {
                    case 1:
                        addSupplier();
                        break;
                    case 2:
                        showSuppliers();
                        break;
                    case 3:
                        searchSupplier();
                        break;
                    case 4:
                        updateSupplier();
                        break;
                    case 5:
                        deleteSupplier();
                        break;
                    case 0:
                        std::cout << "Quay lai menu chinh.\n";
                        break;
                    default:
                        std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
                }
            } catch (const std::exception& loi) {
                std::cout << "Da xay ra loi: " << loi.what() << '\n';
            }
        } while (luaChon != 0);
    }
};

#endif

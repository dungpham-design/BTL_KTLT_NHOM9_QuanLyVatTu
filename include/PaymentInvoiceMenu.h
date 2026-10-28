#ifndef PAYMENT_INVOICE_MENU_H
#define PAYMENT_INVOICE_MENU_H

// Tac gia: Mai Tat Dat
#include "Repository.h"
#include "PaymentInvoice.h"
#include "InputHelper.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

// Menu CRUD cho UC10 - Quan ly hoa don thanh toan.
class PaymentInvoiceMenu {
private:
    Repository<PaymentInvoice>& repo;

    // Doc mot truong co the de trong; Enter nghia la giu gia tri cu.
    std::string getOptionalString(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::getline(std::cin, value);
        return value;
    }

    template <typename Setter>
    void updateOptionalField(const std::string& prompt, Setter setter) {
        while (true) {
            const std::string value = getOptionalString(prompt);
            if (value.empty()) return;
            try {
                setter(value);
                return;
            } catch (const std::exception& e) {
                std::cout << "Loi: " << e.what()
                          << " Nhap lai hoac nhan Enter de giu nguyen.\n";
            }
        }
    }

    void updateOptionalAmount(PaymentInvoice& invoice) {
        while (true) {
            const std::string raw = getOptionalString("Tong tien moi (VND, Enter de giu nguyen): ");
            if (raw.empty()) return;
            try {
                std::size_t used = 0;
                const double amount = std::stod(raw, &used);
                if (used != raw.size()) throw std::invalid_argument("Tong tien chi duoc chua gia tri so.");
                invoice.setTongTien(amount);
                return;
            } catch (const std::exception& e) {
                std::cout << "Loi: " << e.what() << " Vui long nhap lai.\n";
            }
        }
    }

    void addInvoice() {
        while (true) {
            PaymentInvoice invoice;
            invoice.input();
            if (repo.findById(invoice.getId()) != nullptr) {
                std::cout << "Loi: Ma hoa don da ton tai. Vui long nhap lai.\n\n";
                continue;
            }
            repo.add(invoice); // Repository::add cua nhom tra ve void.
            std::cout << "Them hoa don thanh cong.\n";
            return;
        }
    }

    void showInvoices() const {
        const std::vector<PaymentInvoice>& list = repo.getAll();
        if (list.empty()) {
            std::cout << "Danh sach hoa don dang rong.\n";
            return;
        }
        PaymentInvoice::printHeader();
        for (const PaymentInvoice& invoice : list) invoice.display();
        std::cout << "Tong so hoa don: " << list.size() << '\n';
    }

    void searchInvoice() {
        const std::string ma = InputHelper::getString("Nhap ma hoa don can tim: ");
        PaymentInvoice* invoice = repo.findById(ma);
        if (invoice == nullptr) {
            std::cout << "Khong tim thay hoa don co ma " << ma << ".\n";
            return;
        }
        PaymentInvoice::printHeader();
        invoice->display();
    }

    void updateInvoice() {
        const std::string ma = InputHelper::getString("Nhap ma hoa don can cap nhat: ");
        PaymentInvoice* current = repo.findById(ma);
        if (current == nullptr) {
            std::cout << "Khong tim thay hoa don.\n";
            return;
        }

        std::cout << "Thong tin hien tai:\n";
        PaymentInvoice::printHeader();
        current->display();
        std::cout << "Nhap gia tri moi; nhan Enter de giu nguyen. Ma hoa don khong duoc sua.\n";

        PaymentInvoice updated = *current;
        updateOptionalField("Ma du an moi: ",
            [&updated](const std::string& value) { updated.setMaDuAn(value); });
        updateOptionalField("Ma nha cung cap moi: ",
            [&updated](const std::string& value) { updated.setMaNhaCungCap(value); });
        updateOptionalField("Ngay lap moi (dd/mm/yyyy): ",
            [&updated](const std::string& value) { updated.setNgayLap(value); });
        updateOptionalAmount(updated);
        updateOptionalField("Trang thai moi: ",
            [&updated](const std::string& value) { updated.setTrangThai(value); });
        updateOptionalField("Ghi chu moi: ",
            [&updated](const std::string& value) { updated.setGhiChu(value); });

        if (repo.update(ma, updated)) {
            std::cout << "Cap nhat hoa don thanh cong.\n";
        } else {
            std::cout << "Cap nhat that bai. Vui long thu lai.\n";
        }
    }

    void deleteInvoice() {
        const std::string ma = InputHelper::getString("Nhap ma hoa don can xoa: ");
        PaymentInvoice* invoice = repo.findById(ma);
        if (invoice == nullptr) {
            std::cout << "Khong tim thay hoa don.\n";
            return;
        }
        std::cout << "Hoa don se bi xoa:\n";
        PaymentInvoice::printHeader();
        invoice->display();
        const std::string confirm = InputHelper::getString("Xac nhan xoa (y/n): ");
        if (confirm == "y" || confirm == "Y") {
            if (repo.remove(ma)) std::cout << "Xoa hoa don thanh cong.\n";
            else std::cout << "Xoa that bai. Vui long thu lai.\n";
        } else {
            std::cout << "Da huy thao tac xoa.\n";
        }
    }

public:
    // Nhan Repository quan ly danh sach hoa don.
    explicit PaymentInvoiceMenu(Repository<PaymentInvoice>& r) : repo(r) {}

    // Chay menu CRUD cua UC10.
    void run() {
        int choice;
        do {
            std::cout << "\n============= UC10 - QUAN LY HOA DON THANH TOAN =============\n";
            std::cout << "1. Them hoa don moi\n";
            std::cout << "2. Xem danh sach hoa don\n";
            std::cout << "3. Tim kiem hoa don theo ma\n";
            std::cout << "4. Cap nhat thong tin hoa don\n";
            std::cout << "5. Xoa hoa don\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "=============================================================\n";
            choice = InputHelper::getInt("Nhap lua chon: ");
            try {
                switch (choice) {
                    case 1: addInvoice(); break;
                    case 2: showInvoices(); break;
                    case 3: searchInvoice(); break;
                    case 4: updateInvoice(); break;
                    case 5: deleteInvoice(); break;
                    case 0: std::cout << "Quay lai menu chinh.\n"; break;
                    default: std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Da xay ra loi: " << e.what() << '\n';
            }
        } while (choice != 0);
    }
};

#endif

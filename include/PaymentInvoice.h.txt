#ifndef PAYMENT_INVOICE_MENU_H
#define PAYMENT_INVOICE_MENU_H

#include "Repository.h"
#include "PaymentInvoice.h"
#include "InputHelper.h"
#include <iostream>

class PaymentInvoiceMenu {
private:
    Repository<PaymentInvoice>& repo;

public:
    PaymentInvoiceMenu(Repository<PaymentInvoice>& r) : repo(r) {}

    void run() {
        int choice = 0;
        do {
            std::cout << "\n============= QUAN LY HOA DON THANH TOAN ============\n";
            std::cout << "1. Them hoa don moi\n";
            std::cout << "2. Xem danh sach hoa don\n";
            std::cout << "3. Tim kiem hoa don theo ma\n";
            std::cout << "4. Cap nhat thong tin hoa don\n";
            std::cout << "5. Xoa hoa don\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "=====================================================\n";
            std::cout << "Nhap lua chon: ";
            choice = InputHelper::getInt();

            switch (choice) {
                case 1: {
                    PaymentInvoice inv;
                    inv.input();
                    if (repo.add(inv)) {
                        std::cout << "=> Them hoa don thanh cong!\n";
                    } else {
                        std::cout << "=> Loi: Ma hoa don da ton tai hoac khong hop le!\n";
                    }
                    break;
                }
                case 2: {
                    std::cout << "\n--- DANH SACH HOA DON THANH TOAN ---\n";
                    PaymentInvoice::printHeader();
                    auto list = repo.getAll();
                    for (const auto& inv : list) {
                        inv.display();
                    }
                    std::cout << "Tong so: " << list.size() << " hoa don.\n";
                    break;
                }
                case 3: {
                    std::cout << "Nhap ma hoa don can tim: ";
                    std::string ma = InputHelper::getString();
                    PaymentInvoice* inv = repo.findById(ma);
                    if (inv != nullptr) {
                        std::cout << "=> Tim thay thong tin:\n";
                        PaymentInvoice::printHeader();
                        inv->display();
                    } else {
                        std::cout << "=> Khong tim thay hoa don co ma: " << ma << "\n";
                    }
                    break;
                }
                case 4: {
                    std::cout << "Nhap ma hoa don can cap nhat: ";
                    std::string ma = InputHelper::getString();
                    PaymentInvoice* inv = repo.findById(ma);
                    if (inv != nullptr) {
                        std::cout << "Nhap thong tin moi:\n";
                        inv->input();
                        repo.saveToFile();
                        std::cout << "=> Cap nhat thanh cong!\n";
                    } else {
                        std::cout << "=> Khong tim thay hoa don!\n";
                    }
                    break;
                }
                case 5: {
                    std::cout << "Nhap ma hoa don can xoa: ";
                    std::string ma = InputHelper::getString();
                    if (repo.remove(ma)) {
                        std::cout << "=> Xoa thanh cong!\n";
                    } else {
                        std::cout << "=> Xoa that bai (khong tim thay ma)!\n";
                    }
                    break;
                }
                case 0:
                    std::cout << "Quay lai menu chinh.\n";
                    break;
                default:
                    std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
            }
        } while (choice != 0);
    }
};

#endif
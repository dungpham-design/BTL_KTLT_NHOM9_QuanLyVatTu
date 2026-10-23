#ifndef IMPORT_RECEIPT_MENU_H
#define IMPORT_RECEIPT_MENU_H

#include "ImportReceipt.h"
#include "Repository.h"
#include "InputHelper.h"
#include <iostream>

class ImportReceiptMenu {
private:
    Repository<ImportReceipt>& repo;

public:
    ImportReceiptMenu(Repository<ImportReceipt>& r) : repo(r) {}

    void run() {
        int choice = 0;
        do {
            std::cout << "\n================ QUAN LY PHIEU NHAP KHO ================\n";
            std::cout << "1. Lap phieu nhap moi\n";
            std::cout << "2. Xem danh sach phieu nhap\n";
            std::cout << "3. Tim kiem phieu nhap theo ma\n";
            std::cout << "4. Cap nhat thong tin phieu nhap\n";
            std::cout << "5. Xoa phieu nhap\n";
            std::cout << "0. Quay lai\n";
            std::cout << "=========================================================\n";
            std::cout << "Nhap lua chon cua ban: ";
            choice = InputHelper::getInt();

            switch (choice) {
            case 1: {
                std::cout << "\n--- LAP PHIEU NHAP KHO MOI ---\n";
                ImportReceipt item;
                item.input();
                if (repo.findById(item.getId()) != nullptr) {
                    std::cout << "Loi: Ma phieu nhap da ton tai trong he thong!\n";
                }
                else {
                    repo.add(item);
                    repo.saveToFile();
                    std::cout << "Lap phieu nhap thanh cong!\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH PHIEU NHAP KHO ---\n";
                const auto& list = repo.getAll();
                if (list.empty()) {
                    std::cout << "Danh sach trong!\n";
                }
                else {
                    ImportReceipt::printHeader();
                    for (const auto& item : list) {
                        item.display();
                    }
                }
                break;
            }
            case 3: {
                std::cout << "\n--- TIM KIEM PHIEU NHAP ---\n";
                std::cout << "Nhap ma phieu nhap can tim: ";
                std::string id = InputHelper::getString();
                ImportReceipt* found = repo.findById(id);
                if (found != nullptr) {
                    std::cout << "Tim thay phieu nhap:\n";
                    ImportReceipt::printHeader();
                    found->display();
                }
                else {
                    std::cout << "Khong tim thay phieu nhap co ma: " << id << "\n";
                }
                break;
            }
            case 4: {
                std::cout << "\n--- CAP NHAT PHIEU NHAP ---\n";
                std::cout << "Nhap ma phieu nhap can cap nhat: ";
                std::string id = InputHelper::getString();
                ImportReceipt* found = repo.findById(id);
                if (found != nullptr) {
                    std::cout << "Nhap thong tin moi:\n";
                    found->input();
                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                }
                else {
                    std::cout << "Khong tim thay phieu nhap co ma: " << id << "\n";
                }
                break;
            }
            case 5: {
                std::cout << "\n--- XOA PHIEU NHAP ---\n";
                std::cout << "Nhap ma phieu nhap can xoa: ";
                std::string id = InputHelper::getString();
                if (repo.remove(id)) {
                    repo.saveToFile();
                    std::cout << "Xoa phieu nhap thanh cong!\n";
                }
                else {
                    std::cout << "Khong tim thay phieu nhap co ma: " << id << " de xoa!\n";
                }
                break;
            }
            case 0:
                std::cout << "Quay lai menu chinh...\n";
                break;
            default:
                std::cout << "Lua chon khong hop le! Vui long chon lai.\n";
            }
        } while (choice != 0);
    }
};

#endif // IMPORT_RECEIPT_MENU_H
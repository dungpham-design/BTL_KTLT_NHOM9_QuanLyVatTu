#ifndef EXPORT_RECEIPT_MENU_H
#define EXPORT_RECEIPT_MENU_H

#include "../Repository.h"
#include "ExportReceipt.h"
#include "../InputHelper.h"
#include <iostream>

class ExportReceiptMenu {
private:
    Repository<ExportReceipt>& repository;

public:
    explicit ExportReceiptMenu(Repository<ExportReceipt>& repo) : repository(repo) {}

    void run() {
        int choice = -1;
        do {
            std::cout << "\n============ QUAN LY PHIEU XUAT KHO ============\n";
            std::cout << "1. Them phieu xuat kho m?i\n";
            std::cout << "2. Xem danh sach phieu xuat kho\n";
            std::cout << "3. Tim kiem phieu xuat theo ma\n";
            std::cout << "4. Cap nhat thong tin phieu xuat\n";
            std::cout << "5. Xoa phieu xuat kho\n";
            std::cout << "0. Quay lai\n";
            std::cout << "=================================================\n";
            choice = InputHelper::getInt("Nhap lua chon cua ban: ");

            switch (choice) {
                case 1: {
            ExportReceipt item;
            item.input();
            if (repository.findById(item.getId()) != nullptr) {
                std::cout << "Loi: Ma phieu xuat da ton tai!\n";
            } else {
                repository.add(item);
                std::cout << "Them phieu xuat thanh cong!\n";
            }
            break;
        }
                case 2: {
                    auto list = repository.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach phieu xuat kho rong!\n";
                    } else {
                        std::cout << "\n--- DANH SACH PHIEU XUAT KHO ---\n";
                        ExportReceipt::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap ma phieu xuat can tim: ");
                    ExportReceipt* item = repository.findById(id);
                    if (item) {
                        std::cout << "\nThong tin phieu xuat tim thay:\n";
                        ExportReceipt::printHeader();
                        item->display();
                    } else {
                        std::cout << "Khong tim th?y phieu xuat co ma: " << id << "\n";
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap ma phieu xuat can cap nhat: ");
                    ExportReceipt* item = repository.findById(id);
                    if (item) {
                        std::cout << "Nhap thong tin moi cho phieu xuat:\n";
                        ExportReceipt newItem;
                        newItem.input();
                        if (repository.update(id, newItem)) {
                            std::cout << "Cap nhat phieu xuat thanh cong!\n";
                        } else {
                            std::cout << "Cap nhat th?t bai!\n";
                        }
                    } else {
                        std::cout << "Khong tim th?y phieu xuat co ma: " << id << "\n";
                    }
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap ma phieu xuat can xoa: ");
                    if (repository.remove(id)) {
                        std::cout << "Xoa phieu xuat thanh cong!\n";
                    } else {
                        std::cout << "Khong tim th?y phieu xuat hoac xoa that bai!\n";
                    }
                    break;
                }
                case 0:
                    std::cout << "Tro ve menu chinh...\n";
                    break;
                default:
                    std::cout << "Lua chon khong hop le! Vui long nhap lai.\n";
                    break;
            }
        } while (choice != 0);
    }
};

#endif // EXPORT_RECEIPT_MENU_H

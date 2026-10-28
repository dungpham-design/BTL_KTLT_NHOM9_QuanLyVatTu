#ifndef MATERIAL_MENU_H
#define MATERIAL_MENU_H

#include "../Repository.h"
#include "Material.h"
#include "../InputHelper.h"
#include <iostream>

class MaterialMenu {
private:
    Repository<Material>& repository;

public:
    explicit MaterialMenu(Repository<Material>& repo) : repository(repo) {}

    void run() {
        int choice = -1;
        do {
            std::cout << "\n================ QUAN LY VAT TU ================\n";
            std::cout << "1. Them vat tu moi\n";
            std::cout << "2. Xem danh sach vat tu\n";
            std::cout << "3. Tim kiem vat tu theo ma\n";
            std::cout << "4. Cap nhat thong tin vat tu\n";
            std::cout << "5. Xoa vat tu\n";
            std::cout << "0. Quay lai\n";
            std::cout << "=================================================\n";
            choice = InputHelper::getInt("Nhap lua chon cua ban: ");

            switch (choice) {
                case 1: {
    Material item;
    item.input();
    if (repository.findById(item.getId()) != nullptr) {
        std::cout << "Loi: Ma vat tu da ton tai!\n";
    } else {
        repository.add(item);
        std::cout << "Them vat tu thanh cong!\n";
    }
    break;
}
                case 2: {
                    auto list = repository.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach vat tu rong!\n";
                    } else {
                        std::cout << "\n--- DANH SACH VAT TU ---\n";
                        Material::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap ma vat tu can tim: ");
                    Material* item = repository.findById(id);
                    if (item) {
                        std::cout << "\nThong tin vat tu tim thay:\n";
                        Material::printHeader();
                        item->display();
                    } else {
                        std::cout << "Khong tim th?y vat tu co ma: " << id << "\n";
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap ma vat tu can cap nhat: ");
                    Material* item = repository.findById(id);
                    if (item) {
                        std::cout << "Nhap thong tin moi cho vat tu:\n";
                        Material newItem;
                        newItem.input();
                        if (repository.update(id, newItem)) {
                            std::cout << "Cap nhat thanh cong!\n";
                        } else {
                            std::cout << "Cap nhat th?t b?i!\n";
                        }
                    } else {
                        std::cout << "Khong tim thay vat tu co ma: " << id << "\n";
                    }
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap ma vat tu can xoa: ");
                    if (repository.remove(id)) {
                        std::cout << "Xoa vat tu thanh cong!\n";
                    } else {
                        std::cout << "Khong tim th?y vat tu hoac xoa that bai!\n";
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

#endif // MATERIAL_MENU_H

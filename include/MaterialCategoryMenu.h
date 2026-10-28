#ifndef MATERIAL_CATEGORY_MENU_H
#define MATERIAL_CATEGORY_MENU_H

#include "MaterialCategory.h"
#include "../Repository.h"
#include "../InputHelper.h"
#include <iostream>

class MaterialCategoryMenu {
private:
    Repository<MaterialCategory>& repo;

public:
    MaterialCategoryMenu(Repository<MaterialCategory>& r) : repo(r) {}

    void run() {
        int choice = 0;
        do {
            std::cout << "\n================ QUAN LY DANH MUC VAT TU ================\n";
            std::cout << "1. Them danh muc moi\n";
            std::cout << "2. Xem danh sach danh muc\n";
            std::cout << "3. Tim kiem danh muc theo ma\n";
            std::cout << "4. Cap nhat thong tin danh muc\n";
            std::cout << "5. Xoa danh muc\n";
            std::cout << "0. Quay lai\n";
            std::cout << "=========================================================\n";
            std::cout << "Nhap lua chon cua ban: ";
            choice = InputHelper::getInt("");

            switch (choice) {
            case 1: {
                std::cout << "\n--- THEM DANH MUC MOI ---\n";
                MaterialCategory item;
                item.input();
                if (repo.findById(item.getId()) != nullptr) {
                    std::cout << "Loi: Ma danh muc da ton tai trong he thong!\n";
                }
                else {
                    repo.add(item);
                    repo.saveToFile();
                    std::cout << "Them danh muc thanh cong!\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n--- DANH SACH DANH MUC VAT TU ---\n";
                const auto& list = repo.getAll();
                if (list.empty()) {
                    std::cout << "Danh sach trong!\n";
                }
                else {
                    MaterialCategory::printHeader();
                    for (const auto& item : list) {
                        item.display();
                    }
                }
                break;
            }
            case 3: {
                std::cout << "\n--- TIM KIEM DANH MUC ---\n";
                std::cout << "Nhap ma danh muc can tim: ";
                std::string id = InputHelper::getString("");
                MaterialCategory* found = repo.findById(id);
                if (found != nullptr) {
                    std::cout << "Tim thay danh muc:\n";
                    MaterialCategory::printHeader();
                    found->display();
                }
                else {
                    std::cout << "Khong tim thay danh muc co ma: " << id << "\n";
                }
                break;
            }
            case 4: {
                std::cout << "\n--- CAP NHAT DANH MUC ---\n";
                std::cout << "Nhap ma danh muc can cap nhat: ";
                std::string id = InputHelper::getString("");
                MaterialCategory* found = repo.findById(id);
                if (found != nullptr) {
                    std::cout << "Nhap thong tin moi:\n";
                    found->input();
                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                }
                else {
                    std::cout << "Khong tim thay danh muc co ma: " << id << "\n";
                }
                break;
            }
            case 5: {
                std::cout << "\n--- XOA DANH MUC ---\n";
                std::cout << "Nhap ma danh muc can xoa: ";
                std::string id = InputHelper::getString("");
                if (repo.remove(id)) {
                    repo.saveToFile();
                    std::cout << "Xoa danh muc thanh cong!\n";
                }
                else {
                    std::cout << "Khong tim thay danh muc co ma: " << id << " de xoa!\n";
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

#endif // MATERIAL_CATEGORY_MENU_H
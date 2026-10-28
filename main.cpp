#include <iostream>
#include "Repository.h"
#include "include/Material.h"
#include "include/MaterialMenu.h"
#include "InputHelper.h"

int main() {
    // 1. Khoi tao repository va nap du lieu tu file
    Repository<Material> materialRepo("data/vattu.txt");
    materialRepo.load();

    // 2. Khoi tao Menu cho Sinh vien 2
    MaterialMenu materialMenu(materialRepo);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n================ PHAN HE SINH VIEN 2 ================\n";
        std::cout << "1. Quan ly Vat tu (UC02)\n";
        std::cout << "0. Thoat phan he\n";
        std::cout << "=====================================================\n";
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                materialMenu.run(); // Mo Menu con UC02
                break;
            case 0:
                std::cout << "Thoat phan he Sinh vien 2 thanh cong!\n";
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long nhap lai!\n";
                break;
        }
    }

    return 0;
}

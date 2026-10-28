#include <iostream>
#include "Repository.h"
<<<<<<< HEAD
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
=======
#include "include/Warehouse.h"
#include "include/WarehouseMenu.h"
#include "include/Project.h"
#include "include/ProjectMenu.h"
#include "InputHelper.h"

int main() {
    // 1. Kh?i t?o repository n?p d? li?u t? file
    Repository<Warehouse> warehouseRepo("data/warehouses.txt");
    Repository<Project> projectRepo("data/projects.txt");

    // 2. Kh?i t?o Menu cho 2 Use Case c?a Sinh viên 4
    WarehouseMenu warehouseMenu(warehouseRepo);
    ProjectMenu projectMenu(projectRepo);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n================ PHAN HE SINH VIEN 4 ================\n";
        std::cout << "1. Quan ly Kho (UC04)\n";
        std::cout << "2. Quan ly Du an trien khai (UC06)\n";
        std::cout << "0. Thoat phan he\n";
        std::cout << "======================================================\n";
>>>>>>> 5d649cd344c200d00e33d63b23d7220414ef4206
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
<<<<<<< HEAD
                materialMenu.run(); // Mo Menu con UC02
                break;
            case 0:
                std::cout << "Thoat phan he Sinh vien 2 thanh cong!\n";
=======
                warehouseMenu.run(); // M? Menu con UC04
                break;
            case 2:
                projectMenu.run(); // M? Menu con UC06
                break;
            case 0:
                std::cout << "Thoat phan he Sinh vien 4 thanh cong!\n";
>>>>>>> 5d649cd344c200d00e33d63b23d7220414ef4206
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long nhap lai!\n";
                break;
        }
    }

    return 0;
}

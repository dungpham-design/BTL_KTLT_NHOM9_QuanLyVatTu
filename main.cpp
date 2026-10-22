#include <iostream>
#include "Repository.h"
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
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                warehouseMenu.run(); // M? Menu con UC04
                break;
            case 2:
                projectMenu.run(); // M? Menu con UC06
                break;
            case 0:
                std::cout << "Thoat phan he Sinh vien 4 thanh cong!\n";
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long nhap lai!\n";
                break;
        }
    }

    return 0;
}

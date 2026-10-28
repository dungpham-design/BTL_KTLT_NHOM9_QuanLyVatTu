#include <iostream>
#include "../Repository.h"
#include "../include/Material.h"
#include "../include/MaterialMenu.h"
#include "../include/ExportReceipt.h"
#include "../include/ExportReceiptMenu.h"
#include "../InputHelper.h"

int main() {
    // 1. Khoi tao repository cho 2 Use Case cua SV2 (da tu dong doc file)
    Repository<Material> materialRepo("data/vattu.txt");
    Repository<ExportReceipt> exportRepo("data/export_receipts.txt");

    // 2. Khoi tao Menu
    MaterialMenu materialMenu(materialRepo);
    ExportReceiptMenu exportMenu(exportRepo);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n================ PHAN HE SINH VIEN 2 ================\n";
        std::cout << "1. Quan ly Vat tu (UC02)\n";
        std::cout << "2. Quan ly Phieu xuat kho (UC08)\n";
        std::cout << "0. Thoat phan he\n";
        std::cout << "=====================================================\n";
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                materialMenu.run();
                break;
            case 2:
                exportMenu.run();
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

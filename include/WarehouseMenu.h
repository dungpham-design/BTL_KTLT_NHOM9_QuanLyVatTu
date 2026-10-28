#ifndef WAREHOUSE_MENU_H
#define WAREHOUSE_MENU_H

#include "Repository.h"
#include "Warehouse.h"
#include "InputHelper.h"

class WarehouseMenu {
private:
    Repository<Warehouse>& repo;

public:
    WarehouseMenu(Repository<Warehouse>& r) : repo(r) {}

    void run() {
        int choice = -1;
        while (choice != 0) {
            std::cout << "\n========== QUAN LY KHO (UC04) ==========\n";
            std::cout << "1. Them kho moi\n";
            std::cout << "2. Xem danh sach kho\n";
            std::cout << "3. Tim kiem kho theo ma\n";
            std::cout << "4. Cap nhat thong tin kho\n";
            std::cout << "5. Xoa kho\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "========================================\n";
            choice = InputHelper::getInt("Nhap lua chon: ");

            switch (choice) {
                case 1: {
                    std::cout << "\n--- THEM KHO MOI ---\n";
                    std::string id = InputHelper::getString("Nhap Ma kho: ");
                    if (repo.findById(id) != nullptr) {
                        std::cout << "Loi: Ma kho da ton tai!\n";
                        break;
                    }
                    Warehouse wh;
                    wh.setMaKho(id);
                    wh.setTenKho(InputHelper::getString("Nhap Ten kho: "));
                    wh.setDiaChiKho(InputHelper::getString("Nhap Dia chi kho: "));
                    wh.setNguoiQuanLy(InputHelper::getString("Nhap Ho ten nguoi quan ly: "));
                    wh.setSucChua(InputHelper::getInt("Nhap Suc chua kho (m2): "));

                    repo.add(wh);
                    std::cout << "Them kho thanh cong!\n";
                    break;
                }
                case 2: {
                    std::cout << "\n--- DANH SACH KHO ---\n";
                    auto list = repo.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach trong!\n";
                    } else {
                        Warehouse::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap Ma kho can tim: ");
                    auto ptr = repo.findById(id);
                    if (ptr) {
                        std::cout << "\nThong tin tim thay:\n";
                        Warehouse::printHeader();
                        ptr->display();
                    } else {
                        std::cout << "Khong tim thay kho co ma: " << id << std::endl;
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap Ma kho can sua: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay ma phu hop!\n";
                        break;
                    }
                    std::cout << "\nThong tin hien tai:\n";
                    Warehouse::printHeader();
                    ptr->display();

                    std::cout << "\nNhap thong tin moi (Nhan Enter de giu nguyen):\n";
                    std::string val;

                    std::cout << "Ten kho moi (" << ptr->getTenKho() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setTenKho(val);

                    std::cout << "Dia chi kho moi (" << ptr->getDiaChiKho() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setDiaChiKho(val);

                    std::cout << "Nguoi quan ly moi (" << ptr->getNguoiQuanLy() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setNguoiQuanLy(val);

                    std::cout << "Suc chua moi (" << ptr->getSucChua() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setSucChua(std::stoi(val));

                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap Ma kho can xoa: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay kho!\n";
                        break;
                    }
                    ptr->display();
                    std::string confirm = InputHelper::getString("Ban co chac chan muon xoa kho nay? (y/n): ");
                    if (confirm == "y" || confirm == "Y") {
                        if (repo.remove(id)) {
                            std::cout << "Xoa thanh cong!\n";
                        } else {
                            std::cout << "Xoa that bai!\n";
                        }
                    } else {
                        std::cout << "Da huy thao tac xoa.\n";
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Lua chon khong hop le!\n";
            }
        }
    }
};

#endif

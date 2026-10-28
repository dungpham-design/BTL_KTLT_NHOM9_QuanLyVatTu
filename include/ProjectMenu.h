#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "../Repository.h"
#include "Project.h"
#include "../InputHelper.h"

class ProjectMenu {
private:
    Repository<Project>& repo;

public:
    ProjectMenu(Repository<Project>& r) : repo(r) {}

    void run() {
        int choice = -1;
        while (choice != 0) {
            std::cout << "\n========== QUAN LY DU AN TRIEN KHAI (UC06) ==========\n";
            std::cout << "1. Them du an moi\n";
            std::cout << "2. Xem danh sach du an\n";
            std::cout << "3. Tim kiem du an theo ma\n";
            std::cout << "4. Cap nhat thong tin du an\n";
            std::cout << "5. Xoa du an\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "======================================================\n";
            choice = InputHelper::getInt("Nhap lua chon: ");

            switch (choice) {
                case 1: {
                    std::cout << "\n--- THEM DU AN MOI ---\n";
                    std::string id = InputHelper::getString("Nhap Ma du an: ");
                    if (repo.findById(id) != nullptr) {
                        std::cout << "Loi: Ma du an da ton tai!\n";
                        break;
                    }
                    Project proj;
                    proj.setMaDA(id);
                    proj.setTenDA(InputHelper::getString("Nhap Ten du an: "));
                    proj.setDiaBan(InputHelper::getString("Nhap Dia ban trien khai: "));
                    proj.setNgayBatDau(InputHelper::getString("Nhap Ngay bat dau (dd/mm/yyyy): "));
                    proj.setNgayHoanThanhDuKien(InputHelper::getString("Nhap Ngay hoan thanh du kien (dd/mm/yyyy): "));
                    proj.setTrangThai(InputHelper::getString("Nhap Trang thai (Dang thi cong / Hoan thanh / Tam dung): "));

                    repo.add(proj);
                    std::cout << "Them du an thanh cong!\n";
                    break;
                }
                case 2: {
                    std::cout << "\n--- DANH SACH DU AN TRIEN KHAI ---\n";
                    auto list = repo.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach trong!\n";
                    } else {
                        Project::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap Ma du an can tim: ");
                    auto ptr = repo.findById(id);
                    if (ptr) {
                        std::cout << "\nThong tin du an tim thay:\n";
                        Project::printHeader();
                        ptr->display();
                    } else {
                        std::cout << "Khong tim thay du an co ma: " << id << std::endl;
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap Ma du an can sua: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay ma phu hop!\n";
                        break;
                    }
                    std::cout << "\nThong tin hien tai:\n";
                    Project::printHeader();
                    ptr->display();

                    std::cout << "\nNhap thong tin moi (Nhan Enter de giu nguyen):\n";
                    std::string val;

                    std::cout << "Ten du an moi (" << ptr->getTenDA() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setTenDA(val);

                    std::cout << "Dia ban moi (" << ptr->getDiaBan() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setDiaBan(val);

                    std::cout << "Ngay bat dau moi (" << ptr->getNgayBatDau() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setNgayBatDau(val);

                    std::cout << "Ngay HT du kien moi (" << ptr->getNgayHoanThanhDuKien() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setNgayHoanThanhDuKien(val);

                    std::cout << "Trang thai moi (" << ptr->getTrangThai() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setTrangThai(val);

                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap Ma du an can xoa: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay du an!\n";
                        break;
                    }
                    ptr->display();
                    std::string confirm = InputHelper::getString("Ban co chac chan muon xoa du an nay? (y/n): ");
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

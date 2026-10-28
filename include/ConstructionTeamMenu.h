#ifndef CONSTRUCTION_TEAM_MENU_H
#define CONSTRUCTION_TEAM_MENU_H

#include "Repository.h"
#include "ConstructionTeam.h"
#include "InputHelper.h"

class ConstructionTeamMenu {
private:
    Repository<ConstructionTeam>& repo;

public:
    ConstructionTeamMenu(Repository<ConstructionTeam>& r) : repo(r) {}

    void run() {
        int choice = -1;
        while (choice != 0) {
            std::cout << "\n========== QUAN LY DOI THI CONG (UC05) ==========\n";
            std::cout << "1. Them doi thi cong moi\n";
            std::cout << "2. Xem danh sach doi thi cong\n";
            std::cout << "3. Tim kiem doi thi cong theo ma\n";
            std::cout << "4. Cap nhat thong tin doi thi cong\n";
            std::cout << "5. Xoa doi thi cong\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "=================================================\n";
            choice = InputHelper::getInt("Nhap lua chon: ");

            switch (choice) {
                case 1: {
                    ConstructionTeam team;
                    std::cout << "\n--- THEM DOI THI CONG MOI ---\n";
                    std::string id = InputHelper::getString("Nhap Ma doi thi cong: ");
                    if (repo.findById(id) != nullptr) {
                        std::cout << "Loi: Ma doi thi cong da ton tai!\n";
                        break;
                    }
                    team.setMaDoiTC(id);
                    team.setTenDoi(InputHelper::getString("Nhap Ten doi thi cong: "));
                    team.setDoiTruong(InputHelper::getString("Nhap Ho ten doi truong: "));
                    team.setSoDienThoai(InputHelper::getString("Nhap So dien thoai: "));
                    team.setSoLuongNhanSu(InputHelper::getInt("Nhap So luong nhan su: "));

                    repo.add(team);
                    std::cout << "Them doi thi cong thanh cong!\n";
                    break;
                }
                case 2: {
                    std::cout << "\n--- DANH SACH DOI THI CONG ---\n";
                    auto list = repo.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach trong!\n";
                    } else {
                        ConstructionTeam::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap Ma doi thi cong can tim: ");
                    auto ptr = repo.findById(id);
                    if (ptr) {
                        std::cout << "\nThong tin tim thay:\n";
                        ConstructionTeam::printHeader();
                        ptr->display();
                    } else {
                        std::cout << "Khong tim thay doi thi cong co ma: " << id << std::endl;
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap Ma doi thi cong can sua: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay ma phu hop!\n";
                        break;
                    }
                    std::cout << "\nThong tin hien tai:\n";
                    ConstructionTeam::printHeader();
                    ptr->display();

                    std::cout << "\nNhap thông tin moi (Nhan Enter de giu nguyen):\n";
                    std::string val;

                    std::cout << "Ten doi moi (" << ptr->getTenDoi() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setTenDoi(val);

                    std::cout << "Doi truong moi (" << ptr->getDoiTruong() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setDoiTruong(val);

                    std::cout << "SĐT moi (" << ptr->getSoDienThoai() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setSoDienThoai(val);

                    std::cout << "So nhan su moi (" << ptr->getSoLuongNhanSu() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setSoLuongNhanSu(std::stoi(val));

                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap Ma doi thi cong can xoa: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay doi thi cong!\n";
                        break;
                    }
                    ptr->display();
                    std::string confirm = InputHelper::getString("Ban co chac chan muon xoa? (y/n): ");
                    if (confirm == "y" || confirm == "Y") {
                        if (repo.remove(id)) {
                            std::cout << "Xoa thanh cong!\n";
                        } else {
                            std::cout << "Xoa thất bại!\n";
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
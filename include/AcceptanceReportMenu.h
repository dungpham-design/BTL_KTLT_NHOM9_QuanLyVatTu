#ifndef ACCEPTANCE_REPORT_MENU_H
#define ACCEPTANCE_REPORT_MENU_H

#include "../Repository.h"
#include "AcceptanceReport.h"
#include "ConstructionTeam.h"
#include "../InputHelper.h"

class AcceptanceReportMenu {
private:
    Repository<AcceptanceReport>& repo;
    Repository<ConstructionTeam>& teamRepo; // Tham chiếu đến repo Đội thi công để kiểm tra ràng buộc

public:
    AcceptanceReportMenu(Repository<AcceptanceReport>& r, Repository<ConstructionTeam>& tr) 
        : repo(r), teamRepo(tr) {}

    void run() {
        int choice = -1;
        while (choice != 0) {
            std::cout << "\n========== QUAN LY PHIEU NGHIEM THU (UC09) ==========\n";
            std::cout << "1. Them phieu nghiem thu moi\n";
            std::cout << "2. Xem danh sach phieu nghiem thu\n";
            std::cout << "3. Tim kiem phieu nghiem thu theo ma\n";
            std::cout << "4. Cap nhat phieu nghiem thu\n";
            std::cout << "5. Xoa phieu nghiem thu\n";
            std::cout << "0. Quay lai menu chinh\n";
            std::cout << "======================================================\n";
            choice = InputHelper::getInt("Nhap lua chon: ");

            switch (choice) {
                case 1: {
                    std::cout << "\n--- THEM PHIEU NGHIEM THU MOI ---\n";
                    std::string id = InputHelper::getString("Nhap Ma phieu nghiem thu: ");
                    if (repo.findById(id) != nullptr) {
                        std::cout << "Loi: Ma phieu nghiem thu da ton tai!\n";
                        break;
                    }

                    std::string maDTC = InputHelper::getString("Nhap Ma doi thi cong thuc hien: ");
                    if (teamRepo.findById(maDTC) == nullptr) {
                        std::cout << "Canh bao: Ma doi thi cong '" << maDTC << "' chua ton tai trong he thong!\n";
                    }

                    AcceptanceReport report;
                    report.setMaPNT(id);
                    report.setMaDA(InputHelper::getString("Nhap Ma du an: "));
                    report.setMaDoiTC(maDTC);
                    report.setNgayNghiemThu(InputHelper::getString("Nhap Ngay nghiem thu (dd/mm/yyyy): "));
                    report.setDanhGia(InputHelper::getString("Nhap Danh gia (Dat/Khong dat): "));
                    
                    double cp;
                    while (true) {
                        std::cout << "Nhap Chi phi nghiem thu (VND): ";
                        if (std::cin >> cp && cp >= 0) {
                            std::cin.ignore(10000, '\n');
                            break;
                        }
                        std::cout << "Loi: Nhap so duong!\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                    }
                    report.setChiPhi(cp);

                    repo.add(report);
                    std::cout << "Them phieu nghiem thu thanh cong!\n";
                    break;
                }
                case 2: {
                    std::cout << "\n--- DANH SACH PHIEU NGHIEM THU ---\n";
                    auto list = repo.getAll();
                    if (list.empty()) {
                        std::cout << "Danh sach trong!\n";
                    } else {
                        AcceptanceReport::printHeader();
                        for (const auto& item : list) {
                            item.display();
                        }
                    }
                    break;
                }
                case 3: {
                    std::string id = InputHelper::getString("Nhap Ma phieu nghiem thu can tim: ");
                    auto ptr = repo.findById(id);
                    if (ptr) {
                        std::cout << "\nThong tin phieu nghiem thu:\n";
                        AcceptanceReport::printHeader();
                        ptr->display();
                    } else {
                        std::cout << "Khong tim thay phieu nghiem thu co ma: " << id << std::endl;
                    }
                    break;
                }
                case 4: {
                    std::string id = InputHelper::getString("Nhap Ma phieu nghiem thu can sua: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay ma phu hop!\n";
                        break;
                    }
                    std::cout << "\nThong tin hien tai:\n";
                    AcceptanceReport::printHeader();
                    ptr->display();

                    std::cout << "\nNhap thong tin moi (Nhan Enter de giu nguyen):\n";
                    std::string val;

                    std::cout << "Ma du an moi (" << ptr->getMaDA() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setMaDA(val);

                    std::cout << "Ma doi thi cong moi (" << ptr->getMaDoiTC() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setMaDoiTC(val);

                    std::cout << "Ngay nghiem thu moi (" << ptr->getNgayNghiemThu() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setNgayNghiemThu(val);

                    std::cout << "Danh gia moi (" << ptr->getDanhGia() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setDanhGia(val);

                    std::cout << "Chi phi moi (" << ptr->getChiPhi() << "): ";
                    std::getline(std::cin, val);
                    if (!val.empty()) ptr->setChiPhi(std::stod(val));

                    repo.saveToFile();
                    std::cout << "Cap nhat thanh cong!\n";
                    break;
                }
                case 5: {
                    std::string id = InputHelper::getString("Nhap Ma phieu nghiem thu can xoa: ");
                    auto ptr = repo.findById(id);
                    if (!ptr) {
                        std::cout << "Khong tim thay phieu nghiem thu!\n";
                        break;
                    }
                    ptr->display();
                    std::string confirm = InputHelper::getString("Ban co chac chan muon xoa phieu nay? (y/n): ");
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
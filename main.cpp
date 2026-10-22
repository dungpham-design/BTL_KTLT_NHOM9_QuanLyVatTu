#include <iostream>
#include "Repository.h"
#include "include/ConstructionTeam.h"
#include "include/ConstructionTeamMenu.h"
#include "include/AcceptanceReport.h"
#include "include/AcceptanceReportMenu.h"
#include "InputHelper.h"

int main() {
    // 1. Khởi tạo repository nạp dữ liệu từ file
    Repository<ConstructionTeam> teamRepo("data/construction_teams.txt");
    Repository<AcceptanceReport> reportRepo("data/acceptance_reports.txt");

    // 2. Khởi tạo Menu cho 2 Use Case
    ConstructionTeamMenu teamMenu(teamRepo);
    AcceptanceReportMenu reportMenu(reportRepo, teamRepo);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n================ PHAN HE SINH VIEN 5 ================\n";
        std::cout << "1. Quan ly Doi thi cong (UC05)\n";
        std::cout << "2. Quan ly Phieu nghiem thu (UC09)\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "======================================================\n";
        choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                teamMenu.run(); // Mở Menu con UC05
                break;
            case 2:
                reportMenu.run(); // Mở Menu con UC09
                break;
            case 0:
                std::cout << "Da thoat phan he Sinh vien 5.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le, vui long nhap lai!\n";
                break;
        }
    }

    return 0;
}
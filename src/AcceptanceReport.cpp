#include "../include/AcceptanceReport.h"
#include "../InputHelper.h"

AcceptanceReport::AcceptanceReport() : maPNT(""), maDA(""), maDoiTC(""), ngayNghiemThu(""), danhGia(""), chiPhi(0.0) {}

AcceptanceReport::AcceptanceReport(std::string pnt, std::string da, std::string dtc, std::string ngay, std::string dg, double cp)
    : maPNT(pnt), maDA(da), maDoiTC(dtc), ngayNghiemThu(ngay), danhGia(dg), chiPhi(cp) {}

void AcceptanceReport::input() {
    maPNT = InputHelper::getString("Nhap Ma phieu nghiem thu (vd: PNT01): ");
    maDA = InputHelper::getString("Nhap Ma du an tham chieu (vd: DA01): ");
    maDoiTC = InputHelper::getString("Nhap Ma doi thi cong (vd: DTC01): ");
    ngayNghiemThu = InputHelper::getString("Nhap Ngay nghiem thu (dd/mm/yyyy): ");
    danhGia = InputHelper::getString("Nhap Danh gia (Dat/Khong dat): ");
    
    while (true) {
        std::cout << "Nhap Chi phi nghiem thu (VND): ";
        if (std::cin >> chiPhi && chiPhi >= 0) {
            std::cin.ignore(10000, '\n');
            break;
        }
        std::cout << "Loi: Chi phi phai la so duong!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void AcceptanceReport::printHeader() {
    std::cout << std::left 
              << std::setw(12) << "Ma PNT"
              << std::setw(12) << "Ma DA"
              << std::setw(12) << "Ma DTC"
              << std::setw(15) << "Ngay NT"
              << std::setw(15) << "Danh Gia"
              << std::setw(18) << "Chi Phi (VND)" << std::endl;
    std::cout << std::string(84, '-') << std::endl;
}

void AcceptanceReport::display() const {
    std::cout << std::left 
              << std::setw(12) << maPNT
              << std::setw(12) << maDA
              << std::setw(12) << maDoiTC
              << std::setw(15) << ngayNghiemThu
              << std::setw(15) << danhGia
              << std::setw(18) << std::fixed << std::setprecision(0) << chiPhi << std::endl;
}

std::string AcceptanceReport::toString() const {
    return maPNT + "|" + maDA + "|" + maDoiTC + "|" + ngayNghiemThu + "|" + danhGia + "|" + std::to_string(chiPhi);
}

void AcceptanceReport::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, maPNT, '|');
    std::getline(ss, maDA, '|');
    std::getline(ss, maDoiTC, '|');
    std::getline(ss, ngayNghiemThu, '|');
    std::getline(ss, danhGia, '|');
    std::getline(ss, token, '|');
    chiPhi = token.empty() ? 0.0 : std::stod(token);
}
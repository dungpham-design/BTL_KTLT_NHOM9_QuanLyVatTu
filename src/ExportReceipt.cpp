#include "../include/ExportReceipt.h"
#include "../InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

ExportReceipt::ExportReceipt() : tongTien(0.0) {}

ExportReceipt::ExportReceipt(const std::string& maP, const std::string& maDA, 
                             const std::string& ngay, const std::string& nguoi, double tong)
    : maPhieu(maP), maDuAn(maDA), ngayXuat(ngay), nguoiXuat(nguoi), tongTien(tong) {}

std::string ExportReceipt::getId() const {
    return maPhieu;
}

std::string ExportReceipt::getMaPhieu() const { return maPhieu; }
void ExportReceipt::setMaPhieu(const std::string& maP) { maPhieu = maP; }

std::string ExportReceipt::getMaDuAn() const { return maDuAn; }
void ExportReceipt::setMaDuAn(const std::string& maDA) { maDuAn = maDA; }

std::string ExportReceipt::getNgayXuat() const { return ngayXuat; }
void ExportReceipt::setNgayXuat(const std::string& ngay) { ngayXuat = ngay; }

std::string ExportReceipt::getNguoiXuat() const { return nguoiXuat; }
void ExportReceipt::setNguoiXuat(const std::string& nguoi) { nguoiXuat = nguoi; }

double ExportReceipt::getTongTien() const { return tongTien; }
void ExportReceipt::setTongTien(double tong) { tongTien = tong; }

void ExportReceipt::printHeader() {
    std::cout << std::left 
              << std::setw(15) << "Ma Phieu"
              << std::setw(15) << "Ma Du An"
              << std::setw(15) << "Ngay Xuat"
              << std::setw(25) << "Nguoi Xuat"
              << std::setw(18) << "Tong Tien (VND)" << std::endl;
    std::cout << std::string(88, '-') << std::endl;
}

void ExportReceipt::input() {
    maPhieu = InputHelper::getString("Nhap ma phieu xuat: ");
    maDuAn = InputHelper::getString("Nhap ma du an: ");
    ngayXuat = InputHelper::getString("Nhap ngay xuat (dd/mm/yyyy): ");
    nguoiXuat = InputHelper::getString("Nhap ten nguoi xuat: ");
    tongTien = std::stod(InputHelper::getString("Nhap tong gia tri phieu xuat: "));
}

void ExportReceipt::display() const {
    std::cout << std::left 
              << std::setw(15) << maPhieu
              << std::setw(15) << maDuAn
              << std::setw(15) << ngayXuat
              << std::setw(25) << nguoiXuat
              << std::setw(18) << std::fixed << std::setprecision(2) << tongTien << std::endl;
}

std::string ExportReceipt::toString() const {
    std::ostringstream oss;
    oss << maPhieu << "|" << maDuAn << "|" << ngayXuat << "|" 
        << nguoiXuat << "|" << tongTien;
    return oss.str();
}

void ExportReceipt::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    if (std::getline(ss, token, '|')) maPhieu = token;
    if (std::getline(ss, token, '|')) maDuAn = token;
    if (std::getline(ss, token, '|')) ngayXuat = token;
    if (std::getline(ss, token, '|')) nguoiXuat = token;
    if (std::getline(ss, token, '|')) tongTien = std::stod(token);
}

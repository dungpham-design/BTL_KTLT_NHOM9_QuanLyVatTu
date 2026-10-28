#include "ImportReceipt.h"
#include <sstream>
#include <iomanip>

ImportReceipt::ImportReceipt() : maPhieuNhap(""), ngayNhap(""), maNhaCungCap(""), maNhanVien(""), tongTien(0.0) {}

ImportReceipt::ImportReceipt(std::string maPhieu, std::string ngay, std::string maNCC, std::string maNV, double tien)
    : maPhieuNhap(maPhieu), ngayNhap(ngay), maNhaCungCap(maNCC), maNhanVien(maNV), tongTien(tien) {}

std::string ImportReceipt::getId() const {
    return maPhieuNhap;
}

void ImportReceipt::input() {
    std::cout << "Nhap ma phieu nhap: ";
    maPhieuNhap = InputHelper::getString();
    std::cout << "Nhap ngay nhap (DD/MM/YYYY): ";
    ngayNhap = InputHelper::getString();
    std::cout << "Nhap ma nha cung cap: ";
    maNhaCungCap = InputHelper::getString();
    std::cout << "Nhap ma nhan vien kho: ";
    maNhanVien = InputHelper::getString();
    std::cout << "Nhap tong tien nhap: ";
    while (true) {
        tongTien = static_cast<double>(InputHelper::getInt()); // Co the dieu chinh thanh double neu InputHelper ho tro
        if (tongTien >= 0) break;
        std::cout << "Tong tien khong duoc am. Vui long nhap lai: ";
    }
}

void ImportReceipt::display() const {
    std::cout << std::left
        << std::setw(15) << maPhieuNhap
        << std::setw(15) << ngayNhap
        << std::setw(18) << maNhaCungCap
        << std::setw(15) << maNhanVien
        << std::setw(15) << std::fixed << std::setprecision(0) << tongTien
        << std::endl;
}

std::string ImportReceipt::toString() const {
    std::ostringstream oss;
    oss << maPhieuNhap << "|" << ngayNhap << "|" << maNhaCungCap << "|" << maNhanVien << "|" << tongTien;
    return oss.str();
}

void ImportReceipt::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string tempTien;
    std::getline(ss, maPhieuNhap, '|');
    std::getline(ss, ngayNhap, '|');
    std::getline(ss, maNhaCungCap, '|');
    std::getline(ss, maNhanVien, '|');
    std::getline(ss, tempTien, '|');
    if (!tempTien.empty()) {
        tongTien = std::stod(tempTien);
    }
}

void ImportReceipt::printHeader() {
    std::cout << std::left
        << std::setw(15) << "Ma Phieu Nhap"
        << std::setw(15) << "Ngay Nhap"
        << std::setw(18) << "Ma Nha Cung Cap"
        << std::setw(15) << "Ma Nhan Vien"
        << std::setw(15) << "Tong Tien"
        << std::endl;
    std::cout << std::string(78, '-') << std::endl;
}

std::string ImportReceipt::getMaPhieuNhap() const { return maPhieuNhap; }
void ImportReceipt::setMaPhieuNhap(const std::string& ma) { maPhieuNhap = ma; }
std::string ImportReceipt::getNgayNhap() const { return ngayNhap; }
void ImportReceipt::setNgayNhap(const std::string& ngay) { ngayNhap = ngay; }
std::string ImportReceipt::getMaNhaCungCap() const { return maNhaCungCap; }
void ImportReceipt::setMaNhaCungCap(const std::string& ma) { maNhaCungCap = ma; }
std::string ImportReceipt::getMaNhanVien() const { return maNhanVien; }
void ImportReceipt::setMaNhanVien(const std::string& ma) { maNhanVien = ma; }
double ImportReceipt::getTongTien() const { return tongTien; }
void ImportReceipt::setTongTien(double tien) { tongTien = tien; }
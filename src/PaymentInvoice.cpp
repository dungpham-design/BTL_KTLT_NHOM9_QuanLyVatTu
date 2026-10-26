#include "PaymentInvoice.h"
#include "InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

PaymentInvoice::PaymentInvoice() : maHoaDon(""), maNCC(""), ngayThanhToan(""), soTien(0.0), trangThai("") {}

PaymentInvoice::PaymentInvoice(std::string maHD, std::string maNCC, std::string ngayTT, double tien, std::string tt)
    : maHoaDon(maHD), maNCC(maNCC), ngayThanhToan(ngayTT), soTien(tien), trangThai(tt) {}

std::string PaymentInvoice::getId() const {
    return maHoaDon;
}

void PaymentInvoice::input() {
    std::cout << "Nhap ma hoa don (VD: HD01): ";
    maHoaDon = InputHelper::getString();
    std::cout << "Nhap ma nha cung cap lien quan: ";
    maNCC = InputHelper::getString();
    std::cout << "Nhap ngay thanh toan (DD/MM/YYYY): ";
    ngayThanhToan = InputHelper::getString();
    std::cout << "Nhap so tien thanh toan: ";
    soTien = InputHelper::getDouble();
    std::cout << "Nhap trang thai (Da thanh toan / Chua thanh toan): ";
    trangThai = InputHelper::getString();
}

void PaymentInvoice::display() const {
    std::cout << std::left
              << std::setw(12) << maHoaDon
              << std::setw(15) << maNCC
              << std::setw(18) << ngayThanhToan
              << std::setw(18) << std::fixed << std::setprecision(0) << soTien
              << std::setw(20) << trangThai << "\n";
}

std::string PaymentInvoice::toString() const {
    std::stringstream ss;
    ss << maHoaDon << "|" << maNCC << "|" << ngayThanhToan << "|" << soTien << "|" << trangThai;
    return ss.str();
}

void PaymentInvoice::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string tienStr;
    std::getline(ss, maHoaDon, '|');
    std::getline(ss, maNCC, '|');
    std::getline(ss, ngayThanhToan, '|');
    std::getline(ss, tienStr, '|');
    try {
        soTien = std::stod(tienStr);
    } catch (...) {
        soTien = 0.0;
    }
    std::getline(ss, trangThai, '|');
}

void PaymentInvoice::printHeader() {
    std::cout << std::left
              << std::setw(12) << "Ma HD"
              << std::setw(15) << "Ma NCC"
              << std::setw(18) << "Ngay Thanh Toan"
              << std::setw(18) << "So Tien (VND)"
              << std::setw(20) << "Trang Thai" << "\n";
    std::cout << std::string(83, '-') << "\n";
}

std::string PaymentInvoice::getMaHoaDon() const { return maHoaDon; }
void PaymentInvoice::setMaHoaDon(const std::string& ma) { maHoaDon = ma; }
std::string PaymentInvoice::getMaNCC() const { return maNCC; }
void PaymentInvoice::setMaNCC(const std::string& ma) { maNCC = ma; }
std::string PaymentInvoice::getNgayThanhToan() const { return ngayThanhToan; }
void PaymentInvoice::setNgayThanhToan(const std::string& ngay) { ngayThanhToan = ngay; }
double PaymentInvoice::getSoTien() const { return soTien; }
void PaymentInvoice::setSoTien(double tien) { soTien = tien; }
std::string PaymentInvoice::getTrangThai() const { return trangThai; }
void PaymentInvoice::setTrangThai(const std::string& tt) { trangThai = tt; }
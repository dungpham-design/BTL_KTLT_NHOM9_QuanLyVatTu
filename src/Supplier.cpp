#include "Supplier.h"
#include "InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Supplier::Supplier() : maNCC(""), tenNCC(""), diaChi(""), soDienThoai(""), email("") {}

Supplier::Supplier(std::string ma, std::string ten, std::string dc, std::string sdt, std::string em)
    : maNCC(ma), tenNCC(ten), diaChi(dc), soDienThoai(sdt), email(em) {}

std::string Supplier::getId() const {
    return maNCC;
}

void Supplier::input() {
    std::cout << "Nhap ma nha cung cap (VD: NCC01): ";
    maNCC = InputHelper::getString();
    std::cout << "Nhap ten nha cung cap: ";
    tenNCC = InputHelper::getString();
    std::cout << "Nhap dia chi: ";
    diaChi = InputHelper::getString();
    std::cout << "Nhap so dien thoai: ";
    soDienThoai = InputHelper::getString();
    std::cout << "Nhap email: ";
    email = InputHelper::getString();
}

void Supplier::display() const {
    std::cout << std::left
              << std::setw(12) << maNCC
              << std::setw(25) << tenNCC
              << std::setw(25) << diaChi
              << std::setw(15) << soDienThoai
              << std::setw(25) << email << "\n";
}

std::string Supplier::toString() const {
    return maNCC + "|" + tenNCC + "|" + diaChi + "|" + soDienThoai + "|" + email;
}

void Supplier::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, maNCC, '|');
    std::getline(ss, tenNCC, '|');
    std::getline(ss, diaChi, '|');
    std::getline(ss, soDienThoai, '|');
    std::getline(ss, email, '|');
}

void Supplier::printHeader() {
    std::cout << std::left
              << std::setw(12) << "Ma NCC"
              << std::setw(25) << "Ten Nha Cung Cap"
              << std::setw(25) << "Dia Chi"
              << std::setw(15) << "So Dien Thoai"
              << std::setw(25) << "Email" << "\n";
    std::cout << std::string(102, '-') << "\n";
}

std::string Supplier::getMaNCC() const { return maNCC; }
void Supplier::setMaNCC(const std::string& ma) { maNCC = ma; }
std::string Supplier::getTenNCC() const { return tenNCC; }
void Supplier::setTenNCC(const std::string& ten) { tenNCC = ten; }
std::string Supplier::getDiaChi() const { return diaChi; }
void Supplier::setDiaChi(const std::string& dc) { diaChi = dc; }
std::string Supplier::getSoDienThoai() const { return soDienThoai; }
void Supplier::setSoDienThoai(const std::string& sdt) { soDienThoai = sdt; }
std::string Supplier::getEmail() const { return email; }
void Supplier::setEmail(const std::string& em) { email = em; }
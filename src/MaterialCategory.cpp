#include "../include/MaterialCategory.h"
#include <sstream>
#include <iomanip>

MaterialCategory::MaterialCategory() : maDanhMuc(""), tenDanhMuc(""), moTa("") {}

MaterialCategory::MaterialCategory(std::string ma, std::string ten, std::string mota)
    : maDanhMuc(ma), tenDanhMuc(ten), moTa(mota) {}

std::string MaterialCategory::getId() const {
    return maDanhMuc;
}

void MaterialCategory::input() {
    std::cout << "Nhap ma danh muc: ";
    maDanhMuc = InputHelper::getString("");
    std::cout << "Nhap ten danh muc: ";
    tenDanhMuc = InputHelper::getString("");
    std::cout << "Nhap mo ta: ";
    moTa = InputHelper::getString("");
}

void MaterialCategory::display() const {
    std::cout << std::left
        << std::setw(15) << maDanhMuc
        << std::setw(30) << tenDanhMuc
        << std::setw(40) << moTa
        << std::endl;
}

std::string MaterialCategory::toString() const {
    return maDanhMuc + "|" + tenDanhMuc + "|" + moTa;
}

void MaterialCategory::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::getline(ss, maDanhMuc, '|');
    std::getline(ss, tenDanhMuc, '|');
    std::getline(ss, moTa, '|');
}

void MaterialCategory::printHeader() {
    std::cout << std::left
        << std::setw(15) << "Ma Danh Muc"
        << std::setw(30) << "Ten Danh Muc"
        << std::setw(40) << "Mo Ta"
        << std::endl;
    std::cout << std::string(85, '-') << std::endl;
}

std::string MaterialCategory::getMaDanhMuc() const { return maDanhMuc; }
void MaterialCategory::setMaDanhMuc(const std::string& ma) { maDanhMuc = ma; }
std::string MaterialCategory::getTenDanhMuc() const { return tenDanhMuc; }
void MaterialCategory::setTenDanhMuc(const std::string& ten) { tenDanhMuc = ten; }
std::string MaterialCategory::getMoTa() const { return moTa; }
void MaterialCategory::setMoTa(const std::string& mota) { moTa = mota; }
#include "include/Warehouse.h"
#include "InputHelper.h"

Warehouse::Warehouse() : maKho(""), tenKho(""), diaChiKho(""), nguoiQuanLy(""), sucChua(0) {}

Warehouse::Warehouse(std::string ma, std::string ten, std::string diaChi, std::string ql, int sc)
    : maKho(ma), tenKho(ten), diaChiKho(diaChi), nguoiQuanLy(ql), sucChua(sc) {}

void Warehouse::input() {
    maKho = InputHelper::getString("Nhap Ma kho (vd: KHO01): ");
    tenKho = InputHelper::getString("Nhap Ten kho: ");
    diaChiKho = InputHelper::getString("Nhap Dia chi kho: ");
    nguoiQuanLy = InputHelper::getString("Nhap Ho ten nguoi quan ly (Thu kho): ");
    sucChua = InputHelper::getInt("Nhap Suc chua kho (m2): ");
}

void Warehouse::printHeader() {
    std::cout << std::left 
              << std::setw(12) << "Ma Kho"
              << std::setw(25) << "Ten Kho"
              << std::setw(30) << "Dia Chi Kho"
              << std::setw(20) << "Nguoi Quan Ly"
              << std::setw(12) << "Suc Chua" << std::endl;
    std::cout << std::string(99, '-') << std::endl;
}

void Warehouse::display() const {
    std::cout << std::left 
              << std::setw(12) << maKho
              << std::setw(25) << tenKho
              << std::setw(30) << diaChiKho
              << std::setw(20) << nguoiQuanLy
              << std::setw(12) << sucChua << std::endl;
}

std::string Warehouse::toString() const {
    return maKho + "|" + tenKho + "|" + diaChiKho + "|" + nguoiQuanLy + "|" + std::to_string(sucChua);
}

void Warehouse::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, maKho, '|');
    std::getline(ss, tenKho, '|');
    std::getline(ss, diaChiKho, '|');
    std::getline(ss, nguoiQuanLy, '|');
    std::getline(ss, token, '|');
    sucChua = token.empty() ? 0 : std::stoi(token);
}

#include "include/Project.h"
#include "InputHelper.h"

Project::Project() : maDA(""), tenDA(""), diaBan(""), ngayBatDau(""), ngayHoanThanhDuKien(""), trangThai("") {}

Project::Project(std::string ma, std::string ten, std::string db, std::string bd, std::string ht, std::string tt)
    : maDA(ma), tenDA(ten), diaBan(db), ngayBatDau(bd), ngayHoanThanhDuKien(ht), trangThai(tt) {}

void Project::input() {
    maDA = InputHelper::getString("Nhap Ma du an (vd: DA01): ");
    tenDA = InputHelper::getString("Nhap Ten du an: ");
    diaBan = InputHelper::getString("Nhap Dia ban trien khai: ");
    ngayBatDau = InputHelper::getString("Nhap Ngay bat dau (dd/mm/yyyy): ");
    ngayHoanThanhDuKien = InputHelper::getString("Nhap Ngay hoan thanh du kien (dd/mm/yyyy): ");
    trangThai = InputHelper::getString("Nhap Trang thai (Dang thi cong / Hoan thanh / Tam dung): ");
}

void Project::printHeader() {
    std::cout << std::left 
              << std::setw(12) << "Ma DA"
              << std::setw(30) << "Ten Du An"
              << std::setw(20) << "Dia Ban"
              << std::setw(15) << "Ngay Bat Dau"
              << std::setw(18) << "Ngay HT Du Kien"
              << std::setw(18) << "Trang Thai" << std::endl;
    std::cout << std::string(113, '-') << std::endl;
}

void Project::display() const {
    std::cout << std::left 
              << std::setw(12) << maDA
              << std::setw(30) << tenDA
              << std::setw(20) << diaBan
              << std::setw(15) << ngayBatDau
              << std::setw(18) << ngayHoanThanhDuKien
              << std::setw(18) << trangThai << std::endl;
}

std::string Project::toString() const {
    return maDA + "|" + tenDA + "|" + diaBan + "|" + ngayBatDau + "|" + ngayHoanThanhDuKien + "|" + trangThai;
}

void Project::fromString(const std::string& line) {
    std::stringstream ss(line);

    std::getline(ss, maDA, '|');
    std::getline(ss, tenDA, '|');
    std::getline(ss, diaBan, '|');
    std::getline(ss, ngayBatDau, '|');
    std::getline(ss, ngayHoanThanhDuKien, '|');
    std::getline(ss, trangThai, '|');
}

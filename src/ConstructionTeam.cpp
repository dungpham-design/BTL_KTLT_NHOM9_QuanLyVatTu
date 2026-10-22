#include "../include/ConstructionTeam.h"
#include "InputHelper.h"

ConstructionTeam::ConstructionTeam() : maDoiTC(""), tenDoi(""), doiTruong(""), soDienThoai(""), soLuongNhanSu(0) {}

ConstructionTeam::ConstructionTeam(std::string ma, std::string ten, std::string dt, std::string sdt, int sl)
    : maDoiTC(ma), tenDoi(ten), doiTruong(dt), soDienThoai(sdt), soLuongNhanSu(sl) {}

void ConstructionTeam::input() {
    maDoiTC = InputHelper::getString("Nhap Ma doi thi cong (vd: DTC01): ");
    tenDoi = InputHelper::getString("Nhap Ten doi thi cong: ");
    doiTruong = InputHelper::getString("Nhap Ho ten doi truong: ");
    soDienThoai = InputHelper::getString("Nhap So dien thoai: ");
    soLuongNhanSu = InputHelper::getInt("Nhap So luong nhan su: ");
}

void ConstructionTeam::printHeader() {
    std::cout << std::left 
              << std::setw(12) << "Ma DTC"
              << std::setw(25) << "Ten Doi"
              << std::setw(22) << "Doi Truong"
              << std::setw(15) << "So Dien Thoai"
              << std::setw(15) << "So Nhan Su" << std::endl;
    std::cout << std::string(89, '-') << std::endl;
}

void ConstructionTeam::display() const {
    std::cout << std::left 
              << std::setw(12) << maDoiTC
              << std::setw(25) << tenDoi
              << std::setw(22) << doiTruong
              << std::setw(15) << soDienThoai
              << std::setw(15) << soLuongNhanSu << std::endl;
}

std::string ConstructionTeam::toString() const {
    return maDoiTC + "|" + tenDoi + "|" + doiTruong + "|" + soDienThoai + "|" + std::to_string(soLuongNhanSu);
}

void ConstructionTeam::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    std::getline(ss, maDoiTC, '|');
    std::getline(ss, tenDoi, '|');
    std::getline(ss, doiTruong, '|');
    std::getline(ss, soDienThoai, '|');
    std::getline(ss, token, '|');
    soLuongNhanSu = token.empty() ? 0 : std::stoi(token);
}
#include "../include/Material.h"
#include "../InputHelper.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Material::Material() : donGia(0.0), soLuongTon(0) {}

Material::Material(const std::string& ma, const std::string& ten, const std::string& maDM, 
                   const std::string& dvt, double gia, int sl)
    : maVatTu(ma), tenVatTu(ten), maDanhMuc(maDM), donViTinh(dvt), donGia(gia), soLuongTon(sl) {}

std::string Material::getId() const {
    return maVatTu;
}

std::string Material::getMaVatTu() const { return maVatTu; }
void Material::setMaVatTu(const std::string& ma) { maVatTu = ma; }

std::string Material::getTenVatTu() const { return tenVatTu; }
void Material::setTenVatTu(const std::string& ten) { tenVatTu = ten; }

std::string Material::getMaDanhMuc() const { return maDanhMuc; }
void Material::setMaDanhMuc(const std::string& maDM) { maDanhMuc = maDM; }

std::string Material::getDonViTinh() const { return donViTinh; }
void Material::setDonViTinh(const std::string& dvt) { donViTinh = dvt; }

double Material::getDonGia() const { return donGia; }
void Material::setDonGia(double gia) { donGia = gia; }

int Material::getSoLuongTon() const { return soLuongTon; }
void Material::setSoLuongTon(int sl) { soLuongTon = sl; }

void Material::printHeader() {
    std::cout << std::left 
              << std::setw(12) << "Ma Vat Tu"
              << std::setw(30) << "Ten Vat Tu"
              << std::setw(15) << "Ma Danh Muc"
              << std::setw(12) << "Don Vi Tinh"
              << std::setw(15) << "Don Gia"
              << std::setw(12) << "So Luong Ton" << std::endl;
    std::cout << std::string(96, '-') << std::endl;
}

void Material::input() {
    maVatTu = InputHelper::getString("Nhap ma vat tu: ");
    tenVatTu = InputHelper::getString("Nhap ten vat tu: ");
    maDanhMuc = InputHelper::getString("Nhap ma danh muc: ");
    donViTinh = InputHelper::getString("Nhap don vi tinh: ");
    donGia = std::stod(InputHelper::getString("Nhap don gia: "));
    soLuongTon = InputHelper::getInt("Nhap so luong ton: ");
}

void Material::display() const {
    std::cout << std::left 
              << std::setw(12) << maVatTu
              << std::setw(30) << tenVatTu
              << std::setw(15) << maDanhMuc
              << std::setw(12) << donViTinh
              << std::setw(15) << std::fixed << std::setprecision(2) << donGia
              << std::setw(12) << soLuongTon << std::endl;
}

std::string Material::toString() const {
    std::ostringstream oss;
    oss << maVatTu << "|" << tenVatTu << "|" << maDanhMuc << "|" 
        << donViTinh << "|" << donGia << "|" << soLuongTon;
    return oss.str();
}

void Material::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    if (std::getline(ss, token, '|')) maVatTu = token;
    if (std::getline(ss, token, '|')) tenVatTu = token;
    if (std::getline(ss, token, '|')) maDanhMuc = token;
    if (std::getline(ss, token, '|')) donViTinh = token;
    if (std::getline(ss, token, '|')) donGia = std::stod(token);
    if (std::getline(ss, token, '|')) soLuongTon = std::stoi(token);
}

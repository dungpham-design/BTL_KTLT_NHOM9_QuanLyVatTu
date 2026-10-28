// Tac gia: Mai Tat Dat
#include "../include/Supplier.h"
#include "../InputHelper.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
std::string fitCell(const std::string& value, std::size_t width) {
    if (value.size() <= width) {
        return value;
    }
    if (width <= 3) {
        return value.substr(0, width);
    }
    return value.substr(0, width - 3) + "...";
}
}

Supplier::Supplier()
    : maNhaCungCap(""), tenNhaCungCap(""), diaChi(""),
      soDienThoai(""), email("") {
}

Supplier::Supplier(const std::string& ma, const std::string& ten,
                   const std::string& diaChiMoi,
                   const std::string& soDienThoaiMoi,
                   const std::string& emailMoi)
    : maNhaCungCap(""), tenNhaCungCap(""), diaChi(""),
      soDienThoai(""), email("") {
    setMaNhaCungCap(ma);
    setTenNhaCungCap(ten);
    setDiaChi(diaChiMoi);
    setSoDienThoai(soDienThoaiMoi);
    setEmail(emailMoi);
}

std::string Supplier::getId() const {
    return maNhaCungCap;
}

std::string Supplier::getMaNhaCungCap() const {
    return maNhaCungCap;
}

std::string Supplier::getTenNhaCungCap() const {
    return tenNhaCungCap;
}

std::string Supplier::getDiaChi() const {
    return diaChi;
}

std::string Supplier::getSoDienThoai() const {
    return soDienThoai;
}

std::string Supplier::getEmail() const {
    return email;
}

void Supplier::validateRequiredField(const std::string& value,
                                     const std::string& fieldName) {
    if (value.empty()) {
        throw std::invalid_argument(fieldName + " khong duoc de trong.");
    }
    if (value.find('|') != std::string::npos ||
        value.find('\n') != std::string::npos ||
        value.find('\r') != std::string::npos) {
        throw std::invalid_argument(fieldName + " khong duoc chua ky tu | hoac xuong dong.");
    }
}

void Supplier::setMaNhaCungCap(const std::string& ma) {
    validateRequiredField(ma, "Ma nha cung cap");
    maNhaCungCap = ma;
}

void Supplier::setTenNhaCungCap(const std::string& ten) {
    validateRequiredField(ten, "Ten nha cung cap");
    tenNhaCungCap = ten;
}

void Supplier::setDiaChi(const std::string& diaChiMoi) {
    validateRequiredField(diaChiMoi, "Dia chi");
    diaChi = diaChiMoi;
}

void Supplier::setSoDienThoai(const std::string& soDienThoaiMoi) {
    validateRequiredField(soDienThoaiMoi, "So dien thoai");

    int soChuSo = 0;
    for (std::size_t i = 0; i < soDienThoaiMoi.size(); ++i) {
        unsigned char kyTu = static_cast<unsigned char>(soDienThoaiMoi[i]);
        if (std::isdigit(kyTu)) {
            ++soChuSo;
        } else if (soDienThoaiMoi[i] != '+' && soDienThoaiMoi[i] != '-' &&
                   soDienThoaiMoi[i] != '(' && soDienThoaiMoi[i] != ')' &&
                   soDienThoaiMoi[i] != ' ') {
            throw std::invalid_argument("So dien thoai chi duoc chua chu so va ky tu + - ( ).");
        }
    }

    if (soChuSo < 8 || soChuSo > 15) {
        throw std::invalid_argument("So dien thoai phai co tu 8 den 15 chu so.");
    }
    soDienThoai = soDienThoaiMoi;
}

void Supplier::setEmail(const std::string& emailMoi) {
    validateRequiredField(emailMoi, "Email");
    std::size_t viTriA = emailMoi.find('@');
    std::size_t viTriCham = emailMoi.rfind('.');
    if (viTriA == std::string::npos || viTriA == 0 ||
        viTriCham == std::string::npos || viTriCham <= viTriA + 1 ||
        viTriCham == emailMoi.size() - 1) {
        throw std::invalid_argument("Email khong dung dinh dang co ban.");
    }
    email = emailMoi;
}

void Supplier::input() {
    while (true) {
        std::string giaTri = InputHelper::getString("Nhap ma nha cung cap: ");
        try {
            setMaNhaCungCap(giaTri);
            break;
        } catch (const std::exception& loi) {
            std::cout << "Loi: " << loi.what() << " Vui long nhap lai.\n";
        }
    }

    while (true) {
        std::string giaTri = InputHelper::getString("Nhap ten nha cung cap: ");
        try {
            setTenNhaCungCap(giaTri);
            break;
        } catch (const std::exception& loi) {
            std::cout << "Loi: " << loi.what() << " Vui long nhap lai.\n";
        }
    }

    while (true) {
        std::string giaTri = InputHelper::getString("Nhap dia chi: ");
        try {
            setDiaChi(giaTri);
            break;
        } catch (const std::exception& loi) {
            std::cout << "Loi: " << loi.what() << " Vui long nhap lai.\n";
        }
    }

    while (true) {
        std::string giaTri = InputHelper::getString("Nhap so dien thoai: ");
        try {
            setSoDienThoai(giaTri);
            break;
        } catch (const std::exception& loi) {
            std::cout << "Loi: " << loi.what() << " Vui long nhap lai.\n";
        }
    }

    while (true) {
        std::string giaTri = InputHelper::getString("Nhap email: ");
        try {
            setEmail(giaTri);
            break;
        } catch (const std::exception& loi) {
            std::cout << "Loi: " << loi.what() << " Vui long nhap lai.\n";
        }
    }
}

void Supplier::display() const {
    std::cout << std::left
              << std::setw(12) << fitCell(maNhaCungCap, 12) << ' '
              << std::setw(28) << fitCell(tenNhaCungCap, 28) << ' '
              << std::setw(34) << fitCell(diaChi, 34) << ' '
              << std::setw(18) << fitCell(soDienThoai, 18) << ' '
              << std::setw(30) << fitCell(email, 30)
              << '\n';
}

std::string Supplier::toString() const {
    return maNhaCungCap + "|" + tenNhaCungCap + "|" + diaChi + "|" +
           soDienThoai + "|" + email;
}

void Supplier::fromString(const std::string& line) {
    std::stringstream stream(line);
    std::vector<std::string> fields;
    std::string field;

    while (std::getline(stream, field, '|')) {
        fields.push_back(field);
    }

    if (fields.size() != 5) {
        throw std::invalid_argument("Dong du lieu nha cung cap phai co dung 5 truong.");
    }

    setMaNhaCungCap(fields[0]);
    setTenNhaCungCap(fields[1]);
    setDiaChi(fields[2]);
    setSoDienThoai(fields[3]);
    setEmail(fields[4]);
}

void Supplier::printHeader() {
    std::cout << std::left
              << std::setw(12) << "Ma NCC" << ' '
              << std::setw(28) << "Ten nha cung cap" << ' '
              << std::setw(34) << "Dia chi" << ' '
              << std::setw(18) << "So dien thoai" << ' '
              << std::setw(30) << "Email"
              << '\n';
    std::cout << std::string(126, '-') << '\n';
}

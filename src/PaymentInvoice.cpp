// Tac gia: Mai Tat Dat
#include "PaymentInvoice.h"
#include "InputHelper.h"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace {
std::string fitCell(const std::string& value, std::size_t width) {
    if (value.size() <= width) return value;
    if (width <= 3) return value.substr(0, width);
    return value.substr(0, width - 3) + "...";
}

std::vector<std::string> splitFields(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream stream(line);
    std::string field;
    while (std::getline(stream, field, '|')) fields.push_back(field);
    // getline khong tao phan tu cuoi neu dong ket thuc bang '|'.
    if (!line.empty() && line[line.size() - 1] == '|') fields.push_back("");
    return fields;
}

double parsePositiveAmount(const std::string& raw) {
    std::size_t used = 0;
    double value = 0.0;
    try {
        value = std::stod(raw, &used);
    } catch (...) {
        throw std::invalid_argument("Tong tien phai la mot so hop le.");
    }
    if (used != raw.size()) {
        throw std::invalid_argument("Tong tien chi duoc chua gia tri so.");
    }
    if (value <= 0.0) {
        throw std::invalid_argument("Tong tien phai lon hon 0.");
    }
    return value;
}
}

PaymentInvoice::PaymentInvoice()
    : maHoaDon(""), maDuAn(""), maNhaCungCap(""), ngayLap(""),
      tongTien(0.0), trangThai(""), ghiChu("") {
}

std::string PaymentInvoice::getId() const { return maHoaDon; }
std::string PaymentInvoice::getMaHoaDon() const { return maHoaDon; }
std::string PaymentInvoice::getMaDuAn() const { return maDuAn; }
std::string PaymentInvoice::getMaNhaCungCap() const { return maNhaCungCap; }
std::string PaymentInvoice::getNgayLap() const { return ngayLap; }
double PaymentInvoice::getTongTien() const { return tongTien; }
std::string PaymentInvoice::getTrangThai() const { return trangThai; }
std::string PaymentInvoice::getGhiChu() const { return ghiChu; }

void PaymentInvoice::validateField(const std::string& value,
                                   const std::string& tenTruong,
                                   bool choPhepTrong) {
    if (!choPhepTrong && value.empty()) {
        throw std::invalid_argument(tenTruong + " khong duoc de trong.");
    }
    if (value.find('|') != std::string::npos ||
        value.find('\n') != std::string::npos ||
        value.find('\r') != std::string::npos) {
        throw std::invalid_argument(tenTruong + " khong duoc chua ky tu | hoac xuong dong.");
    }
}

bool PaymentInvoice::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[2] != '/' || date[5] != '/') return false;
    for (std::size_t i = 0; i < date.size(); ++i) {
        if (i == 2 || i == 5) continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
    }
    const int day = (date[0] - '0') * 10 + (date[1] - '0');
    const int month = (date[3] - '0') * 10 + (date[4] - '0');
    const int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 +
                     (date[8] - '0') * 10 + (date[9] - '0');
    if (year < 1900 || month < 1 || month > 12) return false;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const bool leapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (leapYear) daysInMonth[1] = 29;
    return day >= 1 && day <= daysInMonth[month - 1];
}

void PaymentInvoice::setMaHoaDon(const std::string& ma) {
    validateField(ma, "Ma hoa don");
    maHoaDon = ma;
}

void PaymentInvoice::setMaDuAn(const std::string& ma) {
    validateField(ma, "Ma du an");
    maDuAn = ma;
}

void PaymentInvoice::setMaNhaCungCap(const std::string& ma) {
    validateField(ma, "Ma nha cung cap");
    maNhaCungCap = ma;
}

void PaymentInvoice::setNgayLap(const std::string& ngay) {
    validateField(ngay, "Ngay lap hoa don");
    if (!isValidDate(ngay)) {
        throw std::invalid_argument("Ngay lap phai dung dinh dang dd/mm/yyyy va la ngay hop le.");
    }
    ngayLap = ngay;
}

void PaymentInvoice::setTongTien(double tien) {
    if (tien <= 0.0) throw std::invalid_argument("Tong tien phai lon hon 0.");
    tongTien = tien;
}

void PaymentInvoice::setTrangThai(const std::string& trangThaiMoi) {
    validateField(trangThaiMoi, "Trang thai");
    if (trangThaiMoi != "Chua thanh toan" &&
        trangThaiMoi != "Da thanh toan" &&
        trangThaiMoi != "Thanh toan mot phan") {
        throw std::invalid_argument("Trang thai phai la: Chua thanh toan, Da thanh toan, hoac Thanh toan mot phan.");
    }
    trangThai = trangThaiMoi;
}

void PaymentInvoice::setGhiChu(const std::string& ghiChuMoi) {
    validateField(ghiChuMoi, "Ghi chu", true);
    ghiChu = ghiChuMoi;
}

void PaymentInvoice::input() {
    while (true) {
        try {
            setMaHoaDon(InputHelper::getString("Nhap ma hoa don: "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            setMaDuAn(InputHelper::getString("Nhap ma du an: "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            setMaNhaCungCap(InputHelper::getString("Nhap ma nha cung cap: "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            setNgayLap(InputHelper::getString("Nhap ngay lap (dd/mm/yyyy): "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            const std::string raw = InputHelper::getString("Nhap tong tien (VND, > 0): ");
            setTongTien(parsePositiveAmount(raw));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            std::cout << "Trang thai hop le: Chua thanh toan / Da thanh toan / Thanh toan mot phan.\n";
            setTrangThai(InputHelper::getString("Nhap trang thai: "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
    while (true) {
        try {
            setGhiChu(InputHelper::getString("Nhap ghi chu: "));
            break;
        } catch (const std::exception& e) { std::cout << "Loi: " << e.what() << '\n'; }
    }
}

void PaymentInvoice::display() const {
    std::cout << std::left
              << std::setw(12) << fitCell(maHoaDon, 11)
              << std::setw(12) << fitCell(maDuAn, 11)
              << std::setw(12) << fitCell(maNhaCungCap, 11)
              << std::setw(12) << ngayLap
              << std::right << std::setw(16) << std::fixed << std::setprecision(0) << tongTien
              << std::left << "  " << std::setw(23) << fitCell(trangThai, 22)
              << std::setw(30) << fitCell(ghiChu, 29) << '\n';
}

std::string PaymentInvoice::toString() const {
    std::ostringstream output;
    output << maHoaDon << '|' << maDuAn << '|' << maNhaCungCap << '|'
           << ngayLap << '|' << std::setprecision(15) << tongTien << '|'
           << trangThai << '|' << ghiChu;
    return output.str();
}

void PaymentInvoice::fromString(const std::string& line) {
    const std::vector<std::string> fields = splitFields(line);
    if (fields.size() != 7) {
        throw std::invalid_argument("Hoa don phai co dung 7 truong.");
    }
    setMaHoaDon(fields[0]);
    setMaDuAn(fields[1]);
    setMaNhaCungCap(fields[2]);
    setNgayLap(fields[3]);
    setTongTien(parsePositiveAmount(fields[4]));
    setTrangThai(fields[5]);
    setGhiChu(fields[6]);
}

void PaymentInvoice::printHeader() {
    std::cout << std::left
              << std::setw(12) << "Ma hoa don"
              << std::setw(12) << "Ma du an"
              << std::setw(12) << "Ma NCC"
              << std::setw(12) << "Ngay lap"
              << std::right << std::setw(16) << "Tong tien"
              << std::left << "  " << std::setw(23) << "Trang thai"
              << std::setw(30) << "Ghi chu" << '\n';
    std::cout << std::string(117, '-') << '\n';
}

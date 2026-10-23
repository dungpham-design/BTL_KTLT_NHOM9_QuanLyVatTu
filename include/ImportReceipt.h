#ifndef IMPORT_RECEIPT_H
#define IMPORT_RECEIPT_H

#include "Entity.h"
#include "InputHelper.h"
#include <string>
#include <iomanip>
#include <iostream>

class ImportReceipt : public Entity {
private:
    std::string maPhieuNhap;
    std::string ngayNhap;
    std::string maNhaCungCap;
    std::string maNhanVien;
    double tongTien;

public:
    ImportReceipt();
    ImportReceipt(std::string maPhieu, std::string ngay, std::string maNCC, std::string maNV, double tien);

    std::string getId() const override;

    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();

    std::string getMaPhieuNhap() const;
    void setMaPhieuNhap(const std::string& ma);
    std::string getNgayNhap() const;
    void setNgayNhap(const std::string& ngay);
    std::string getMaNhaCungCap() const;
    void setMaNhaCungCap(const std::string& ma);
    std::string getMaNhanVien() const;
    void setMaNhanVien(const std::string& ma);
    double getTongTien() const;
    void setTongTien(double tien);
};

#endif // IMPORT_RECEIPT_H
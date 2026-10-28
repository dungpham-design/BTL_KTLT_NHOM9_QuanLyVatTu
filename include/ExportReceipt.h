#ifndef EXPORT_RECEIPT_H
#define EXPORT_RECEIPT_H

#include "../Entity.h"
#include <string>

class ExportReceipt : public Entity {
private:
    std::string maPhieu;
    std::string maDuAn;
    std::string ngayXuat;
    std::string nguoiXuat;
    double tongTien;

public:
    ExportReceipt();
    ExportReceipt(const std::string& maP, const std::string& maDA, 
                  const std::string& ngay, const std::string& nguoi, double tong);

    std::string getId() const override;

    // Getters & Setters
    std::string getMaPhieu() const;
    void setMaPhieu(const std::string& maP);

    std::string getMaDuAn() const;
    void setMaDuAn(const std::string& maDA);

    std::string getNgayXuat() const;
    void setNgayXuat(const std::string& ngay);

    std::string getNguoiXuat() const;
    void setNguoiXuat(const std::string& nguoi);

    double getTongTien() const;
    void setTongTien(double tong);

    // Virtual methods from Entity
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif // EXPORT_RECEIPT_H

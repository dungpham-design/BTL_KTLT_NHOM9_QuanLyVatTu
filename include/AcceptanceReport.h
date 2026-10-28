#ifndef ACCEPTANCE_REPORT_H
#define ACCEPTANCE_REPORT_H

#include "../Entity.h"
#include <string>
#include <sstream>
#include <iomanip>

class AcceptanceReport : public Entity {
private:
    std::string maPNT;
    std::string maDA;      // Khóa ngoại tham chiếu Dự án (UC06)
    std::string maDoiTC;   // Khóa ngoại tham chiếu Đội thi công (UC05)
    std::string ngayNghiemThu;
    std::string danhGia;   // Dat / Khong dat
    double chiPhi;

public:
    AcceptanceReport();
    AcceptanceReport(std::string pnt, std::string da, std::string dtc, std::string ngay, std::string dg, double cp);

    std::string getId() const override { return maPNT; }
    void setMaPNT(const std::string& ma) { maPNT = ma; }

    std::string getMaDA() const { return maDA; }
    void setMaDA(const std::string& da) { maDA = da; }

    std::string getMaDoiTC() const { return maDoiTC; }
    void setMaDoiTC(const std::string& dtc) { maDoiTC = dtc; }

    std::string getNgayNghiemThu() const { return ngayNghiemThu; }
    void setNgayNghiemThu(const std::string& ngay) { ngayNghiemThu = ngay; }

    std::string getDanhGia() const { return danhGia; }
    void setDanhGia(const std::string& dg) { danhGia = dg; }

    double getChiPhi() const { return chiPhi; }
    void setChiPhi(double cp) { chiPhi = cp; }

    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif
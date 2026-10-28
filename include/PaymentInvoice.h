#ifndef PAYMENT_INVOICE_H
#define PAYMENT_INVOICE_H

// Tac gia: Mai Tat Dat
#include "../Entity.h"
#include <string>

// Lop thuc the UC10: Quan ly hoa don thanh toan cho du an trien khai mang.
class PaymentInvoice : public Entity {
private:
    std::string maHoaDon;
    std::string maDuAn;
    std::string maNhaCungCap;
    std::string ngayLap;
    double tongTien;
    std::string trangThai;
    std::string ghiChu;

    static void validateField(const std::string& value,
                              const std::string& tenTruong,
                              bool choPhepTrong = false);
    static bool isValidDate(const std::string& date);

public:
    // Tao hoa don rong de Repository nap du lieu tu file.
    PaymentInvoice();

    // Lay ma hoa don lam ma dinh danh duy nhat.
    std::string getId() const override;

    // Cac getter cua hoa don.
    std::string getMaHoaDon() const;
    std::string getMaDuAn() const;
    std::string getMaNhaCungCap() const;
    std::string getNgayLap() const;
    double getTongTien() const;
    std::string getTrangThai() const;
    std::string getGhiChu() const;

    // Cac setter co kiem tra du lieu hop le.
    void setMaHoaDon(const std::string& ma);
    void setMaDuAn(const std::string& ma);
    void setMaNhaCungCap(const std::string& ma);
    void setNgayLap(const std::string& ngay);
    void setTongTien(double tien);
    void setTrangThai(const std::string& trangThaiMoi);
    void setGhiChu(const std::string& ghiChuMoi);

    // Nhap day du thong tin hoa don tu ban phim.
    void input() override;

    // Hien thi hoa don theo dang mot dong cua bang.
    void display() const override;

    // Chuyen doi hoa don thanh mot dong phan cach bang ky tu '|'.
    std::string toString() const override;

    // Nap hoa don tu mot dong file; nem exception neu sai dinh dang.
    void fromString(const std::string& line) override;

    // In tieu de bang hoa don thanh toan.
    static void printHeader();
};

#endif

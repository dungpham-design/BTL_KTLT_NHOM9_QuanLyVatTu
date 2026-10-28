#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Entity.h"
#include <string>

// Tac gia: Mai Tat Dat
// Lop thuc the quan ly nha cung cap vat tu cho du an mang.
class Supplier : public Entity {
private:
    std::string maNhaCungCap;
    std::string tenNhaCungCap;
    std::string diaChi;
    std::string soDienThoai;
    std::string email;

public:
    // Khoi tao doi tuong rong de Repository co the nap du lieu tu file.
    Supplier();

    // Khoi tao nha cung cap voi day du thong tin.
    Supplier(const std::string& ma, const std::string& ten,
        const std::string& diaChi, const std::string& soDienThoai,
        const std::string& email);

    // Tra ve ma nha cung cap, dong thoi la ma dinh danh duy nhat.
    std::string getId() const override;

    // Cac getter tra ve thong tin nha cung cap.
    std::string getMaNhaCungCap() const;
    std::string getTenNhaCungCap() const;
    std::string getDiaChi() const;
    std::string getSoDienThoai() const;
    std::string getEmail() const;

    // Cac setter kiem tra du lieu truoc khi cap nhat.
    void setMaNhaCungCap(const std::string& ma);
    void setTenNhaCungCap(const std::string& ten);
    void setDiaChi(const std::string& diaChi);
    void setSoDienThoai(const std::string& soDienThoai);
    void setEmail(const std::string& email);

    // Nhap thong tin nha cung cap tu ban phim.
    void input() override;

    // Hien thi thong tin thanh mot dong cua bang.
    void display() const override;

    // Chuyen doi doi tuong thanh mot dong du lieu phan cach bang dau |.
    std::string toString() const override;

    // Nap thong tin tu mot dong du lieu; nem ngoai le neu sai dinh dang.
    void fromString(const std::string& line) override;

    // In hang tieu de bang danh sach nha cung cap.
    static void printHeader();

private:
    // Kiem tra chuoi bat buoc va khong chua ky tu phan cach cua file.
    static void validateRequiredField(const std::string& value,
        const std::string& fieldName);
};

#endif

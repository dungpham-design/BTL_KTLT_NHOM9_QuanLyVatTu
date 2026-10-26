#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Entity.h"
#include <string>

class Supplier : public Entity {
private:
    std::string maNCC;
    std::string tenNCC;
    std::string diaChi;
    std::string soDienThoai;
    std::string email;

public:
    Supplier();
    Supplier(std::string ma, std::string ten, std::string dc, std::string sdt, std::string em);
    ~Supplier() override = default;

    std::string getId() const override;
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();

    // Getters & Setters
    std::string getMaNCC() const;
    void setMaNCC(const std::string& ma);
    std::string getTenNCC() const;
    void setTenNCC(const std::string& ten);
    std::string getDiaChi() const;
    void setDiaChi(const std::string& dc);
    std::string getSoDienThoai() const;
    void setSoDienThoai(const std::string& sdt);
    std::string getEmail() const;
    void setEmail(const std::string& em);
};

#endif
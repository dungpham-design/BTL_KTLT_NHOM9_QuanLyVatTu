#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Entity.h"
#include <string>

class Material : public Entity {
private:
    std::string maVatTu;
    std::string tenVatTu;
    std::string maDanhMuc;
    std::string donViTinh;
    double donGia;
    int soLuongTon;

public:
    Material();
    Material(const std::string& ma, const std::string& ten, const std::string& maDM, 
             const std::string& dvt, double gia, int sl);

    std::string getId() const override;
    
    // Getters & Setters
    std::string getMaVatTu() const;
    void setMaVatTu(const std::string& ma);
    
    std::string getTenVatTu() const;
    void setTenVatTu(const std::string& ten);
    
    std::string getMaDanhMuc() const;
    void setMaDanhMuc(const std::string& maDM);
    
    std::string getDonViTinh() const;
    void setDonViTinh(const std::string& dvt);
    
    double getDonGia() const;
    void setDonGia(double gia);
    
    int getSoLuongTon() const;
    void setSoLuongTon(int sl);

    // Virtual methods from Entity
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif // MATERIAL_H

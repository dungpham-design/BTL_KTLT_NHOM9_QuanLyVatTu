#ifndef MATERIAL_CATEGORY_H
#define MATERIAL_CATEGORY_H

#include "../Entity.h"
#include "../InputHelper.h"
#include <string>
#include <iomanip>
#include <iostream>

class MaterialCategory : public Entity {
private:
    std::string maDanhMuc;
    std::string tenDanhMuc;
    std::string moTa;

public:
    MaterialCategory();
    MaterialCategory(std::string ma, std::string ten, std::string mota);

    std::string getId() const override;

    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();

    std::string getMaDanhMuc() const;
    void setMaDanhMuc(const std::string& ma);
    std::string getTenDanhMuc() const;
    void setTenDanhMuc(const std::string& ten);
    std::string getMoTa() const;
    void setMoTa(const std::string& mota);
};

#endif // MATERIAL_CATEGORY_H
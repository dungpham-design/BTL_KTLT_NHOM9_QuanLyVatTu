#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "../Entity.h"
#include <string>
#include <sstream>
#include <iomanip>

class Warehouse : public Entity {
private:
    std::string maKho;
    std::string tenKho;
    std::string diaChiKho;
    std::string nguoiQuanLy;
    int sucChua; // Suc chua (m2 hoac so ton)

public:
    Warehouse();
    Warehouse(std::string ma, std::string ten, std::string diaChi, std::string ql, int sc);
    ~Warehouse() override = default;

    // Getters & Setters
    std::string getId() const override { return maKho; }
    void setMaKho(const std::string& ma) { maKho = ma; }

    std::string getTenKho() const { return tenKho; }
    void setTenKho(const std::string& ten) { tenKho = ten; }

    std::string getDiaChiKho() const { return diaChiKho; }
    void setDiaChiKho(const std::string& diaChi) { diaChiKho = diaChi; }

    std::string getNguoiQuanLy() const { return nguoiQuanLy; }
    void setNguoiQuanLy(const std::string& ql) { nguoiQuanLy = ql; }

    int getSucChua() const { return sucChua; }
    void setSucChua(int sc) { sucChua = sc; }

    // Ghi dè các hàm thu?n ?o t? l?p Entity
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif
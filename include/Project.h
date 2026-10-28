#ifndef PROJECT_H
#define PROJECT_H

#include "../Entity.h"
#include <string>
#include <sstream>
#include <iomanip>

class Project : public Entity {
private:
    std::string maDA;
    std::string tenDA;
    std::string diaBan;
    std::string ngayBatDau;
    std::string ngayHoanThanhDuKien;
    std::string trangThai; // Dang thi cong / Hoan thanh / Tam dung

public:
    Project();
    Project(std::string ma, std::string ten, std::string db, std::string bd, std::string ht, std::string tt);

    // Getters & Setters
    std::string getId() const override { return maDA; }
    void setMaDA(const std::string& ma) { maDA = ma; }

    std::string getTenDA() const { return tenDA; }
    void setTenDA(const std::string& ten) { tenDA = ten; }

    std::string getDiaBan() const { return diaBan; }
    void setDiaBan(const std::string& db) { diaBan = db; }

    std::string getNgayBatDau() const { return ngayBatDau; }
    void setNgayBatDau(const std::string& bd) { ngayBatDau = bd; }

    std::string getNgayHoanThanhDuKien() const { return ngayHoanThanhDuKien; }
    void setNgayHoanThanhDuKien(const std::string& ht) { ngayHoanThanhDuKien = ht; }

    std::string getTrangThai() const { return trangThai; }
    void setTrangThai(const std::string& tt) { trangThai = tt; }

    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif

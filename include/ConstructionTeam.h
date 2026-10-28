#ifndef CONSTRUCTION_TEAM_H
#define CONSTRUCTION_TEAM_H

#include "Entity.h"
#include <string>
#include <sstream>
#include <iomanip>

class ConstructionTeam : public Entity {
private:
    std::string maDoiTC;
    std::string tenDoi;
    std::string doiTruong;
    std::string soDienThoai;
    int soLuongNhanSu;

public:
    ConstructionTeam();
    ConstructionTeam(std::string ma, std::string ten, std::string dt, std::string sdt, int sl);

    // Getters & Setters
    std::string getId() const override { return maDoiTC; }
    void setMaDoiTC(const std::string& ma) { maDoiTC = ma; }
    
    std::string getTenDoi() const { return tenDoi; }
    void setTenDoi(const std::string& ten) { tenDoi = ten; }

    std::string getDoiTruong() const { return doiTruong; }
    void setDoiTruong(const std::string& dt) { doiTruong = dt; }

    std::string getSoDienThoai() const { return soDienThoai; }
    void setSoDienThoai(const std::string& sdt) { soDienThoai = sdt; }

    int getSoLuongNhanSu() const { return soLuongNhanSu; }
    void setSoLuongNhanSu(int sl) { soLuongNhanSu = sl; }

    // Ghi đè các hàm từ Entity
    void input() override;
    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& line) override;

    static void printHeader();
};

#endif
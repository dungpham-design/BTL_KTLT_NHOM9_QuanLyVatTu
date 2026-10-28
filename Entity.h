#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity {
public:
    virtual ~Entity() {}

    // Lấy mã định danh duy nhất của đối tượng
    virtual std::string getId() const = 0;

    // Các hàm thuần ảo bắt buộc ở lớp con
    virtual void input() = 0;
    virtual void display() const = 0;
    virtual std::string toString() const = 0;
    virtual void fromString(const std::string& line) = 0;
};

#endif
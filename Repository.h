#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

template <typename T>
class Repository {
private:
    std::vector<T> items;
    std::string filePath;

public:
    Repository(const std::string& path) : filePath(path) {
        loadFromFile();
    }

    const std::vector<T>& getAll() const {
        return items;
    }

    void add(const T& item) {
        items.push_back(item);
        saveToFile();
    }

    T* findById(const std::string& id) {
        for (auto& item : items) {
            if (item.getId() == id) {
                return &item;
            }
        }
        return nullptr;
    }

    bool update(const std::string& id, const T& newItem) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getId() == id) {
                items[i] = newItem;
                saveToFile();
                return true;
            }
        }
        return false;
    }

    bool remove(const std::string& id) {
        auto it = std::remove_if(items.begin(), items.end(),
            [&id](const T& item) { return item.getId() == id; });
        if (it != items.end()) {
            items.erase(it, items.end());
            saveToFile();
            return true;
        }
        return false;
    }

    void loadFromFile() {
        items.clear();
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::ofstream newFile(filePath);
            newFile.close();
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue;
            T item;
            try {
                item.fromString(line);
                items.push_back(item);
            } catch (...) {
                std::cerr << "Canh bao: Dong sai dinh dang trong file " << filePath << std::endl;
            }
        }
        file.close();
    }

    void saveToFile() const {
        std::ofstream file(filePath);
        if (!file.is_open()) return;

        for (const auto& item : items) {
            file << item.toString() << "\n";
        }
        file.close();
    }
};

#endif 	
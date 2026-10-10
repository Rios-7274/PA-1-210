#pragma once
#include <ostream>
#include <string>

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {
    }

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

private:
    int id_;
    std::string name_;
};

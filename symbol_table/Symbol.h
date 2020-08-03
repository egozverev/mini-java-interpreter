#pragma once

#include <string>
#include <unordered_map>
#include <memory>


class Symbol {
 public:
    
    bool operator==(const Symbol& other) const;
    bool operator!=(const Symbol& other) const;
    std::string GetName() const;
    explicit Symbol(const std::string& name);
    Symbol(const Symbol& other) = default;
 private:
    std::string name_;
};

namespace std {
    template<>
    struct hash<Symbol>
    {
        std::size_t operator()(const Symbol& other) const {
            return hash<string>()(other.GetName());
        }
    };
    
}


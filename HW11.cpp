#include <iostream>
#include <string>
class Pokemon {
public:
    Pokemon(int level, const std::string& type) 
        : level(level), type(type) {}
    virtual ~Pokemon() {}
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;
    void showInfo() const {
        std::cout << "Level: " << level << ", Type: " << type << std::endl;
    }
protected:
    int level;
    std::string type;
};
class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(int level) 
        : Pokemon(level, "Electric") {}

    void attack() const override {
        std::cout << "Electric attack!" << std::endl;
    }

    void defend() const override {
        std::cout << "Electric defense!" << std::endl;
    }

    void evolve() override {
        std::cout << "Evolving into a stronger Electric Pokémon!" << std::endl;
    }
};
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int level) : ElectricPokemon(level) {}

    void attack() const override {
        std::cout << "Pikachu uses Thunderbolt!" << std::endl;
    }

    void defend() const override {
        std::cout << "Pikachu dodges the attack!" << std::endl;
    }

    void evolve() override {
        std::cout << "Pikachu is evolving into Raichu!" << std::endl;
    }
};

int main() {
    Pikachu pikachu(10);
    pikachu.showInfo(); 
    pikachu.attack();    
    pikachu.defend();    
    pikachu.evolve();    
    return 0;
}

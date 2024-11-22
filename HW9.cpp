#include <iostream>
#include <string>
using namespace std;

class Rock {
public:
    void attack() {
        cout << "Attack the rock" << endl;
    }
    void attack(int damage) {
        cout << "You deal " << damage << " damage" << endl;
    }

    void attack(string spell, int damage) {
        cout << "You cast '" << spell << "' and inflict" << damage << "  damage" << endl;
    }
};
int main() {
    Rock rock;

    rock.attack();      
    rock.attack(15);                
    rock.attack("zap", 20);    

    return 0;
}

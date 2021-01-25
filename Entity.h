using namespace std;
#include<string>

class Entity {
    
private:
    string hp;
    string spells;
    string pos;

    // function
public:
    Entity();

    Entity(string, string, string);

    void setHP(string);

    string getHP();

    void setSpell(string);

    string getTelNo();

    void setPos(string);

    string getPos();
};
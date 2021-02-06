 #ifndef EntityClasses_h
 #define EntityClasses_h

#include "Entity.h"

class Walls : public Entity{
public:
    Walls(int hp, int armor, int maxmp, bool moveable);    
    Walls();
};


class Melee : public Entity{
    Melee(int hp, int armor, int maxmp, int x, int y, bool moveable);
};


class Ranged : public Entity{
    Ranged(int hp, int armor, int maxmp, int x, int y, bool moveable);
};

#endif  

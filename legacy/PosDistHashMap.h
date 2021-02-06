#ifndef posdisthashmap_h
#define posdisthashmap_h
#include "VHashMap.h"

// Forward Declaration
class AbsolutePosition;

class PosDistHashMap : public VHashMap<AbsolutePosition, int> {
private:
public:
    PosDistHashMap();
    ~PosDistHashMap();

    int hash(AbsolutePosition absPos);

    // specialized functions
    void add(AbsolutePosition newKey, int newVal);
    void remove(AbsolutePosition existingKey);
    void set(AbsolutePosition existingKey, int newVal);
    int* get(AbsolutePosition existingKey);
    bool isEmpty();
    int getSize();
    int getCapacity();
};

#endif
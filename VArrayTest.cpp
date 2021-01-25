#include "VArray.h"
#include "VArray.cpp"
#include <iostream>

int main() {
    VArray<int> varray;
    int choice = -1;
    while(choice != 0) {
        std::cout << "[0]: Exit\n[1]: Push\n[2]: Set\n[3]: Get\n[4]: Remove\n[5]: Print\nEnter your option: ";
        std::cin >> choice;
        if(choice == 1) {
            int item, index;
            std::cout << "Enter: [item] [index]: ";
            std::cin >> item >> index;
            if(index == -999) {
                varray.push(item);
            } else {
                varray.push(item, index);
            }
        } else if(choice == 2) {
            int item, index;
            std::cout << "Enter: [item] [index]: ";
            std::cin >> item >> index;
            varray[index] = item;
        } else if(choice == 3) {
            int index;
            std::cout << "Enter: [index]: ";
            std::cin >> index;
            std::cout << "Return value: " << varray[index] << std::endl;
        } else if(choice == 4) {
            int index;
            std::cout << "Enter: [index]: ";
            std::cin >> index;
            varray.remove(index);
        } else if(choice == 5) {
            varray.print();
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include "dynamic_array.h"

int main(){
    
    DynamicStringArray d, d_copy, d_assigned;
    std::string *res;

    d.addEntry("e1");
    d.addEntry("e2");
    d.addEntry("e3");
    
    std::cout<<d.getSize()<<"\n";

    res = d.getEntry(2);
    
    std::cout<<*res<<"\n";

    d.deleteEntry("e2");

    d.display();

    d_copy = d;

    d_copy.display();

    return 0;
}
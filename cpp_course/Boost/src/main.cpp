#include <iostream>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <string>

using namespace boost::interprocess;

int main() {

    std::cout<<"Run\n";

    /*
    shared_memory_object::remove("Denumirea_memoriei");
    managed_shared_memory managed_shm{open_or_create, "Denumirea_memoriei", 1024};
    std::string *i = managed_shm.construct<std::string>("Denumirea")("zaur");
    std::cout << *i << '\n';
    std::pair<std::string *, std::size_t> p = managed_shm.find<std::string>("Denumirea");
    if (p.first)
        std::cout << *p.first << '\n';
    */

    //shared_memory_object::remove("Boost");
    managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
    int *i = managed_shm.find_or_construct<int>("Integer")(99);
    std::cout << *i << '\n';
    managed_shm.destroy<int>("Integer");
    std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer");
    std::cout << p.first << '\n';


    
    return 0;
}
#include <string>
#include <iostream>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <mutex>

using namespace boost::interprocess;



class Thermostat {
        

    public:

        float desiredTemp, extTemp;

        int readTemperature() {
            std::string des, ext;

            while(1) {
            
                std::cin >> des;                
                std::cin >> ext;

                if(des == "exit" || ext == "exit") {
                    return 0;
                }


                float desired, exterior;

                desired = stof(des);
                exterior = stof(ext);

                if(desired < 16.0f || desired > 34.0f || exterior < -10.0f || exterior > 40.0f) {
                    std::cout << "Invalid temperatures\n";
                    shared_memory_object::remove("Boost");
                    return -1;
                }

                
                managed_shared_memory managed_shm_mtx{open_or_create, "M1", 1024};
                interprocess_mutex *m1 = managed_shm_mtx.find_or_construct<interprocess_mutex>("M1")();
                

                

                //named_mtx.lock();
                //++(*i);
                //std::cout << *i << '\n';
                

                //shared_memory_object::remove("Boost");

                m1->lock();

                managed_shared_memory managed_shm_temp{open_or_create, "Boost", 1024};
                //managed_shared_memory managed_shm{open_or_create, "shm", 1024};
                float* rez = managed_shm_temp.find_or_construct<float>("sentExt")(exterior); //pt a extrage val *sentExt.first
                float* rez1 = managed_shm_temp.find_or_construct<float>("sentDes")(desired);
                //managed_shm.construct<Thermostat>("sentThermo")(this);

                m1->unlock();
                //named_mtx.unlock();
                

                
                


            }
        }
};
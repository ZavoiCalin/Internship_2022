#include <iostream>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <mutex>
#include <chrono>
#include <thread>

using namespace boost::interprocess;



class ACUnit {
    private:
        float roomTemp, exteriorTemp;
        

    public:

        int crtState;

        managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
        std::pair<float *, size_t> desReceived = managed_shm.find<float>("sentDes");
        std::pair<float *, size_t> extReceived = managed_shm.find<float>("sentExt");
        //std::pair<Thermostat *, size_t> thermoReceived = managed_shm.find<Thermostat>("sentThermo");

        ACUnit() {
            roomTemp = 20.0f;
            crtState = 1;
        }

        float getRoom() {
            return roomTemp;
        }

        float getExt() {
            return exteriorTemp;
        }

        float getState() {
            return crtState;
        }

        void setState(int s) {
            crtState = s;
        }


        /*
        void checkTurnOff() {
            float roomT = this->getRoom();

            if (roomT == *desReceived.first) {
                std::cout << "Turning off\n";
            }

            
        }
        */

        void checkACOff() {
        
            float roomT = this->getRoom();

            while (*extReceived.first < roomT) {
                roomT += 0.1;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "AC is off and room temperature is " << this->getRoom() << "\n";
            }

            while (*extReceived.first > roomT) {
                roomT -= 0.1;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "AC is off and room temperature is " << this->getRoom() << "\n";
            }

            this->crtState = 0;
        }

        void startAC() {

            //shared_memory_object::remove("Boost");
            managed_shared_memory managed_shm_mtx{open_or_create, "Boost", 1024};
            interprocess_mutex *m1 = managed_shm_mtx.find_or_construct<interprocess_mutex>("M1")();

            m1->lock();

            //shared_memory_object::remove("Boost");
            managed_shared_memory managed_shm{open_or_create, "Boost", 1024};
            std::pair<float *, size_t> desReceived = managed_shm.find<float>("sentDes");
            std::pair<float *, size_t> extReceived = managed_shm.find<float>("sentExt");
            //std::pair<Thermostat *, size_t> thermoReceived = managed_shm.find<Thermostat>("sentThermo");

            m1->unlock();

            if (desReceived.first && extReceived.first) {
                std::cout << this->getRoom() << "\n";
                std::cout << *desReceived.first << "\n";
                std::cout << *extReceived.first << "\n";
            }

            float tempDelta = *desReceived.first - this->getRoom();
            float roomT = this->getRoom();

            if (tempDelta >= 1.0f) {
                std::cout << "Heating\n";
                

                while (roomT < *desReceived.first) {
                    roomT += 0.5f;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Room temperature = " << roomT << "\n";
                    
                }

                
                this->crtState = 1;
                
            }


            if (tempDelta <= -1.0f) {
                std::cout << "Cooling\n";

                while (roomT > *desReceived.first) {
                    roomT -= 0.5f;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << "Room temperature = " << roomT << "\n";
                }

                if (roomT == *desReceived.first) {
                    std::cout << "Turning off\n";
                    
                }

                this->crtState = 1;
                
                
            }

            
        }

};

//de folosit
/*
using namespace boost::interprocess;

int main()
{
  managed_shared_memory managed_shm{open_or_create, "shm", 1024};
  int *i = managed_shm.find_or_construct<int>("Integer")(0);
  named_mutex named_mtx{open_or_create, "mtx"};
  named_condition named_cnd{open_or_create, "cnd"};
  scoped_lock<named_mutex> lock{named_mtx};
  while (*i < 10)
  {
    if (*i % 2 == 0)
    {
      ++(*i);
      named_cnd.notify_all();
      named_cnd.wait(lock);
    }
    else
    {
      std::cout << *i << std::endl;
      ++(*i);
      named_cnd.notify_all();
      named_cnd.wait(lock);
    }
  }
  named_cnd.notify_all();
  shared_memory_object::remove("shm");
  named_mutex::remove("mtx");
  named_condition::remove("cnd");
}
*/
#include <iostream>
#include "thermostat.h"
#include "acunit.h"
#include <mutex>

/*state machine*/

//mutex pentru sync de shared memory de la boost::
//link uri de la task
//link din conversatie google hangouts

typedef allocator<int, managed_shared_memory::segment_manager> sharedMemoryAllocator;
typedef vector<int, sharedMemoryAllocator> clientVector;

int main() {
    ACUnit ac;
    int c = 0, total;

    int users, exteriorTemperature, desiredTemperature, Pstart = 0, Pend = 2, i = 2;

    managed_shared_memory segment(open_only, "MySharedMemoryNew");

    clientVector *crtVector = segment.find<clientVector>("sharedClientVector").first;

    if (!(crtVector->empty()))
    {
        c = (*crtVector)[0];
        total += c;
    }

            
    
    while(1) {
        switch(ac.crtState) {
            case 0:
                crtVector->erase(std::next(crtVector->begin(), Pstart),
                std::next(crtVector->begin(), Pend));

                crtVector->erase(std::next(crtVector->begin(), i - 2));

                if (crtVector->empty()) {
                    crtVector->insert(crtVector->begin() + 0, c);
                    crtVector->insert(crtVector->begin() + 1, exteriorTemperature);
                }

                else {
                    crtVector->erase(std::next(crtVector->begin(), Pstart),
                                std::next(crtVector->begin(), Pend));

                    crtVector->insert(crtVector->begin() + 0, c);
                    crtVector->insert(crtVector->begin() + 1, exteriorTemperature);
                 }

                ac.startAC();
                break;

            case 1:

                if (i == (*crtVector).size()) {

                    crtVector->insert(crtVector->begin() + i, desiredTemperature);

                    i++;

                    break;
                }

                

                else {
                    crtVector->insert(crtVector->begin() + i, desiredTemperature);
                }


                ac.checkACOff();

                for (int j = 0; j < (*crtVector).size(); j++) {

                    std::cout << (*crtVector)[j] << " ";
                }

                break;

        }
    }

    return 0;
}

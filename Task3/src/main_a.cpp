#include <iostream>
#include "thermostat.h"
#include "acunit.h"
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <mutex>

/*state machine*/

//mutex pentru sync de shared memory de la boost::
//link uri de la task
//link din conversatie google hangouts

int main() {
    ACUnit ac;
    
    while(1) {
        switch(ac.crtState) {
            case 0:
                ac.startAC();
                break;
            case 1:
                ac.checkACOff();
                break;

        }
    }

    return 0;
}
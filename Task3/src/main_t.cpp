#include <iostream>
#include "thermostat.h"
#include "acunit.h"
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <mutex>


int main() {

    Thermostat thermo;
    thermo.readTemperature();

    return 0;
}

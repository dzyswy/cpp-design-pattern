#include "car.h"




int main()
{
    MotoCarBom motocar_bom;
    SUVBom suv_bom;
    BUSBom bus_bom;

    MotoCarProcess motocar_process(&motocar_bom);
    SUVProcess suv_process(&suv_bom);
    BUSProcess bus_process(&bus_bom);

    std::shared_ptr<Car> motocar = motocar_process.process();
    std::shared_ptr<Car> suv = suv_process.process();
    std::shared_ptr<Car> bus = bus_process.process();

    motocar->info();
    suv->info();
    bus->info();


    return 0;
}
















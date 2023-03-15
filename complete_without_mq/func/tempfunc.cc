#include "../includes/tempfunc.h"

void temperature::templocation()
{
    in[TEMP_TYPE_0].open("/sys/class/thermal/thermal_zone0/temp");
    in[TEMP_TYPE_1].open("/sys/class/thermal/thermal_zone1/temp");
}

void sigint_handler(int isgno)
{
    cout << temperature::Temp_Out(); << "Interval : %d\n" << z << endl;
    z++;
    counter += end;
    alarm(end);
}

void temperature::Temp_Out()
{
    if(temp_sensor == 1)
    {
        temperature::Temp_Zone0((TEMP_TYPE)(temp_sensor -1));
    }

    else if(temp_sensor == 2)
    {
        temperature::Temp_Zone1((TEMP_TYPE)(temp_sensor -1));
    }
}

void temperature::Temp_Zone0(TEMP_TYPE type)
{
    in[type] >> value;
    std::cout << "temp_zone0 temperature is :: " << value << "℃" << std::endl;
}

void temperature::Temp_Zone1(TEMP_TYPE type)
{
    in[type] >> value;
    std::cout << "temp_zone1 temperature is :: " << value << "℃" << std::endl;
}
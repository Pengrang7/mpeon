#include "../includes/tempfunc.h"
#include "../includes/header.h"

void temperature::Temp_Out()
{
    if(msg.LN == 1)
    {
        temperature::Temp_Zone0((TEMP_TYPE)(msg.opcode -1));
    }

    else if(msg.LN == 2)
    {
        temperature::Temp_Zone1((TEMP_TYPE)(msg.opcode -1));
    }
}

void temperature::Temp_Zone0(TEMP_TYPE type)
{
    ifstream in("/sys/class/thermal/thermal_zone0/temp");
    in >> value;
    std::cout << "온도 :: " << value << "℃" << std::endl;
}

void temperature::Temp_Zone1(TEMP_TYPE type)
{
    ifstream in("/sys/class/thermal/thermal_zone1/temp");  
    in >> value;
    std::cout << "온도 :: " << value << "℃" << std::endl;
}
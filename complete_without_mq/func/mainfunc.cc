#include "ui_main.h"
// #include "ledfunc.h" 
// #include "tempfunc.h"

void UI_MAIN::main_ui_init(UI_INSERT type)
{   
    led led;
    temperature temp;

    switch(insert -1)
    {
        case UI_LED:
        cout << "This is LED Controller" << endl;
        cout << "Please Choose What Led You Want to Control" << endl;
        cout << "1.GNSS LED    2.WAVE LED    3.C-V2X LED    4.5G LED    5.RUN LED    6.EXIT" << endl;
        cin >> led.gpio_num;
        cout << "Select Your LED Status Insert ( 0 is off, 1 is on)" << endl;
        cin >> led.led_num;
        led.Out();
        break;

        case UI_TEMP:
        cout << "This is Temperature sensor Controller" << endl;
        cout << "Please Choose What Sensor You Want to Control" << endl;
        cout << "1.Temperature Seneor 1    2.Temperature Sensor 2" << endl;
        cin >> temp.temp_sensor;
        temp.Temp_Out();
        break;

        case UI_GPS:
        cout << "This is Temperature Sensor Controller" << endl;
        cout << "Please Insert Interval of You Want to Receive Data" << endl;
        cin >> 

        struct gps_data_t g_GpsData;

        
        
    }
}

// #include "includes/common.h"
#include "includes/ui_main.h"

using namespace std;

int main()
{
    
    UI_MAIN main;
    cout << "This is Main UI!!!" << endl;
    cout << "Please Select What do You Want to Control!!!" << endl;
    cout << "1.LED    2.Temperature    3.GPS" << endl;
    cin >> main.insert;
    main.main_ui_init((UI_INSERT)(main.insert));

}

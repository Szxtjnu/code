#include "cubeVolume.h"
#include<cstdlib>
#include<iostream>
int main()
{
    cubeVolume cube[3];
    int i;
    for ( i = 0; i < 3 ; i++)
    {
        std::cout << "Enter " << i + 1 << "th cube:" << std::endl;
        cube[i].set_volume();
        cube[i].cal_volume();
        cube[i].show_colume();
    }
    system("pause");
    return 0;
}
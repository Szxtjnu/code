#include "cubeVolume.h"
#include<iostream>

using namespace std;

void cubeVolume::set_volume()
{
    cout << "L:";
    cin >> length;
    cout << "W:";
    cin >> width;
    cout << "H:";
    cin >> height;
}

void cubeVolume::cal_volume()
{
    volume = length * height * width;
}

void cubeVolume::show_colume()
{
    cout << "The volume is " << volume << endl;
}
#ifndef _CUBEVOLUME_H
#define _CUBEVOLUME_H

class cubeVolume
{
private:
    int length;
    int width;
    int height;
    int volume;

public:

    void set_volume();
    void cal_volume();
    void show_colume();
};

#endif

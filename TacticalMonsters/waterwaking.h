#ifndef WATERWAKING_H
#define WATERWAKING_H

#include "agent.h"

class WaterWalking : public Agent
{

public:
    WaterWalking(char player_type, QWidget* parent, play_page * page, string input_name);
    void Unlock_allCompatibleHexas();

private:
    void setWariourProperties();
    //vo
};

#endif // WATERWAKING_H

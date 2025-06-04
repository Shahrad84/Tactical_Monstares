#ifndef WATERWAKING_H
#define WATERWAKING_H

#include "agent.h"

class WaterWaking : public Agent
{

public:
    WaterWaking(char player_type, QWidget* parent, play_page * page, string input_name);

private:
    void setWariourProperties();
    //void Render_Agent();
};

#endif // WATERWAKING_H

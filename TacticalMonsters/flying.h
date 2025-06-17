#ifndef FLYING_H
#define FLYING_H

#include "agent.h"

class Flying : public Agent
{

public:
    Flying(char player_type, QWidget* parent, play_page * page, string input_name);
    void Unlock_allCompatibleHexas();

private:
    void setWariourProperties();
    //void Render_Agent();
};

#endif // FLYING_H

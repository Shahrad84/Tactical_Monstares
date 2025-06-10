#ifndef FLOATING_H
#define FLOATING_H

#include "agent.h"

class Floating : public Agent
{

public:
    Floating(char player_type, QWidget* parent, play_page * page, string input_name);
    void Unlock_allCompatibleHexas();

private:
    void setWariourProperties();
    //void Render_Agent();
};

#endif // FLOATING_H

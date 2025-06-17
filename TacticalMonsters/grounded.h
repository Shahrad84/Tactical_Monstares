#ifndef GROUNDED_H
#define GROUNDED_H

#include "agent.h"

class Grounded : public Agent
{

public:
    Grounded(char player_type, QWidget* parent, play_page * page, string input_name);
    void Unlock_allCompatibleHexas();

private:
    void setWariourProperties();
    //vo
};

#endif // GROUNDED_H

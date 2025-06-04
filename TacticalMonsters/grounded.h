#ifndef GROUNDED_H
#define GROUNDED_H

#include "agent.h"

class Grounded : public Agent
{

public:
    Grounded(char player_type, QWidget* parent, play_page * page, string input_name);

private:
    void setWariourProperties();
    //void Render_Agent();
};

#endif // GROUNDED_H

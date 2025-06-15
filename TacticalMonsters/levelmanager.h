#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "string"
using std::string;

class play_page;

class LevelManager
{
public:
    LevelManager(play_page *);

    void Update();
    string get_level();
    void agentDied(char);

private:
    play_page * playPage;
    string level;
    int agentLockCount;
    void Go_to_level_Fight();

    int player_1_remained_agents;
    int player_2_remained_agents;
};

#endif // LEVELMANAGER_H

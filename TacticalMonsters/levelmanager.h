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

private:
    play_page * playPage;
    string level;
    int agentLockCount;
    void Go_to_level_Fight();
};

#endif // LEVELMANAGER_H

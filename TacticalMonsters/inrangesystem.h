#ifndef INRANGESYSTEM_H
#define INRANGESYSTEM_H

#include "hexa.h"
#include "play_page.h"
#include <vector>
#include <queue>
using std::vector;
using std::queue;

class InRangeSystem
{
public:
    InRangeSystem(play_page * input_playPage);

    queue <Hexa *> Find_in_range(Hexa *, int);



private:
    vector <Hexa *> visited;
    queue <Hexa *> result;
    queue <Hexa *> inProcess;
    static play_page * playPage;

    void clear_queue_and_vector();

    bool isVisited(const vector <Hexa*> visited, Hexa * node);
    bool find_in_queue(Hexa * data, queue<Hexa *> input_q);
};

#endif // INRANGESYSTEM_H

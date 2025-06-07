#ifndef INRANGESYSTEM_H
#define INRANGESYSTEM_H

#pragma once;

#include "hexa.h"
#include "play_page.h"
#include <vector>
#include <queue>
#include "agent.h"
using std::vector;
using std::queue;

class Hexa;

class InRangeSystem
{
public:
    InRangeSystem(play_page * input_playPage);

    void Find_in_range(Agent *, int);

    queue <Hexa *> get_attackable_hexas();
    queue <Hexa *> get_movebale_hexas();
    Hexa * movebale_hexas_with_index(int);


    bool find_in_queue(Hexa * data, queue<Hexa *> input_q);
    void clear_queue_and_vector();


private:
    vector <Hexa *> visited;
    queue <Hexa *> moveable_hexas;
    queue <Hexa *> inProcess;
    queue <Hexa *> attackable_hexas;
    static play_page * playPage;

    void reDraw_hexa(queue <Hexa *>, char, string);

    bool isVisited(const vector <Hexa*> visited, Hexa * node);

    bool find_in_vector(Hexa * data, queue<Hexa *> input_q);
};

#endif // INRANGESYSTEM_H

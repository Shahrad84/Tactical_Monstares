#ifndef AGENT_H
#define AGENT_H

#pragma once

#include "hexa.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <play_page.h>
#include "string"
#include "vector"
#include "inrangesystem.h"

using std::string;
using std::vector;

//#include "floating.h"
class Hexa;

class Agent : public QLabel
{
    Q_OBJECT

public:
    Agent(char input_ownership, QWidget* parent, play_page * page, string input_name);
    ~Agent();
    void Move(Hexa* new_hexa);

    static Agent * clicked_agent;
    Hexa * located_hexa;
    char ownership;

    static play_page * playPage;
    void LockAgent(bool);
    bool get_isLock();


    vector <char> compatible_types_to_LOCATE;
    vector <char> compatible_types_to_PASS;
    bool is_hexa_compatible(Hexa *, vector <char>);


    void Attack(Agent *);

    void reduce_HP(int);
    int get_HP();
    int get_damage();

    virtual void Unlock_allCompatibleHexas() = 0;

private:
    char type;
    int x_pos;
    int y_pos;
    int size;
    static InRangeSystem * in_range_system;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    virtual void Render_Agent();

    int HP;
    int mobility;
    int attackRange;
    int damage;
    string name;

    bool isLock;
};


#endif // AGENT_H

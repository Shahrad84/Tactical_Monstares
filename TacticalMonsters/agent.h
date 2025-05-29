#ifndef AGENT_H
#define AGENT_H

#pragma once

#include "hexa.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <play_page.h>
#include "string"
using std::string;

//#include "floating.h"
class Hexa;

class Agent : public QLabel
{
    Q_OBJECT

public:
    Agent(char player_type, QWidget* parent, play_page * page, string input_name);
    void Move(Hexa* new_hexa);

    static Agent * clicked_agent;
    Hexa * located_hexa;
    char player_1_or_2;

    static play_page * playPage;

private:
    char type;
    int x_pos;
    int y_pos;
    int size;

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
};


#endif // AGENT_H

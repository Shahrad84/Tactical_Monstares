#ifndef AGENT_H
#define AGENT_H

#pragma once

#include "hexa.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include <play_page.h>


class Hexa;

class Agent : public QLabel
{
    Q_OBJECT

public:
    explicit Agent(char player_type, QWidget* parent = nullptr);
    void Move(Hexa* new_hexa);

    static Agent * clicked_agent;
    Hexa * located_hexa;
    char player_1_or_2;

    static char turn;
    void change_turn();
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
};


#endif // AGENT_H

#ifndef HEXA_H
#define HEXA_H

#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include "agent.h"
#include "QChar"
#include "play_page.h"

class Agent;

class Hexa : public QLabel
{
    Q_OBJECT

public:
    explicit Hexa(int row, int col, QWidget *parent, play_page * page);
    ~Hexa();

    void Set_type(char input_type);

    //void Determine_x_and_y(int row, int col);

    int get_x_position();
    int get_y_position();
    Agent * located_agent = nullptr;
    char get_type();


    Hexa * get_up();
    Hexa * get_down();
    Hexa * get_right_up();
    Hexa * get_right_down();
    Hexa * get_left_up();
    Hexa * get_left_down();
    int get_i();
    int get_j();


private:
    int x_pos;
    int y_pos;
    char type;
    static play_page * playPage;

    Hexa * up;
    Hexa * down;
    Hexa * right_up;
    Hexa * right_down;
    Hexa * left_up;
    Hexa * left_down;

    int i, j;
    void setNeighbors();


protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();
};

#endif

#ifndef HEXA_H
#define HEXA_H

#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include "agent.h"
#include "QChar"
#include "play_page.h"
#include "vector"

class Agent;

class Hexa : public QLabel
{
    Q_OBJECT

public:
    explicit Hexa(int row, int col, QWidget *parent, play_page * page);
    ~Hexa();

    void Set_type(char input_type);
    void Render(char ch);

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
    Hexa * get_member_of_neighbors(int);
    void setNeighbors();
    void printStatus();

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
    //Hexa * neighbors[6] = {up, down, right_up, right_down, left_up, left_down};
    vector<Hexa *> neighbors;

    int i, j;

    int size = 90;



protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();
};

#endif

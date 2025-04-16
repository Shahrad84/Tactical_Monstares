// hexa.h
#ifndef HEXA_H
#define HEXA_H

#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QObject>
#include "agent.h"
#include "QChar"

class Agent;

class Hexa : public QLabel
{
    Q_OBJECT

public:
    explicit Hexa(int row, int col, QWidget *parent = nullptr);
    ~Hexa();

    void Set_type(char input_type);

    //void Determine_x_and_y(int row, int col);

    // You can add custom methods and signals/slots here

    int get_x_position();
    int get_y_position();
    Agent * located_agent = nullptr;
    char get_type();

private:
    int x_pos;
    int y_pos;
    char type;

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();  // Signal to emit when clicked
};

#endif // HEXA_H

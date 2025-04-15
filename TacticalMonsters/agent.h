#ifndef AGENT_H
#define AGENT_H

#pragma once

#include "hexa.h"
#include <QLabel>
#include <QMouseEvent>
#include <QObject>


class Hexa;  // Forward declaration

class Agent : public QLabel
{
    Q_OBJECT

public:
    explicit Agent(QWidget* parent = nullptr);
    void Move(Hexa* new_hexa);

    static Agent * clicked_agent;
    Hexa * located_hexa;

private:
    char type;

    int x_pos;
    int y_pos;

signals:
    void clicked();  // Signal to emit when clicked

protected:
    void mousePressEvent(QMouseEvent* event) override;
};


#endif // AGENT_H

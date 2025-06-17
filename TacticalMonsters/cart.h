#ifndef CART_H
#define CART_H

#include <QObject>
#include <QWidget>
#include "QString"
#include "QLabel"
#include "QMouseEvent"
#include <QLabel>
#include <QMouseEvent>
#include "string"
using std::string;

class cart : public QLabel
{
    Q_OBJECT
public:
    cart(QLabel *inputQLabel, char inputOwnership, QWidget *parent = nullptr);
    bool get_isSelected();

    string get_subAgentType();
    string get_subAgentName();

signals:
    void clicked();

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    char ownership;
    QLabel * qlabel;
    bool isSelected;

    string subAgentType;
    string subAgentName;
    void parseText();

};



#endif // CART_H


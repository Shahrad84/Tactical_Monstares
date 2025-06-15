#ifndef CART_H
#define CART_H

#include <QObject>
#include <QWidget>
#include "QString"
#include "QLabel"
#include "QMouseEvent"
#include <QLabel>
#include <QMouseEvent>

class cart : public QLabel
{
    Q_OBJECT
public:
    cart(QLabel *inputQLabel, char inputOwnership, QWidget *parent = nullptr);
    bool get_isSelected();

signals:
    void clicked();

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    char ownership;
    QLabel * qlabel;
    bool isSelected;

};



#endif // CART_H


#ifndef POWERDIALOG_H
#define POWERDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <vector>
#include "gamelogic.h"

class PowerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PowerDialog(Player* player, QWidget *parent = nullptr);
    ~PowerDialog();

private slots:
    void usePowerup(int index);

private:
    Player* playerRef;
    std::vector<QPushButton*> useButtons;

    void setupUI();
};

#endif // POWERDIALOG_H

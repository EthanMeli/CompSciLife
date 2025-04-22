#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tiles.h"
#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupBoard();

private:
    Ui::MainWindow *ui;

    // Tile settings
    int tileSize = 50;
    int rows = 9;
    int cols = 9;

    // Board setup
    QVector<QVector<Tile*>> boardGrid;
};
#endif // MAINWINDOW_H

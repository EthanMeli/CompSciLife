#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tiles.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup board space
    setupBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupBoard() {
    // Graphics Scene Initialization
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Resize boardGrid to match rows and cols
    boardGrid.resize(rows);
    for (int i = 0; i < rows; i++) {
        boardGrid[i].resize(cols);
    }

    // Create a grid of tiles
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            boardGrid[row][col] = new EmptyTile();
        }
    }

    // Setup game specific tiles
    boardGrid[0][2] = new MoveForwardTile();
    boardGrid[0][4] = new PowerupTile();
    boardGrid[0][8] = new MoneyTile();
    boardGrid[1][8] = new MoveBackwardTile();
    boardGrid[2][6] = new LifeEventTile();
    boardGrid[2][5] = new MoveForwardTile();
    boardGrid[2][4] = new MoveBackwardTile();
    boardGrid[2][1] = new PowerupTile();

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            QGraphicsRectItem *tile = scene->addRect(col * tileSize, row * tileSize, tileSize, tileSize);
            if (row % 2 == 1) {
                if (boardGrid[row][col]->getColor() == Qt::white) {
                    // Setting empty tiles for snaking pattern
                    if ((row == 1 || row == 5) && col == 8) {
                        tile->setBrush(boardGrid[row][col]->getColor());
                    }
                    else if ((row == 3 || row == 7) && col == 0) {
                        tile->setBrush(boardGrid[row][col]->getColor());
                    }
                    else {
                        tile->setBrush(Qt::darkGray); // Non-player tiles
                    }
                }
                else {
                    tile->setBrush(boardGrid[row][col]->getColor());
                }
            }
            else {
                tile->setBrush(boardGrid[row][col]->getColor());
            }
            tile->setPen(QPen(Qt::black));
        }
    }
}

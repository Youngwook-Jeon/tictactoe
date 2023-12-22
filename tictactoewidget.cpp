#include "tictactoewidget.h"

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent)
{
    createBoard();
}

TicTacToeWidget::~TicTacToeWidget() {}

void TicTacToeWidget::createBoard()
{
    QGridLayout* grid = new QGridLayout(this);
    for (int row = 0; row < MetaData::ROWS; row++) {
        for (int column = 0; column < MetaData::COLUMNS; column++) {
            QPushButton* button = new QPushButton(this);
            button->setText(" ");
            button->setMinimumHeight(50);
            button->setMinimumWidth(50);
            grid->addWidget(button, row, column);
            board.append(button);
        }
    }
}

#include "tictactoewidget.h"
#include <QDebug>

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent)
{
    player = Player::Player1;
    createBoard();
}

TicTacToeWidget::~TicTacToeWidget() {}

void TicTacToeWidget::resetBoard()
{
    for (int i = 0; i < MetaData::ROWS * MetaData::COLUMNS; i++) {
        board.at(i)->setText(MetaData::SPACE_CHAR);
    }
}

void TicTacToeWidget::setCurrentPlayer(Player p)
{
    player = p;
}

Player TicTacToeWidget::getPlayer() const
{
    return player;
}

void TicTacToeWidget::handleClicksOnBoard(int buttonIndex)
{
    if (buttonIndex < 0 || buttonIndex >= board.size()) return;

    QPushButton* button = board.at(buttonIndex);
    button->setFont(QFont("Tahoma", 12, QFont::Bold));

    if (button->text() != MetaData::SPACE_CHAR) return;

    QString symbol;

    if (player == Player::Player1) {
        symbol = "X";
        button->setText(symbol);
        button->setStyleSheet("QPushButton{color: blue; background: lightyellow;}");
        button->setDisabled(true);
        setCurrentPlayer(Player::Player2);
    } else if (player == Player::Player2) {
        symbol = "O";
        button->setText(symbol);
        button->setStyleSheet("QPushButton{color: red; background: lightgreen;}");
        button->setDisabled(true);
        setCurrentPlayer(Player::Player1);
    }

    Winner winner = determineWinner(symbol, buttonIndex);
    if (winner == Winner::NoWinnerYet) {

    }
    else {
        if (winner == Winner::player1) qDebug() << "Player 1 wins";
    }
}

void TicTacToeWidget::createBoard()
{
    QGridLayout* grid = new QGridLayout(this);
    QSignalMapper* mapper = new QSignalMapper();
    for (int row = 0; row < MetaData::ROWS; row++) {
        for (int column = 0; column < MetaData::COLUMNS; column++) {
            QPushButton* button = new QPushButton(this);
            button->setText(MetaData::SPACE_CHAR);
            button->setMinimumHeight(50);
            button->setMinimumWidth(50);
            grid->addWidget(button, row, column);
            mapper->setMapping(button, board.size());
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
            connect(mapper, SIGNAL(mappedInt(int)), this, SLOT(handleClicksOnBoard(int)));
            board.append(button);
        }
    }
}

Winner TicTacToeWidget::determineWinner(const QString& symbol, int position)
{
    int rowNum = position / MetaData::COLUMNS;
    int colNum = position % MetaData::COLUMNS;
    int counter = 0;

    // horizontal checking
    int newCol = colNum;
    bool isValidSecondCheck = true;
    while (++newCol < MetaData::COLUMNS) {
        int newPos = rowNum * MetaData::COLUMNS + newCol;
        QPushButton* button = board.at(newPos);
        if (button->text() != symbol) {
            isValidSecondCheck = false;
            break;
        }
        else {
            counter++;
        }
    }

    newCol = colNum;
    while (isValidSecondCheck && --newCol >= 0) {
        int newPos = rowNum * MetaData::COLUMNS + newCol;
        QPushButton* button = board.at(newPos);
        if (button->text() != symbol) {
            break;
        }
        else {
            counter++;
        }
    }

    if (++counter == MetaData::COLUMNS) {
        if (symbol == "X") {
            return Winner::player1;
        }
        else if (symbol == "O") {
            return Winner::player2;
        }
    }

    return Winner::NoWinnerYet;
}

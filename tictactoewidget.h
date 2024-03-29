#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

struct MetaData {
    static constexpr int ROWS_COLUMNS = 3;
    static constexpr const char* SPACE_CHAR = " ";
    static constexpr const char* PLAYER1_SYMBOL = "X";
    static constexpr const char* PLAYER2_SYMBOL = "O";
};

enum Player {
    Player1, Player2
};

enum Winner {
    player1, player2, Draw, NoWinnerYet
};

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    TicTacToeWidget(QWidget *parent = nullptr);
    ~TicTacToeWidget();
    void resetBoard();
    void setCurrentPlayer(Player p);
    Player getPlayer() const;

private slots:
    void handleClicksOnBoard(int);

private:
    void createBoard();

    Winner determineWinner(const QString&, int);

private:
    QList<QPushButton*> board;
    Player player;
};
#endif // TICTACTOEWIDGET_H

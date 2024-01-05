#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>

struct MetaData {
    static constexpr int ROWS = 3;
    static constexpr int COLUMNS = 3;
    static constexpr const char* SPACE_CHAR = " ";
};

enum Player {
    Player1, Player2
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

private:
    QList<QPushButton*> board;
    Player player;
};
#endif // TICTACTOEWIDGET_H

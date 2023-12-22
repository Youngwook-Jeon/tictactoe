#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QGridLayout>

struct MetaData {
    static constexpr int ROWS = 3;
    static constexpr int COLUMNS = 3;
};

class TicTacToeWidget : public QWidget
{
    Q_OBJECT

public:
    TicTacToeWidget(QWidget *parent = nullptr);
    ~TicTacToeWidget();

private:
    void createBoard();

private:
    QList<QPushButton*> board;
};
#endif // TICTACTOEWIDGET_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QTableWidget>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <QFileDialog>
#include <QSqlDatabase>
#include <qpushbutton.h>
#include "Common/global.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();
	~MainWindow();

    void notCompletefiter();
private slots:
    void addTask();
    void cellSelected(int nRow, int nCol);

public slots:
    void filter();
    void checkboxChecked(int checked, int row);

signals:
    void shake();           // 窗口抖动给zhiban界面

private:
    Ui::MainWindow *ui;
    void createFilters(QHBoxLayout *layout);
    void initializeTable();
    // void updateTable(vector<string*> data);
    // int cmp_struct_char(const todoStruct* p1, const todoStruct* p2);
    void updateTable(QVector<todoStruct> data);
    string path;
    QPushButton* addtask;
    QRadioButton *rb_all;
    QRadioButton *rb_overdue;
    QRadioButton *rb_today;
    QRadioButton *rb_thisweek;
    QCheckBox *cb_completed;
    QTableWidget *table;
    QStringList tableHeader;
    QMenu *fileMenu;
    QAction *addTaskAct;
    QSqlDatabase connection;
};

#endif // MAINWINDOW_H

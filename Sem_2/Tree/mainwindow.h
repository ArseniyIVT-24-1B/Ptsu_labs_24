#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"
#include "treeglwidget.h"

class QPushButton;
class QLabel;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCreateTree();
    void onConvertTree();
    void onFindMax();

private:
    Tree tree;
    TreeGLWidget* glWidget;
    QLabel* maxLabel;
};

#endif // MAINWINDOW_H

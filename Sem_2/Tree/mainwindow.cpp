#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), glWidget(new TreeGLWidget(this)) {

    auto* central = new QWidget(this);
    auto* layout = new QVBoxLayout(central);

    auto* buttonLayout = new QHBoxLayout();
    auto* createBtn = new QPushButton("Создать дерево");
    auto* convertBtn = new QPushButton("В BST");
    auto* maxBtn = new QPushButton("Максимум");
    maxLabel = new QLabel("Макс.: ");

    createBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    convertBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    maxLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    connect(createBtn, &QPushButton::clicked, this, &MainWindow::onCreateTree);
    connect(convertBtn, &QPushButton::clicked, this, &MainWindow::onConvertTree);
    connect(maxBtn, &QPushButton::clicked, this, &MainWindow::onFindMax);

    buttonLayout->addWidget(createBtn);
    buttonLayout->addWidget(convertBtn);
    buttonLayout->addWidget(maxBtn);
    buttonLayout->addWidget(maxLabel);

    layout->addLayout(buttonLayout);
    layout->addWidget(glWidget, 1);

    setCentralWidget(central);
    setWindowTitle("Binary Tree Visualizer");
    resize(800, 600);
}

MainWindow::~MainWindow() {}

void MainWindow::onCreateTree() {
    bool ok;
    int count = QInputDialog::getInt(this, "Количество узлов", "Введите количество:", 7, 1, 100, 1, &ok);
    if (ok) {
        tree.generateBalancedTree(count);
        glWidget->setTree(tree.getRoot());
    }
}

void MainWindow::onConvertTree() {
    tree.convertToBST();
    glWidget->setTree(tree.getRoot());
}

void MainWindow::onFindMax() {
    double maxVal = tree.findMax();
    maxLabel->setText(QString("Макс.: %1").arg(maxVal));
}

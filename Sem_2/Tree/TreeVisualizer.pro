QT += core gui widgets opengl openglwidgets

LIBS += -lopengl32

TARGET = TreeVisualizer
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           tree.cpp \
           treeglwidget.cpp

HEADERS += mainwindow.h \
           tree.h \
           treeglwidget.h

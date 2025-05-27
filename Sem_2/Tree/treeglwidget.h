#ifndef TREEGLWIDGET_H
#define TREEGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "tree.h"

class TreeGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    TreeGLWidget(QWidget* parent = nullptr);
    void setTree(TreeNode* root);

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    TreeNode* root;
    void drawNode(QPainter& painter, TreeNode* node, float x, float y, float dx, int depth);

    void adjustSizeToTree(TreeNode* rootNode);
    int getTreeDepth(TreeNode* node) const;
    int getNodeCount(TreeNode* node) const;
};

#endif // TREEGLWIDGET_H

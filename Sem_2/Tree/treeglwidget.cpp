#include "treeglwidget.h"
#include <QPainter>
#include <cmath>

TreeGLWidget::TreeGLWidget(QWidget* parent)
    : QOpenGLWidget(parent), root(nullptr) {}

void TreeGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1, 1, 1, 1);
}

void TreeGLWidget::paintGL() {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);
    painter.setPen(Qt::black);

    if (root)
        drawNode(painter, root, width() / 2, 30, width() / 4, 0);
}

void TreeGLWidget::drawNode(QPainter& painter, TreeNode* node, float x, float y, float dx, int depth) {
    if (!node) return;

    const float radius = 15.0f;
    QString val = QString::number(node->value, 'f', 1);
    QRectF circleRect(x - radius, y - radius, 2 * radius, 2 * radius);

    painter.drawEllipse(circleRect);
    painter.drawText(circleRect, Qt::AlignCenter, val);

    if (node->left) {
        float childX = x - dx;
        float childY = y + 60;

        float vx = childX - x;
        float vy = childY - y;
        float len = std::sqrt(vx * vx + vy * vy);
        float offsetX = radius * vx / len;
        float offsetY = radius * vy / len;

        painter.drawLine(x + offsetX, y + offsetY, childX - offsetX, childY - offsetY);
        drawNode(painter, node->left, childX, childY, dx / 1.8f, depth + 1);
    }

    if (node->right) {
        float childX = x + dx;
        float childY = y + 60;

        float vx = childX - x;
        float vy = childY - y;
        float len = std::sqrt(vx * vx + vy * vy);
        float offsetX = radius * vx / len;
        float offsetY = radius * vy / len;

        painter.drawLine(x + offsetX, y + offsetY, childX - offsetX, childY - offsetY);
        drawNode(painter, node->right, childX, childY, dx / 1.8f, depth + 1);
    }
}

void TreeGLWidget::setTree(TreeNode* rootNode) {
    root = rootNode;
    adjustSizeToTree(root);
    update();
}


void TreeGLWidget::adjustSizeToTree(TreeNode* rootNode) {
    int depth = getTreeDepth(rootNode);
    int count = getNodeCount(rootNode);

    int width = std::max(800, static_cast<int>(count * 60));
    int height = std::max(600, depth * 80);

    setMinimumSize(width, height);
}

int TreeGLWidget::getTreeDepth(TreeNode* node) const {
    if (!node) return 0;
    return 1 + std::max(getTreeDepth(node->left), getTreeDepth(node->right));
}

int TreeGLWidget::getNodeCount(TreeNode* node) const {
    if (!node) return 0;
    return 1 + getNodeCount(node->left) + getNodeCount(node->right);
}

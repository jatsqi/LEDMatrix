#ifndef LEDWIDGET_H
#define LEDWIDGET_H

#include <QWidget>
#include <QSet>
#include <QPair>
#include <QHash>

class QPaintEvent;
class QPainter;

class LEDWidget : public QWidget
{
    Q_OBJECT

public:

    explicit LEDWidget(unsigned int cols, unsigned int rows, QWidget* parent = nullptr);

    unsigned int getColumnCount() const;
    unsigned int getRowCount() const;

public slots:

    void clear();
    void show(unsigned int col, unsigned int row);
    void hide(unsigned int col, unsigned int row);

protected:

    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:

    void drawGrid(QPainter &painter);
    void drawCells(QPainter &painter);

private:

    QSet<QPair<unsigned int, unsigned int>> visibleCells_;
    unsigned int rows_;
    unsigned int cols_;

};

inline uint qHash(const QPair<unsigned int, unsigned int> &key, uint seed)
{
    return qHash(key.first, seed) ^ qHash(key.second);
}

#endif // LEDWIDGET_H

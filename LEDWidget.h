#ifndef LEDWIDGET_H
#define LEDWIDGET_H

#include <QWidget>
#include <QMap>
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
    void showCell(unsigned int col, unsigned int row, QColor color);
    void hideCell(unsigned int col, unsigned int row, QColor color);

protected:

    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:

    void drawGrid(QPainter &painter);
    void drawCells(QPainter &painter);

private:

    QMap<QPair<unsigned int, unsigned int>, QColor> visibleCells_;
    unsigned int rows_, cols_;
    float cellWidth_, cellHeight_;

};

inline uint qHash(const QPair<unsigned int, unsigned int> &key, uint seed)
{
    return qHash(key.first, seed) ^ qHash(key.second);
}

#endif // LEDWIDGET_H

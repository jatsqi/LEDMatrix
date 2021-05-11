#include "LEDWidget.h"

#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>

LEDWidget::LEDWidget(unsigned int cols, unsigned int rows, QWidget* parent)
    : QWidget(parent), rows_(rows), cols_(cols)
{
    show(1, 1);
}

unsigned int LEDWidget::getColumnCount() const
{
    return cols_;
}

unsigned int LEDWidget::getRowCount() const
{
    return rows_;
}

void LEDWidget::clear()
{
    visibleCells_.clear();
}

void LEDWidget::show(unsigned int col, unsigned int row)
{
    visibleCells_.insert(qMakePair(col, row));
}

void LEDWidget::hide(unsigned int col, unsigned int row)
{
    visibleCells_.remove(qMakePair(col, row));
}

void LEDWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    drawGrid(painter);
    drawCells(painter);
}

void LEDWidget::resizeEvent(QResizeEvent *event)
{
    event->accept();

    if(event->size().width() > event->size().height()) {
        QWidget::resize(event->size().height(), event->size().height());
    } else {
        QWidget::resize(event->size().width(), event->size().width());
    }
}

void LEDWidget::drawGrid(QPainter &painter)
{
    const float cellWidth = width() / cols_;
    const float cellHeight = height() / rows_;
    float currentYVertical = 0;
    float currentXHorizontal = 0;
    unsigned int step = 0;

    do
    {
        currentYVertical = step * cellHeight;
        currentXHorizontal = step * cellWidth;

        if(currentXHorizontal < width())
        {
            painter.drawLine(QLineF(currentXHorizontal, 0, currentXHorizontal, height()));
        }

        if(currentYVertical < height())
        {
            painter.drawLine(QLineF(0, currentYVertical, width(), currentYVertical));
        }

        ++step;
    } while(currentXHorizontal < width() || currentYVertical < height());
}

void LEDWidget::drawCells(QPainter &painter)
{
    const float cellWidth = width() / cols_;
    const float cellHeight = height() / rows_;

    for(const auto& cell : visibleCells_)
    {
        float x = cellWidth * cell.first;
        float y = cellHeight * cell.second;

        painter.fillRect(QRectF(x, y, cellWidth, cellHeight), Qt::black);
    }
}
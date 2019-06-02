#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QChartGlobal>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QGridLayout>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QValueAxis>

#include <vector>
#include <cstdint>

#include "constants.h"
#include "func.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Graphic;
}

class Graphic : public QWidget
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = nullptr);
    ~Graphic();
    QDoubleSpinBox* coeffs_[N_coeffs];
private slots:
    void plot_parabola();


private:
    QChart* m_chart;
    QChartView* m_chartView;
    QGridLayout* m_mainLayout;
    QLabel* labels_[N_coeffs];

    QPushButton* start_button;

    QLineSeries* data;
};

#endif // GRAPHIC_H

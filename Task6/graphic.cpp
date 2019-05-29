
#include "graphic.h"
#include "func.h"

QT_CHARTS_USE_NAMESPACE

Graphic::Graphic(QWidget *parent) :
    QWidget(parent)
{
    m_chart = new QChart();
    m_chart->legend()->setVisible(true);
    m_chart->createDefaultAxes();
    m_chart->legend()->setAlignment(Qt::AlignBottom);
    m_chart->setTheme(QChart::ChartThemeBlueIcy);

    data = nullptr;

    m_chartView = new QChartView(m_chart, this);

    //m_chartView1 = new QChartView(m_chart, this);

    m_chartView->setRenderHint(QPainter::Antialiasing);
    //m_chartView1->setRenderHint(QPainter::Antialiasing);
    QString tmp_array[N_coeffs] = {tr("x_min"), tr("x_max"), tr("N"), tr("t"), tr("gamma")};
    for (size_t i = 0; i < N_coeffs; ++i) {

        labels_[i] = new QLabel(this);
        coeffs_[i] = new QDoubleSpinBox(this);
        if (i == 3){
            labels_[i]->setText(tmp_array[i]
                                +QString("["+QString::number(0.0)
                                         +"; "+QString::number(Coeffs_range[i])+"]"));
            coeffs_[i]->setRange(0.0, Coeffs_range[i]);
            coeffs_[i]->setValue(0.0);
        } else if (i ==4){
            labels_[i]->setText(tmp_array[i]
                                            +QString("["+QString::number(1.0)
                                                     +"; "+QString::number(Coeffs_range[i])+"]"));
            coeffs_[i]->setRange(1.0, Coeffs_range[i]);
            coeffs_[i]->setValue(1.0);
        } else{
            labels_[i]->setText(tmp_array[i]
                                +QString("[-"+QString::number(Coeffs_range[i])
                                         +"; "+QString::number(Coeffs_range[i])+"]"));
            coeffs_[i]->setRange(-1.0*Coeffs_range[i], Coeffs_range[i]);
            coeffs_[i]->setValue(0.0);
        }

    }
    QPushButton* start_button = new QPushButton(this);
    start_button->setText(tr("Calculate"));
    connect(start_button, SIGNAL(clicked()), this, SLOT(plot_parabola()));

    m_mainLayout = new QGridLayout(this);

    m_mainLayout->addWidget(m_chartView, 0, 0, 1, int32_t(2*N_coeffs));
   // m_mainLayout->addWidget(m_chartView, 0, 1, 1, int32_t(2*N_coeffs));

    for(size_t i = 0; i < N_coeffs; ++i) {
        m_mainLayout->addWidget(labels_[i], 1, int32_t(2*i));
        m_mainLayout->addWidget(coeffs_[i], 1, int32_t(2*i) + 1);
    }
    m_mainLayout->addWidget(start_button, 2, N_coeffs-1, 1, 2);

}
void Graphic::plot_parabola()
{
    if (data != nullptr) {
        delete data;
        data = nullptr;
    }
    double x_min = coeffs_[0]->value();
    double x_max = coeffs_[1]->value();
    double N = coeffs_[2]->value();
    double t = coeffs_[3]->value();
    double gamma = coeffs_[4]->value();
    data = generate_data(x_min, x_max, N);
    m_chart->addSeries(data);
    m_chart->createDefaultAxes();
    m_chart->axes(Qt::Horizontal).first()->setRange(-1.0 * X_range, X_range);
    m_chart->axes(Qt::Vertical).first()->setRange(-1.0 * Y_range, Y_range);
}

Graphic::~Graphic()
{
}

#include "func.h"


QLineSeries* generate_data(double a, double b, double c)
{

    double x_min = -1.0 * X_range;
    double x_max = X_range;

    double h = (x_max - x_min) / (N_points - 1);
    QList<QPointF> data;
    for(int32_t i = 0; i < N_points; ++i) {
        double x = x_min + i * h;
        double y = a*x*x + b*x + c;
        data.append(QPointF(x, y));
    }
    QLineSeries* result = new QLineSeries;
    result->setName(QString(QString::number(a)+" * x^2 + "
                           +QString::number(b)+" * x + "
                           +QString::number(c)));
    result->append(data);
    return result;
}

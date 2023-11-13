#include "triangle.h"

Triangle::Triangle(QObject *parent)
    : QObject{parent}
{}

bool Triangle::CalculatePerimeterAreaAndAngles()
{
    if (A == 0 || B == 0 || C == 0) {
        return false;
    }

    // Calculate the perimeter
    U = A + B + C;

    // Calculate the area
    {
        // Calculate the half of the perimeter
        double s = U / 2;

        // Use Heron'sche formula to calculate the area
        Area = sqrt(s * (s - A) * (s - B) * (s - C));
    }

    Alpha = acos(((-B * -B) + (C * C) - (A * A)) / (2 * B * C)) * 180 / M_PI;
    Beta = acos(((-A * -A) + (C * C) - (B * B)) / (2 * A * C)) * 180 / M_PI;

    if (Gamma == 0) {
        Gamma = 180 - Alpha - Beta;
    }

    return U != 0 && Area != 0 && Alpha != 0 && Beta != 0 && Gamma != 0;
}

void Triangle::Calculate()
{
    Calculate_();
    Calculate_();

    // If unsuccessful, run 1 last time
    if (!CalculatePerimeterAreaAndAngles()) {
        Calculate_();
        CalculatePerimeterAreaAndAngles();
    }
}

double Triangle::CosineLaw(double a, double b, double gamma)
{
    return sqrt((a * a) + (b * b) - (2 * a * b * cos(gamma * M_PI / 180)));
}

double Triangle::SineLaw1Angle2Sites(double c, double gamma, double a)
{
    double alpha = a * sin(gamma * M_PI / 180.0) / c;
    return asin(alpha) * 180.0 / M_PI;
}

double Triangle::SineLaw2Angles1Site(double a, double alpha, double beta)
{
    return a * sin(beta * M_PI / 180.0) / sin(alpha * M_PI / 180.0);
}

bool Triangle::Calculate_()
{
    if (Beta != 0 && Gamma != 0 && Alpha == 0) {
        Alpha = 180.0 - Beta - Gamma;
    } else if (Alpha != 0 && Gamma != 0 && Beta == 0) {
        Beta = 180.0 - Alpha - Gamma;
    } else if (Alpha != 0 && Beta != 0 && Gamma == 0) {
        Gamma = 180.0 - Alpha - Beta;
    }

    CalculatePerimeterAreaAndAngles();

    if (Alpha != 0 && B != 0 && C != 0 && A == 0) {
        // Calculate site A
        A = CosineLaw(B, C, Alpha);
    }
    if (Beta != 0 && A != 0 && C != 0 && B == 0) {
        // Calculate site B
        B = CosineLaw(A, C, Beta);
    }
    // A, B and Gamma given
    if (Gamma != 0 && A != 0 && B != 0 && C == 0) {
        // Calculate site C
        C = CosineLaw(A, B, Gamma);
    }

    if (B != 0 && Beta != 0 && Alpha != 0 && A == 0) {
        A = SineLaw2Angles1Site(B, Beta, Alpha);
    }
    if (C != 0 && Gamma != 0 && Alpha != 0 && A == 0) {
        A = SineLaw2Angles1Site(C, Gamma, Alpha);
    }
    if (A != 0 && Alpha != 0 && Beta != 0 && B == 0) {
        B = SineLaw2Angles1Site(A, Alpha, Beta);
    }
    if (C != 0 && Gamma != 0 && Beta != 0 && B == 0) {
        B = SineLaw2Angles1Site(C, Gamma, Beta);
    }
    if (A != 0 && Alpha != 0 && Gamma != 0 && C == 0) {
        C = SineLaw2Angles1Site(A, Alpha, Gamma);
    }
    if (B != 0 && Beta != 0 && Gamma != 0 && C == 0) {
        C = SineLaw2Angles1Site(B, Beta, Gamma);
    }

    if (A != 0 && B != 0 && Beta != 0 && Alpha == 0) {
        Alpha = SineLaw1Angle2Sites(B, Beta, A);
    }
    if (A != 0 && C != 0 && Gamma != 0 && Alpha == 0) {
        Alpha = SineLaw1Angle2Sites(C, Gamma, A);
    }
    if (B != 0 && A != 0 && Alpha != 0 && Beta == 0) {
        Beta = SineLaw1Angle2Sites(A, Alpha, B);
    }
    if (B != 0 && C != 0 && Gamma != 0 && Beta == 0) {
        Beta = SineLaw1Angle2Sites(C, Gamma, B);
    }
    if (C != 0 && A != 0 && Alpha != 0 && Gamma == 0) {
        Gamma = SineLaw1Angle2Sites(A, Alpha, C);
    }
    if (C != 0 && B != 0 && Beta != 0 && Gamma == 0) {
        Gamma = SineLaw1Angle2Sites(B, Beta, C);
    }

    return true;
}

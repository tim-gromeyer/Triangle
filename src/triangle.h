#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QQmlEngine>

#define _USE_MATH_DEFINES
#include <math.h>

class Triangle : public QObject

{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(double SideA MEMBER A NOTIFY SideAChanged)
    Q_PROPERTY(double SideB MEMBER B NOTIFY SideBChanged)
    Q_PROPERTY(double SideC MEMBER C NOTIFY SideCChanged)
    Q_PROPERTY(double Alpha MEMBER Alpha NOTIFY AlphaChanged)
    Q_PROPERTY(double Beta MEMBER Beta NOTIFY BetaChanged)
    Q_PROPERTY(double Gamma MEMBER Gamma NOTIFY GammaChanged)
    Q_PROPERTY(double Area MEMBER Area NOTIFY AreaChanged)
    Q_PROPERTY(double Perimeter MEMBER U NOTIFY PerimeterChanged)

public:
    explicit Triangle(QObject *parent = nullptr);

    /// <summary>
    /// Gets or sets length of A
    /// </summary>
    double A = 0;

    /// <summary>
    /// Gets or sets alpha (in degrees)
    /// </summary>
    double Alpha = 0;

    /// <summary>
    /// Gets or sets the area of the triangle
    /// </summary>
    /// <value>A</value>
    double Area = 0;

    /// <summary>
    /// Gets or sets length of B
    /// </summary>
    double B = 0;

    /// <summary>
    /// Gets or sets beta (in degrees)
    /// </summary>
    double Beta = 0;

    /// <summary>
    /// Gets or sets length of C
    /// </summary>
    double C = 0;

    /// <summary>
    /// Gets or sets gamma (in degrees)
    /// </summary>
    double Gamma = 0;

    /// <summary>
    /// Gets or sets the perimeter
    /// </summary>
    /// <value>The u.</value>
    double U = 0;

    /// <summary>
    /// Calculates this instance.
    /// </summary>
    Q_INVOKABLE void Calculate();

Q_SIGNALS:
    void SideAChanged();
    void SideBChanged();
    void SideCChanged();
    void AlphaChanged();
    void BetaChanged();
    void GammaChanged();
    void AreaChanged();
    void PerimeterChanged();

private:
    static double CosineLaw(double a, double b, double gamma);

    /// <summary>
    /// Returns Alpha. Calculates the following: (a * sin(gamma)) / c
    /// </summary>
    /// <param name="c">Site c</param>
    /// <param name="gamma">Gamma in degree</param>
    /// <param name="a">Site a</param>
    /// <returns>Alpha in degrees</returns>
    static double SineLaw1Angle2Sites(double c, double gamma, double a);

    /// <summary>
    /// Returns B. Calculates the following: (a * sin(beta)) / sin(alpha)
    /// </summary>
    /// <param name="a">Site a</param>
    /// <param name="beta">beta in degree</param>
    /// <param name="alpha">alpha in degree</param>
    /// <returns>Length of side b</returns>
    static double SineLaw2Angles1Site(double a, double alpha, double beta);

    bool Calculate_();

    bool CalculatePerimeterAreaAndAngles();
};

#endif // TRIANGLE_H

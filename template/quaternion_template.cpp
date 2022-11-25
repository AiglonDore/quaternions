/**
 * @file quaternion.cpp
 * @author Thomas Roiseux (thomas.roiseux@outlook.com)
 * @brief Implements {@link quaternion.h}.
 * @version 0.1
 * @date 2022-11-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "quaternion_template.h"
#include <exception>

ensiie::Quaternion::Quaternion() : u(0), v(0), w(0), t(0)
{
}

ensiie::Quaternion::Quaternion(double x) : t(x), u(0), v(0), w(0)
{
}

ensiie::Quaternion::Quaternion(double x, double y) : t(x), u(y), v(0), w(0)
{
}

ensiie::Quaternion::Quaternion(double x, double y, double z, double w) : t(x), u(y), v(z), w(w)
{
}

ensiie::Quaternion::~Quaternion()
{
}

double ensiie::Quaternion::norm() const 
{
    return std::sqrt(t * t + u * u + v * v + w * w);
}

ensiie::Quaternion& ensiie::Quaternion::operator+=(const Quaternion& q)
{
    t += q.t;
    u += q.u;
    v += q.v;
    w += q.w;
    return *this;
}

ensiie::Quaternion& ensiie::Quaternion::operator-=(const Quaternion& q)
{
    t -= q.t;
    u -= q.u;
    v -= q.v;
    w -= q.w;
    return *this;
}

ensiie::Quaternion& ensiie::Quaternion::operator*=(const Quaternion& q)
{
    double t1 = t;
    double u1 = u;
    double v1 = v;
    double w1 = w;
    t = t1 * q.t - u1 * q.u - v1 * q.v - w1 * q.w;
    u = t1 * q.u + u1 * q.t + v1 * q.w - w1 * q.v;
    v = t1 * q.v - u1 * q.w + v1 * q.t + w1 * q.u;
    w = t1 * q.w + u1 * q.v - v1 * q.u + w1 * q.t;
    return *this;
}

ensiie::Quaternion& ensiie::Quaternion::operator/=(const Quaternion& q)
{
    if (q.norm() <= 1e-15)
    {
        throw std::invalid_argument("Division by zero");
    }
    double t1 = t;
    double u1 = u;
    double v1 = v;
    double w1 = w;
    t = (t1 * q.t + u1 * q.u + v1 * q.v + w1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    u = (u1 * q.t - t1 * q.u - w1 * q.v + v1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    v = (v1 * q.t + w1 * q.u - t1 * q.v - u1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    w = (w1 * q.t - v1 * q.u + u1 * q.v - t1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    return *this;
}

ensiie::Quaternion& ensiie::Quaternion::operator*=(double x)
{
    t *= x;
    u *= x;
    v *= x;
    w *= x;
    return *this;
}

ensiie::Quaternion& ensiie::Quaternion::operator/=(double x)
{
    if (x <= 1e-15)
    {
        throw std::invalid_argument("Division by zero");
    }
    t /= x;
    u /= x;
    v /= x;
    w /= x;
    return *this;
}

std::ostream& ensiie::operator<<(std::ostream& os, const Quaternion& q)
{
    os << q.t << " + " << q.u << "i + " << q.v << "j + " << q.w << "k";
    return os;
}

ensiie::Quaternion ensiie::operator+(const Quaternion& q1, const Quaternion& q2)
{
    ensiie::Quaternion copy(q1);
    copy += q2;
    return copy;
}

ensiie::Quaternion ensiie::operator-(const Quaternion& q1, const Quaternion& q2)
{
    ensiie::Quaternion copy(q1);
    copy -= q2;
    return copy;
}

ensiie::Quaternion ensiie::operator*(const Quaternion& q1, const Quaternion& q2)
{
    ensiie::Quaternion copy(q1);
    copy *= q2;
    return copy;
}

ensiie::Quaternion ensiie::operator/(const Quaternion& q1, const Quaternion& q2)
{
    ensiie::Quaternion copy(q1);
    copy /= q2;
    return copy;
}

ensiie::Quaternion ensiie::operator*(const Quaternion& q, double x)
{
    ensiie::Quaternion copy(q);
    copy *= x;
    return copy;
}

ensiie::Quaternion ensiie::operator*(double x, const Quaternion& q)
{
    ensiie::Quaternion copy(q);
    copy *= x;
    return copy;
}

ensiie::Quaternion ensiie::operator/(const Quaternion& q, double x)
{
    ensiie::Quaternion copy(q);
    copy /= x;
    return copy;
}
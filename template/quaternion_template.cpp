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

template<class T>
ensiie::Quaternion<T>::Quaternion() : u(0), v(0), w(0), t(0)
{
}

template<class T>
ensiie::Quaternion<T>::Quaternion(T x) : t(x), u(0), v(0), w(0)
{
}

template<class T>
ensiie::Quaternion<T>::Quaternion(T x, T y) : t(x), u(y), v(0), w(0)
{
}

template<class T>
ensiie::Quaternion<T>::Quaternion(T x, T y, T z, T w) : t(x), u(y), v(z), w(w)
{
}

template<class T>
ensiie::Quaternion<T>::~Quaternion()
{
}

template<class T>
T ensiie::Quaternion<T>::norm() const 
{
    return std::sqrt(t * t + u * u + v * v + w * w);
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator+=(const Quaternion& q)
{
    t += q.t;
    u += q.u;
    v += q.v;
    w += q.w;
    return *this;
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator-=(const Quaternion& q)
{
    t -= q.t;
    u -= q.u;
    v -= q.v;
    w -= q.w;
    return *this;
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator*=(const Quaternion& q)
{
    T t1 = t;
    T u1 = u;
    T v1 = v;
    T w1 = w;
    t = t1 * q.t - u1 * q.u - v1 * q.v - w1 * q.w;
    u = t1 * q.u + u1 * q.t + v1 * q.w - w1 * q.v;
    v = t1 * q.v - u1 * q.w + v1 * q.t + w1 * q.u;
    w = t1 * q.w + u1 * q.v - v1 * q.u + w1 * q.t;
    return *this;
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator/=(const Quaternion& q)
{
    if (q.norm() <= 1e-15)
    {
        throw std::invalid_argument("Division by zero");
    }
    T t1 = t;
    T u1 = u;
    T v1 = v;
    T w1 = w;
    t = (t1 * q.t + u1 * q.u + v1 * q.v + w1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    u = (u1 * q.t - t1 * q.u - w1 * q.v + v1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    v = (v1 * q.t + w1 * q.u - t1 * q.v - u1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    w = (w1 * q.t - v1 * q.u + u1 * q.v - t1 * q.w) / (q.t * q.t + q.u * q.u + q.v * q.v + q.w * q.w);
    return *this;
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator*=(T x)
{
    t *= x;
    u *= x;
    v *= x;
    w *= x;
    return *this;
}

template<class T>
ensiie::Quaternion<T>& ensiie::Quaternion<T>::operator/=(T x)
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

template<typename T>
std::ostream& operator<<(std::ostream& os, const ensiie::Quaternion<T>& q)
{
    os << q.t << " + " << q.u << "i + " << q.v << "j + " << q.w << "k";
    return os;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator+(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    ensiie::Quaternion<T> copy(q1);
    copy += q2;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator-(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    ensiie::Quaternion<T> copy(q1);
    copy -= q2;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator*(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    ensiie::Quaternion<T> copy(q1);
    copy *= q2;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator/(const Quaternion<T>& q1, const Quaternion<T>& q2)
{
    ensiie::Quaternion<T> copy(q1);
    copy /= q2;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator*(const Quaternion<T>& q, T x)
{
    ensiie::Quaternion<T> copy(q);
    copy *= x;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator*(T x, const Quaternion<T>& q)
{
    ensiie::Quaternion<T> copy(q);
    copy *= x;
    return copy;
}

template<typename T>
ensiie::Quaternion<T> ensiie::operator/(const Quaternion<T>& q, T x)
{
    ensiie::Quaternion<T> copy(q);
    copy /= x;
    return copy;
}
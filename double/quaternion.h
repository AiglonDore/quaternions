/**
 * @file quaternion.h
 * @author Thomas Roiseux (thomas.roiseux@outlook.com)
 * @brief Provides a class for quaternions.
 * @version 0.1
 * @date 2022-11-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>
#include <ostream>

/**
 * @brief A namespace for the ENSIIE project.
 * 
 */
namespace ensiie
{
    /**
     * @brief A class for quaternions.
     * 
     */
    class Quaternion
    {
    private:
        double t, u, v, w;

    public:
        /**
         * @brief Construct a new Quaternion object, which is the null quaternion.
         *
         */
        Quaternion();
        /**
         * @brief Construct a new Quaternion object from a double.
         *
         * @param x Real number.
         */
        Quaternion(double x);
        /**
         * @brief Construct a new Quaternion object from a complex.
         *
         * @param x Real port a the complex.
         * @param y Imaginary part of the complex.
         */
        Quaternion(double x, double y);
        /**
         * @brief Construct a new Quaternion object from a quaternion.
         *
         * @param x x.
         * @param y y.
         * @param z z.
         * @param w w.
         */
        Quaternion(double x, double y, double z, double w);
        /**
         * @brief Destroy the Quaternion object.
         *
         */
        ~Quaternion();

        /**
         * @brief Get the real part of the quaternion.
         *
         * @return double Real part.
         */
        double getT() const { return t; };

        /**
         * @brief Get the u part of the quaternion.
         *
         * @return double u part.
         */
        double getU() const { return u; };

        /**
         * @brief Get the v part of the quaternion.
         *
         * @return double v part.
         */
        double getV() const { return v; };

        /**
         * @brief Get the w part of the quaternion.
         *
         * @return double w part.
         */
        double getW() const { return w; };

        /**
         * @brief Get the norm of the quaternion.
         * 
         * @return double 
         */
        double norm() const;

        /**
         * @brief Constructs an identity quaternion.
         * 
         * @return Quaternion 
         */
        static Quaternion identity() { return Quaternion(1, 0, 0, 0); };

        /**
         * @brief Gets the norm of the quaternion.
         * 
         * @param q Quaternion.
         * @return double Norm of q.
         */
        static double norm(const Quaternion& q) { return q.norm(); };


        /**
         * @brief Gets the conjugate of the quaternion.
         * 
         * @param q Quaternion.
         * @return Quaternion Conjugate of q.
         */
        Quaternion conjugate() const { return Quaternion(t, -u, -v, -w); };

        /**
         * @brief Gets the conjugate of the quaternion.
         * 
         * @param q Quaternion.
         * @return Quaternion Conjugate of q.
         */
        static Quaternion conjugate(const Quaternion& q) { return q.conjugate(); };

        /**
         * @brief Gets the inverse of the quaternion.
         * 
         * @param q Quaternion.
         * @return Quaternion Inverse of q.
         */
        Quaternion inverse() const { return conjugate() / norm(); };

        /**
         * @brief Gets the inverse of the quaternion.
         * @throws std::domain_error If the norm of the quaternion is 0.
         * @param q Quaternion.
         * @return Quaternion Inverse of q.
         */
        static Quaternion inverse(const Quaternion& q) { return q.inverse(); };

        /**
         * @brief Adds two quaternions.
         * 
         * @param q Other quaternion.
         * @return Quaternion& 
         */
        Quaternion& operator+=(const Quaternion& q);
        /**
         * @brief Subtracts two quaternions.
         * 
         * @param q Other quaternion.
         * @return Quaternion& 
         */
        Quaternion& operator-=(const Quaternion& q);
        /**
         * @brief Multiplies two quaternions.
         * 
         * @param q Other quaternion.
         * @return Quaternion& 
         */
        Quaternion& operator*=(const Quaternion& q);
        /**
         * @brief Divides two quaternions.
         * @throws std::exception if division by 0.
         * @param q Other quaternion.
         * @return Quaternion& 
         */
        Quaternion& operator/=(const Quaternion& q);

        /**
         * @brief Multiplies a quaternion by a double.
         * 
         * @param x Real number.
         * @return Quaternion& 
         */
        Quaternion& operator*=(double x);
        /**
         * @brief Divides a quaternion by a double.
         * @throws std::exception if division by 0.
         * @param x Real number.
         * @return Quaternion& 
         */
        Quaternion& operator/=(double x);

        /**
         * @brief Gets the opposite of the quaternion.
         * 
         * @return Quaternion 
         */
        Quaternion operator-() const { return Quaternion(-t, -u, -v, -w); };

        /**
         * @brief Equality operator.
         * 
         * @param q Other quaternion.
         * @return true Quaternions are equal.
         * @return false Quaternions are not equal.
         */
        bool operator==(const Quaternion& q) const {return t == q.t && u == q.u && v == q.v && w == q.w; };
        /**
         * @brief Inequality operator.
         * 
         * @param q Other quaternion.
         * @return true Quaternions are not equal.
         * @return false Quaternions are equal.
         */
        bool operator!=(const Quaternion& q) const {return !(*this == q); };
        /**
         * @brief Disply stream.
         * 
         * @param os Output stream.
         * @param q Quaternion.
         * @return std::ostream& Stream to be displayed.
         */
        friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);
    };

    /**
     * @brief Adds two quaternions.
     * 
     * @param q1 First.
     * @param q2 Second.
     * @return Quaternion Result. 
     */
    Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
    /**
     * @brief Subtracts two quaternions.
     * 
     * @param q1 First.
     * @param q2 Second.
     * @return Quaternion Result. 
     */
    Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
    /**
     * @brief Multiplies two quaternions.
     * 
     * @param q1 First.
     * @param q2 Second.
     * @return Quaternion Result. 
     */
    Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
    /**
     * @brief Divides two quaternions.
     * @throws std::exception if division by 0.
     * @param q1 First.
     * @param q2 Second.
     * @return Quaternion Result. 
     */
    Quaternion operator/(const Quaternion& q1, const Quaternion& q2);

    /**
     * @brief Multiplies a quaternion by a double.
     * 
     * @param q Quaternion.
     * @param x Real number.
     * @return Quaternion Result. 
     */
    Quaternion operator*(const Quaternion& q, double x);
    /**
     * @brief Multiplies a quaternion by a double.
     * 
     * @param x Real number.
     * @param q Quaternion.
     * @return Quaternion Result. 
     */
    Quaternion operator*(double x, const Quaternion& q);
    /**
     * @brief Divides a quaternion by a double.
     * @throws std::exception if division by 0.
     * @param q Quaternion.
     * @param x Real number.
     * @return Quaternion Result. 
     */
    Quaternion operator/(const Quaternion& q, double x);
}



#endif // QUATERNION_H
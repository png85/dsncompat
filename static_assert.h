/** \file
 *
 * \brief static_assert template for non-C++11 compilers
 *
 * This file provides a simple template that can be used for compile time assertions like
 * the \a static_assert in C++11.
 *
 * \author Peter 'png' Hille <peter@das-system-networks.de>
 */
#ifndef STATIC_ASSERT_H
#define STATIC_ASSERT_H

#ifndef HAS_CXX11_STATIC_ASSERT
/** \brief Compile time assertion type
 *
 * This template can be sed as \a static_assert<boolean expression>::expr(); to simulate a
 * compile time assertion like \a static_assert(expr, message) in C++11.
 *
 * \param b Boolean expression that is evaluated at compile time
 */
template <bool b>
struct static_assert{};


/** \brief Template specialization for failed compile time assertions
 *
 * \see static_assert
 */
template <>
struct static_assert<true>
{
  static void expr() {};
};
#endif

#endif // STATIC_ASSERT_H

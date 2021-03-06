// Copyright (c) 1997-2003  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.2-branch/Interval_arithmetic/include/CGAL/Arithmetic_filter/predicates/sign_of_determinant.h $
// $Id: sign_of_determinant.h 29562 2006-03-16 20:48:01Z reichel $
// 
//
// Author(s)     : Sylvain Pion

// This file is automatically generated by
// scripts/cgal_filtered_predicates_generator.pl

#ifndef CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H
#define CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H

#include <CGAL/Profile_counter.h>

CGAL_BEGIN_NAMESPACE
template <class ET> class Lazy_exact_nt;
CGAL_END_NAMESPACE

CGAL_BEGIN_NAMESPACE

template < class CT, class ET, bool Protected, class Cache >
/* inline */
Sign
sign_of_determinant2x2(
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a00,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a01,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a10,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a11)
{
  try
  {
    CGAL_PROFILER("IA sign_of_determinant2x2 calls");
    Protect_FPU_rounding<Protected> Protection;
    return sign_of_determinant2x2(
		a00.interval(),
		a01.interval(),
		a10.interval(),
		a11.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("IA sign_of_determinant2x2 failures");
    Protect_FPU_rounding<!Protected> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant2x2(
		a00.exact(),
		a01.exact(),
		a10.exact(),
		a11.exact());
  }
}

template < class ET >
/* inline */
Sign
sign_of_determinant2x2(
    const Lazy_exact_nt<ET> &a00,
    const Lazy_exact_nt<ET> &a01,
    const Lazy_exact_nt<ET> &a10,
    const Lazy_exact_nt<ET> &a11)
{
  try
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant2x2 calls");
    Protect_FPU_rounding<true> Protection;
    return sign_of_determinant2x2(
		a00.interval(),
		a01.interval(),
		a10.interval(),
		a11.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant2x2 failures");
    Protect_FPU_rounding<false> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant2x2(
		a00.exact(),
		a01.exact(),
		a10.exact(),
		a11.exact());
  }
}

template < class CT, class ET, bool Protected, class Cache >
/* inline */
Sign
sign_of_determinant3x3(
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a00,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a01,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a02,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a10,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a11,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a12,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a20,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a21,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a22)
{
  try
  {
    CGAL_PROFILER("IA sign_of_determinant3x3 calls");
    Protect_FPU_rounding<Protected> Protection;
    return sign_of_determinant3x3(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("IA sign_of_determinant3x3 failures");
    Protect_FPU_rounding<!Protected> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant3x3(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact());
  }
}

template < class ET >
/* inline */
Sign
sign_of_determinant3x3(
    const Lazy_exact_nt<ET> &a00,
    const Lazy_exact_nt<ET> &a01,
    const Lazy_exact_nt<ET> &a02,
    const Lazy_exact_nt<ET> &a10,
    const Lazy_exact_nt<ET> &a11,
    const Lazy_exact_nt<ET> &a12,
    const Lazy_exact_nt<ET> &a20,
    const Lazy_exact_nt<ET> &a21,
    const Lazy_exact_nt<ET> &a22)
{
  try
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant3x3 calls");
    Protect_FPU_rounding<true> Protection;
    return sign_of_determinant3x3(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant3x3 failures");
    Protect_FPU_rounding<false> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant3x3(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact());
  }
}

template < class CT, class ET, bool Protected, class Cache >
/* inline */
Sign
sign_of_determinant4x4(
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a00,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a01,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a02,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a03,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a10,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a11,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a12,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a13,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a20,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a21,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a22,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a23,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a30,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a31,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a32,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a33)
{
  try
  {
    CGAL_PROFILER("IA sign_of_determinant4x4 calls");
    Protect_FPU_rounding<Protected> Protection;
    return sign_of_determinant4x4(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("IA sign_of_determinant4x4 failures");
    Protect_FPU_rounding<!Protected> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant4x4(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact());
  }
}

template < class ET >
/* inline */
Sign
sign_of_determinant4x4(
    const Lazy_exact_nt<ET> &a00,
    const Lazy_exact_nt<ET> &a01,
    const Lazy_exact_nt<ET> &a02,
    const Lazy_exact_nt<ET> &a03,
    const Lazy_exact_nt<ET> &a10,
    const Lazy_exact_nt<ET> &a11,
    const Lazy_exact_nt<ET> &a12,
    const Lazy_exact_nt<ET> &a13,
    const Lazy_exact_nt<ET> &a20,
    const Lazy_exact_nt<ET> &a21,
    const Lazy_exact_nt<ET> &a22,
    const Lazy_exact_nt<ET> &a23,
    const Lazy_exact_nt<ET> &a30,
    const Lazy_exact_nt<ET> &a31,
    const Lazy_exact_nt<ET> &a32,
    const Lazy_exact_nt<ET> &a33)
{
  try
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant4x4 calls");
    Protect_FPU_rounding<true> Protection;
    return sign_of_determinant4x4(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant4x4 failures");
    Protect_FPU_rounding<false> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant4x4(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact());
  }
}

template < class CT, class ET, bool Protected, class Cache >
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant5x5(
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a00,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a01,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a02,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a03,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a04,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a10,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a11,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a12,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a13,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a14,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a20,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a21,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a22,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a23,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a24,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a30,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a31,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a32,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a33,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a34,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a40,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a41,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a42,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a43,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a44)
{
  try
  {
    CGAL_PROFILER("IA sign_of_determinant5x5 calls");
    Protect_FPU_rounding<Protected> Protection;
    return sign_of_determinant5x5(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("IA sign_of_determinant5x5 failures");
    Protect_FPU_rounding<!Protected> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant5x5(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact());
  }
}

template < class ET >
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant5x5(
    const Lazy_exact_nt<ET> &a00,
    const Lazy_exact_nt<ET> &a01,
    const Lazy_exact_nt<ET> &a02,
    const Lazy_exact_nt<ET> &a03,
    const Lazy_exact_nt<ET> &a04,
    const Lazy_exact_nt<ET> &a10,
    const Lazy_exact_nt<ET> &a11,
    const Lazy_exact_nt<ET> &a12,
    const Lazy_exact_nt<ET> &a13,
    const Lazy_exact_nt<ET> &a14,
    const Lazy_exact_nt<ET> &a20,
    const Lazy_exact_nt<ET> &a21,
    const Lazy_exact_nt<ET> &a22,
    const Lazy_exact_nt<ET> &a23,
    const Lazy_exact_nt<ET> &a24,
    const Lazy_exact_nt<ET> &a30,
    const Lazy_exact_nt<ET> &a31,
    const Lazy_exact_nt<ET> &a32,
    const Lazy_exact_nt<ET> &a33,
    const Lazy_exact_nt<ET> &a34,
    const Lazy_exact_nt<ET> &a40,
    const Lazy_exact_nt<ET> &a41,
    const Lazy_exact_nt<ET> &a42,
    const Lazy_exact_nt<ET> &a43,
    const Lazy_exact_nt<ET> &a44)
{
  try
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant5x5 calls");
    Protect_FPU_rounding<true> Protection;
    return sign_of_determinant5x5(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant5x5 failures");
    Protect_FPU_rounding<false> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant5x5(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact());
  }
}

template < class CT, class ET, bool Protected, class Cache >
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant6x6(
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a00,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a01,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a02,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a03,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a04,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a05,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a10,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a11,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a12,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a13,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a14,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a15,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a20,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a21,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a22,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a23,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a24,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a25,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a30,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a31,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a32,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a33,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a34,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a35,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a40,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a41,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a42,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a43,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a44,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a45,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a50,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a51,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a52,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a53,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a54,
    const Filtered_exact <CT, ET, Dynamic, Protected, Cache> &a55)
{
  try
  {
    CGAL_PROFILER("IA sign_of_determinant6x6 calls");
    Protect_FPU_rounding<Protected> Protection;
    return sign_of_determinant6x6(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a05.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a15.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a25.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a35.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval(),
		a45.interval(),
		a50.interval(),
		a51.interval(),
		a52.interval(),
		a53.interval(),
		a54.interval(),
		a55.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("IA sign_of_determinant6x6 failures");
    Protect_FPU_rounding<!Protected> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant6x6(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a05.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a15.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a25.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a35.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact(),
		a45.exact(),
		a50.exact(),
		a51.exact(),
		a52.exact(),
		a53.exact(),
		a54.exact(),
		a55.exact());
  }
}

template < class ET >
/* CGAL_KERNEL_LARGE_INLINE */
Sign
sign_of_determinant6x6(
    const Lazy_exact_nt<ET> &a00,
    const Lazy_exact_nt<ET> &a01,
    const Lazy_exact_nt<ET> &a02,
    const Lazy_exact_nt<ET> &a03,
    const Lazy_exact_nt<ET> &a04,
    const Lazy_exact_nt<ET> &a05,
    const Lazy_exact_nt<ET> &a10,
    const Lazy_exact_nt<ET> &a11,
    const Lazy_exact_nt<ET> &a12,
    const Lazy_exact_nt<ET> &a13,
    const Lazy_exact_nt<ET> &a14,
    const Lazy_exact_nt<ET> &a15,
    const Lazy_exact_nt<ET> &a20,
    const Lazy_exact_nt<ET> &a21,
    const Lazy_exact_nt<ET> &a22,
    const Lazy_exact_nt<ET> &a23,
    const Lazy_exact_nt<ET> &a24,
    const Lazy_exact_nt<ET> &a25,
    const Lazy_exact_nt<ET> &a30,
    const Lazy_exact_nt<ET> &a31,
    const Lazy_exact_nt<ET> &a32,
    const Lazy_exact_nt<ET> &a33,
    const Lazy_exact_nt<ET> &a34,
    const Lazy_exact_nt<ET> &a35,
    const Lazy_exact_nt<ET> &a40,
    const Lazy_exact_nt<ET> &a41,
    const Lazy_exact_nt<ET> &a42,
    const Lazy_exact_nt<ET> &a43,
    const Lazy_exact_nt<ET> &a44,
    const Lazy_exact_nt<ET> &a45,
    const Lazy_exact_nt<ET> &a50,
    const Lazy_exact_nt<ET> &a51,
    const Lazy_exact_nt<ET> &a52,
    const Lazy_exact_nt<ET> &a53,
    const Lazy_exact_nt<ET> &a54,
    const Lazy_exact_nt<ET> &a55)
{
  try
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant6x6 calls");
    Protect_FPU_rounding<true> Protection;
    return sign_of_determinant6x6(
		a00.interval(),
		a01.interval(),
		a02.interval(),
		a03.interval(),
		a04.interval(),
		a05.interval(),
		a10.interval(),
		a11.interval(),
		a12.interval(),
		a13.interval(),
		a14.interval(),
		a15.interval(),
		a20.interval(),
		a21.interval(),
		a22.interval(),
		a23.interval(),
		a24.interval(),
		a25.interval(),
		a30.interval(),
		a31.interval(),
		a32.interval(),
		a33.interval(),
		a34.interval(),
		a35.interval(),
		a40.interval(),
		a41.interval(),
		a42.interval(),
		a43.interval(),
		a44.interval(),
		a45.interval(),
		a50.interval(),
		a51.interval(),
		a52.interval(),
		a53.interval(),
		a54.interval(),
		a55.interval());
  } 
  catch (Interval_nt_advanced::unsafe_comparison)
  {
    CGAL_PROFILER("Lazy IA sign_of_determinant6x6 failures");
    Protect_FPU_rounding<false> Protection(CGAL_FE_TONEAREST);
    return sign_of_determinant6x6(
		a00.exact(),
		a01.exact(),
		a02.exact(),
		a03.exact(),
		a04.exact(),
		a05.exact(),
		a10.exact(),
		a11.exact(),
		a12.exact(),
		a13.exact(),
		a14.exact(),
		a15.exact(),
		a20.exact(),
		a21.exact(),
		a22.exact(),
		a23.exact(),
		a24.exact(),
		a25.exact(),
		a30.exact(),
		a31.exact(),
		a32.exact(),
		a33.exact(),
		a34.exact(),
		a35.exact(),
		a40.exact(),
		a41.exact(),
		a42.exact(),
		a43.exact(),
		a44.exact(),
		a45.exact(),
		a50.exact(),
		a51.exact(),
		a52.exact(),
		a53.exact(),
		a54.exact(),
		a55.exact());
  }
}

CGAL_END_NAMESPACE

#endif // CGAL_ARITHMETIC_FILTER_PREDICATES_SIGN_OF_DETERMINANT_H

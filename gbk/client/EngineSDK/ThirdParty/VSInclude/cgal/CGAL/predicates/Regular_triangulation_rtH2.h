// Copyright (c) 1999  INRIA Sophia-Antipolis (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.2-branch/Triangulation_2/include/CGAL/predicates/Regular_triangulation_rtH2.h $
// $Id: Regular_triangulation_rtH2.h 28567 2006-02-16 14:30:13Z lsaboret $
// 
//
// Author(s)     : Sylvain Pion <Sylvain.Pion@sophia.inria.fr>
//                 Mariette Yvinec <Mariette.Yvinec@sophia.inria.fr>

#ifndef CGAL_REGULAR_TRIANGULATION_RTH2_H
#define CGAL_REGULAR_TRIANGULATION_RTH2_H

// This file contains the low level homogeneous predicates
// used by the 2D regular triangulation.

CGAL_BEGIN_NAMESPACE

template <class RT>
Comparison_result
compare_power_distanceH2(const RT& phx, const RT& phy, const RT& phw,
			 const RT& pwt,
			 const RT& qhx, const RT& qhy, const RT& qhw,
			 const RT& qwt,
			 const RT& rhx, const RT& rhy, const RT& rhw)
{
  // returns SMALLER if r is closer to p w.r.t. the power metric
  RT dphx = rhx * phw - phx * rhw;
  RT dphy = rhy * phw - phy * rhw;
  RT dqhx = rhx * qhw - qhx * rhw;
  RT dqhy = rhy * qhw - qhy * rhw;
  RT dphw = CGAL_NTS square(phw);
  RT dqhw = CGAL_NTS square(qhw);
  RT drhw = CGAL_NTS square(rhw);

  RT dh1 = CGAL_NTS square(dphx) + CGAL_NTS square(dphy) - pwt * dphw * drhw;
  RT dh2 = CGAL_NTS square(dqhx) + CGAL_NTS square(dqhy) - qwt * dqhw * drhw;
  return CGAL_NTS compare(dh1, dh2);
}


template <class RT>
Oriented_side
power_testH2( const RT &phx, const RT &phy, const RT &phw, const RT &pwt,
              const RT &qhx, const RT &qhy, const RT &qhw, const RT &qwt,
              const RT &rhx, const RT &rhy, const RT &rhw, const RT &rwt,
              const RT &thx, const RT &thy, const RT &thw, const RT &twt)
{
    RT dphx = phx*phw;
    RT dphy = phy*phw;
    RT dphw = CGAL_NTS square(phw);
    RT dpz = CGAL_NTS square(phx) + CGAL_NTS square(phy) - pwt*dphw;

    RT dqhx = qhx*qhw;
    RT dqhy = qhy*qhw;
    RT dqhw = CGAL_NTS square(qhw);
    RT dqz = CGAL_NTS square(qhx) + CGAL_NTS square(qhy) - qwt*dqhw;

    RT drhx = rhx*rhw;
    RT drhy = rhy*rhw;
    RT drhw = CGAL_NTS square(rhw);
    RT drz = CGAL_NTS square(rhx) + CGAL_NTS square(rhy) - rwt*drhw;

    RT dthx = thx*thw;
    RT dthy = thy*thw;
    RT dthw = CGAL_NTS square(thw);
    RT dtz = CGAL_NTS square(thx) + CGAL_NTS square(thy) - twt*dthw;

    return Oriented_side(sign_of_determinant4x4(dphx, dphy, dpz, dphw,
	                                        dqhx, dqhy, dqz, dqhw,
	                                        drhx, drhy, drz, drhw,
	                                        dthx, dthy, dtz, dthw));
}


template <class RT>
Oriented_side
power_testH2( const RT &phx, const RT &phy, const RT &phw, const RT &pwt,
              const RT &qhx, const RT &qhy, const RT &qhw, const RT &qwt,
              const RT &thx, const RT &thy, const RT &thw, const RT &twt)
{
    // Test if we can project on the (x) axis.  If not, then on the
    // (y) axis
    RT pa, qa, ta;

    if (phx * qhw != qhx * phw )
    {
	pa = phx*phw;
	qa = qhx*qhw;
	ta = thx*thw;
    }
    else
    {   
	pa = phy*phw;
	qa = qhy*qhw;
	ta = thy*thw;
    }

    RT dphw = CGAL_NTS square(phw);
    RT dpz = CGAL_NTS square(phx) + CGAL_NTS square(phy) - pwt*dphw;

    RT dqhw = CGAL_NTS square(qhw);
    RT dqz = CGAL_NTS square(qhx) + CGAL_NTS square(qhy) - qwt*dqhw;

    RT dthw = CGAL_NTS square(thw);
    RT dtz = CGAL_NTS square(thx) + CGAL_NTS square(thy) - twt*dthw;

    return Oriented_side(CGAL_NTS compare(pa, qa) *
	                 sign_of_determinant3x3(pa, dpz, dphw,
				                qa, dqz, dqhw,
				                ta, dtz, dthw));
}

CGAL_END_NAMESPACE

#ifdef CGAL_ARITHMETIC_FILTER_H
#ifndef CGAL_ARITHMETIC_FILTER_REGULAR_TRIANGULATION_RTH2_H
#include <CGAL/Arithmetic_filter/predicates/Regular_triangulation_rtH2.h>
#endif // CGAL_ARITHMETIC_FILTER_REGULAR_TRIANGULATION_RTH2_H
#endif

#endif // CGAL_REGULAR_TRIANGULATION_RTH2_H

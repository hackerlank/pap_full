// Copyright (c) 1999  Max-Planck-Institute Saarbruecken (Germany).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/branches/CGAL-3.2-branch/Convex_hull_2/include/CGAL/ch_eddy.C $
// $Id: ch_eddy.C 28567 2006-02-16 14:30:13Z lsaboret $
// 
//
// Author(s)     : Stefan Schirra


#ifndef CGAL_CH_EDDY_C
#define CGAL_CH_EDDY_C

#ifndef CGAL_CH_EDDY_H
#include <CGAL/ch_eddy.h>
#endif // CGAL_CH_EDDY_H

#ifndef CGAL_CH_NO_POSTCONDITIONS
#include <CGAL/convexity_check_2.h>
#endif // CGAL_CH_NO_POSTCONDITIONS

#include <CGAL/ch_assertions.h>
#include <CGAL/ch_selected_extreme_points_2.h>
#include <CGAL/algorithm.h>
#include <CGAL/functional.h>
#include <list>
#include <algorithm>

CGAL_BEGIN_NAMESPACE
template <class List, class ListIterator, class Traits>
void
ch__recursive_eddy(List& L, 
                        ListIterator  a_it, ListIterator  b_it, 
                        const Traits& ch_traits)
{
  typedef  typename Traits::Point_2                         Point_2;    
  typedef  typename Traits::Left_turn_2                     Left_turn_2;
  typedef  typename Traits::Less_signed_distance_to_line_2  Less_dist;

  Left_turn_2 left_turn    = ch_traits.left_turn_2_object();
  
  CGAL_ch_precondition( \
    std::find_if(a_it, b_it, \
            bind_1(bind_1(left_turn, *b_it), *a_it)) \
    != b_it );


  ListIterator f_it = successor(a_it);
  Less_dist less_dist = ch_traits.less_signed_distance_to_line_2_object();
  ListIterator 
      c_it = std::min_element( f_it, b_it,  // max before
                               bind_1(bind_1(less_dist, *a_it), *b_it));
  Point_2 c = *c_it;

  c_it = std::partition(f_it, b_it, bind_1(bind_1(left_turn, c), *a_it));
  f_it = std::partition(c_it, b_it, bind_1(bind_1(left_turn, *b_it), c));
  c_it = L.insert(c_it, c);
  L.erase( f_it, b_it );

  if ( successor(a_it) != c_it )
  {
      ch__recursive_eddy( L, a_it, c_it, ch_traits);
  }
  if ( successor(c_it) != b_it )
  {
      ch__recursive_eddy( L, c_it, b_it, ch_traits);
  }


}

template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
ch_eddy(InputIterator first, InputIterator last,
             OutputIterator  result,
             const Traits& ch_traits)
{
  typedef  typename Traits::Point_2                         Point_2;    
  typedef  typename Traits::Left_turn_2                     Left_turn_2;
  typedef  typename Traits::Equal_2                         Equal_2;   

  Left_turn_2 left_turn    = ch_traits.left_turn_2_object();  
  Equal_2     equal_points = ch_traits.equal_2_object();   

  if (first == last) return result;
  std::list< Point_2 >   L;
  std::copy( first, last, std::back_inserter(L) );

  typedef typename std::list< Point_2 >::iterator  list_iterator;
  list_iterator   w, e;
  ch_we_point(L.begin(), L.end(), w, e, ch_traits);
  Point_2 wp = *w;
  Point_2 ep = *e;
  if (equal_points(wp,ep) )
  {
      *result = wp;  ++result;
      return result;
  }

  L.erase(w);
  L.erase(e);
  
  e = std::partition(L.begin(), L.end(), 
                     bind_1(bind_1(left_turn, ep), wp) );
  L.push_front(wp);
  e = L.insert(e, ep);

  if ( successor(L.begin()) != e )
  {
      ch__recursive_eddy( L, L.begin(), e, ch_traits);
  }
  w = std::find_if( e, L.end(), bind_1(bind_1(left_turn, wp), ep) );
  if ( w == L.end() )
  {
      L.erase( ++e, L.end() );
      return std::copy( L.begin(), L.end(), result );
  }
  w = L.insert(L.end(), wp);
  ch__recursive_eddy( L, e, w, ch_traits);


  CGAL_ch_postcondition( \
      is_ccw_strongly_convex_2( L.begin(), w, ch_traits) );
  CGAL_ch_expensive_postcondition( \
      ch_brute_force_check_2( first, last, \
                                   L.begin(), w, ch_traits ) );

  return std::copy( L.begin(), w, result );

}

CGAL_END_NAMESPACE

#endif // CGAL_CH_EDDY_C


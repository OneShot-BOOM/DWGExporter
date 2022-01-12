/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2018, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2018 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef OD_GECYLNDR_H
#define OD_GECYLNDR_H /*!DOM*/

#include "OdPlatformSettings.h"
#include "Ge/GeSurface.h"
#include "Ge/GeInterval.h"

class OdGeCircArc3d;

#include "TD_PackPush.h"

/** \details
    This class represents right circular cylinders.

    \remarks
    A right circular cylinder is defined by its

    *  radius
    *  axis of symmetry
    *  origin (a point on the axis)

    It is generated by revolving a line parallel to the axis of symmetry,
    at a distance of radius. 

    The cylinder is parameterized as follows:

    Parameter V is the angle of revolution measured from the refAxis
    (an axis perpendicular to the axis of symmetry).  For a closed cone,
    it defaults to [-OdaPI, OdaPI).  The right hand rule applied along the
    direction of the axis of symmetry defines the positive direction
    of V.  The surface is periodic in V with a period of Oda2PI.

    Parameter U varies along the axis of symmetry.  U is dimensionless,
    and increases in the direction of the axis of symmetry. 
    U = 0 corresponds to center of the base of this cylinder, 
    and U = 1 corresponds to the center of the top of this cylinder.  
    
    [umin, umax] x [vmin, vmax] defines a four sided cylindrical
    patch bounded by two straight lines (at vmin and vmax), and
    two circular arcs (at umin and umax).  The following constraints
    apply to the definition of a cylindrical patch:

    * umin < umax
    * |vmax - vmin| <= Oda2PI.
    * radius > 0.0

    Corresponding C++ library: TD_Ge

    <group OdGe_Classes> 

    \sa
    <link ge_OdGeCylinder.html, Working with Cylinders>
*/
class GE_TOOLKIT_EXPORT OdGeCylinder : public OdGeSurface
{
public:


  /** \param radius [in]  Radius of this cylinder. 
    \param origin [in]  A point on the axis of symmetry.
    \param axisOfSymmetry [in]  Axis of symmetry (rotation).
    \param refAxis [in]  defines thegle 0 of circular end.
    \param height [in]  Height interval of this cylinder.
    \param startAng [in]  Start angle.
    \param endAng [in]  End angle.
    \remarks
    All angles are expressed in radians.

  */
  OdGeCylinder();
  OdGeCylinder(
    double radius, 
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry);
  OdGeCylinder(
    double radius, 
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry,
    const OdGeVector3d& refAxis,
    const OdGeInterval& height,
    double startAng, 
    double endAng);
  OdGeCylinder(const OdGeCylinder&);

  /** \details
    Returns the radius of this cylinder.
  */
   double radius() const;

  /** \details
    Returns the origin of this cylinder.
  */
   OdGePoint3d origin() const;

  /** \details
    Returns the starting and ending angles of this cylinder.

    \param startAng [out]  Receives the start angle.
    \param endAng [out]  Receives the end angle.
    \remarks
    All angles are expressed in radians.

  */
   void getAngles(
    double& startAng, 
    double& endAng) const;

  /** \details
    Returns the interval of the axis of symmetry.

    \param height [out]  Receives the interval of the axis of symmetry.
  */
   void getHeight(
    OdGeInterval& height) const;

  /** \details
    Returns the height of this cylinder corresponding to
    the specified position on the U-axis.

    \remarks
    Parameter U varies along the axis of symmetry.  U is dimensionless,
    and increases in the direction of the axis of symmetry. 

    \param u [in]  Position on the U-axis of this cylinder.
  */
   double heightAt(
    double u) const;

  /** \details
    Returns the axis of symmetry of this cylinder.
  */
   OdGeVector3d axisOfSymmetry() const;

  /** \details
    Returns the reference axis of this cylinder.
  */
   OdGeVector3d refAxis() const;

  /** \details
    Returns true if and only if the normal to this surface
    is pointing outward.
  */
   bool isOuterNormal() const;

  /** \details
    Returns true if and only if this cylinder
    is a full circle within the specified tolerance.

    \param tol [in]  Geometric tolerance.
  */
   bool isClosed(
    const OdGeTol& tol = OdGeContext::gTol) const;

  /** \details
    Sets the radius of this cylinder.

    \param radius [in]  Radius of this cylinder.
  */
   OdGeCylinder& setRadius(
    double radius);

  /** \details
    Sets the starting and ending angles of this cylinder.

    \param startAng [in]  Start angle.
    \param endAng [in]  End angle.
    
    \remarks
    All angles are expressed in radians.

  */
   OdGeCylinder& setAngles(
    double startAng, 
    double endAng);

  /** \details
    Sets the height interval of this cylinder.

    \param height [in]  Height interval of this cylinder.
  */
   OdGeCylinder& setHeight(
    const OdGeInterval& height);

  /** \details
    Sets the parameters for this cylinder according to the arguments, 
    and returns a reference to this cylinder.

    \param radius [in]  Radius of this cylinder. 
    \param axisOfSym [in]  Axis of symmetry (rotation).
  */
   OdGeCylinder& set(
    double radius, 
    const OdGePoint3d& origin, 
    const OdGeVector3d& axisOfSym);
  
  /** \details
    Sets the parameters for this cylinder according to the arguments, 
    and returns a reference to this cylinder.

    \param radius [in]  Radius of this cylinder. 
    \param axisOfSymmetry [in]  Axis of symmetry (rotation).
    \param refAxis [in]  defines thegle 0 of circular end.
    \param height [in]  Height interval of this cylinder.
    \param startAng [in]  Start angle.
    \param endAng [in]  End angle.
    \remarks
    All angles are expressed in radians.
  */
  OdGeCylinder& set(
    double radius, 
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry,
    const OdGeVector3d& refAxis,
    const OdGeInterval& height,
    double startAng, 
    double endAng);

  /** \details
    Returns true if and only if this cylinder intersects with
    a line entity, and returns the number of intersections and the
    points of intersection.

    \param lineEnt [in]  Any 3D line entity.
    \param numInt [out]  Receives the number of intersections.
    \param p1 [out]  Receives the first intersection point.
    \param p2 [out]  Receives the second intersection point.
    \param tol [in]  Geometric tolerance.

    \remarks
    * p1 is valid if and only if numInt >= 1.
    * p2 is valid if and only if numInt = 2.
  */
   bool intersectWith(
    const OdGeLinearEnt3d& linEnt, 
    int& numInt,
    OdGePoint3d& p1, 
    OdGePoint3d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  // Assignment operator
  OdGeCylinder& operator =(const OdGeCylinder& cylinder);

  //////////////////////////////////////////////////////////////////////////
  // TD Special :

  /** \details
  Sets if the cylinder normal is pointing outward.

  \param isOuterNormal [in]  Flag indicating if the cylinder normal is to be set to point outward.
  */
  void setIsOuterNormal(
    bool isOuterNormal);

};

#include "TD_PackPop.h"

#endif // OD_GECYLNDR_H

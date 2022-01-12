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



#ifndef _HOOPSRESULTEX_INCLUDED_
#define _HOOPSRESULTEX_INCLUDED_ /*!DOM*/

/** \details
  <group OdExport_Classes> 
*/
namespace TD_HOOPS_COMMON_EXPORT {

/** \details
  Declares the hoops result codes.
*/
enum HoopsResultEx
{
  exOk                           = 0x00000000,
  exInternalError                = 0x00010000,
  exFileSavingError              ,
  exNullDatabase                 ,
  exOdError                      = 0x00020000,
  exLastErrorNum                 = 0xFFFFFFFF
};
}
#endif //_HOOPSRESULTEX_INCLUDED_

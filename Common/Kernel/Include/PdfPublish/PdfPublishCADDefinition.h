/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2017, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2017 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// PdfPublishCADDefinition.h
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _PDF_PUBLISH_CADDEFINITION_INCLUDED_
#define _PDF_PUBLISH_CADDEFINITION_INCLUDED_

#include "PdfPublishCommon.h"
#include "PdfPublishBaseObject.h"
#include "DbBaseDatabase.h"


/** \details 
Contains declarations for Teigha Publish.
*/
namespace OdPdfPublish{

/** \details
  This class implements an animation in .pdf documents created with Teigha Publish.
*/
class PDFPUBLISH_TOOLKIT OdCADDefinition : public OdObject
{
  //DOM-IGNORE-BEGIN
protected:
  OdCADDefinition();
  //DOM-IGNORE-END
public:
  //DOM-IGNORE-BEGIN
  ODRX_DECLARE_MEMBERS(OdCADDefinition);
  ODRX_HEAP_OPERATORS();
  //DOM-IGNORE-END

  /** \details
    Destroys an object.
  */
  virtual ~OdCADDefinition();

  void setDatabase(OdDbBaseDatabase *database);
  void setLayoutName(const OdString& name);

  //The whole drawing will be published (using its extents) and scaled to fit the specified output media size
  void setMediaSize(const Page::PaperUnits units, const double width, const double height);

  void setEmbededTrueTypeFonts(bool state);
  void setTrueTypeFontAsGeometry(bool state);
  void setSHXTextAsGeometry(bool state);
  void setTextSearchable(bool state);

  void setExportHyperlinks(bool state);

  void setGeomDPI(OdUInt32 dpi);
  void setBWImagesDPI(OdUInt32 dpi);
  void setColorImagesDPI(OdUInt32 dpi);

  void setMeasuring(bool state);

  void setColorPolicy(CAD::ColorPolicy policy);

  OdDbBaseDatabase* getDatabase() const;
  void getLayoutName(OdString& name) const;

  void getMediaSize(Page::PaperUnits& units, double& width, double& height) const;

  void getEmbededTrueTypeFonts(bool& state) const;
  void getTrueTypeFontAsGeometry(bool& state) const;
  void getSHXTextAsGeometry(bool& state) const;
  void getTextSearchable(bool& state) const;

  void getExportHyperlinks(bool& state) const;

  void getGeomDPI(OdUInt32& dpi) const;
  void getBWImagesDPI(OdUInt32& dpi) const;
  void getColorImagesDPI(OdUInt32& dpi) const;

  void getMeasuring(bool& state) const;

  void getColorPolicy(CAD::ColorPolicy& policy) const;

};

/** \details
  A data type that represents a smart pointer to an <link OdPdfPublish::OdCADReference, OdCADReference> object.
*/
SMARTPTR(OdCADDefinition);

}
#endif // _PDF_PUBLISH_CADDEFINITION_INCLUDED_


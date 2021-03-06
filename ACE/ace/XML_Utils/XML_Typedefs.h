/**
 * @file XML_Typedefs.h
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 *
 * Typedefs from the XML Utilities.
 */
#ifndef XML_TYPEDEFS_H
#define XML_TYPEDEFS_H

#include "XML_Utils_Export.h"
#include "XML_Helper.h"
#include "XML_Schema_Resolver.h"
#include "XML_Error_Handler.h"

namespace XML
{
  class XML_Utils_Export XML_Typedef
  {
  public:
    typedef ::XML::Environment_Resolver PATH_RESOLVER;
    typedef ::XML::XML_Schema_Resolver< ::XML::Environment_Resolver> XML_RESOLVER;
    typedef ::XML::XML_Error_Handler ERROR_HANDLER;
    typedef ::XML::XML_Helper<XML_RESOLVER, ERROR_HANDLER> HELPER;

  public:
    static HELPER XML_HELPER;
  };
}

#endif /* XML_TYPEDEFS_H */

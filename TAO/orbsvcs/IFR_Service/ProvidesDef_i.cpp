/* -*- C++ -*- */
// $Id$

#include "Repository_i.h"
#include "ProvidesDef_i.h"

ACE_RCSID(IFR_Service, ProvidesDef_i, "$Id$")

TAO_ProvidesDef_i::TAO_ProvidesDef_i (
    TAO_Repository_i *repo,
    ACE_Configuration_Section_Key section_key
  )
  : TAO_IRObject_i (repo, section_key),
    TAO_Contained_i (repo, section_key)
{
}

TAO_ProvidesDef_i::~TAO_ProvidesDef_i (void)
{
}

IR_DefinitionKind
TAO_ProvidesDef_i::def_kind (CORBA::Environment &)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return dk_Provides;
}

void 
TAO_ProvidesDef_i::destroy (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->destroy_i (ACE_TRY_ENV);
}

void 
TAO_ProvidesDef_i::destroy_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
}

IR_Contained::Description *
TAO_ProvidesDef_i::describe (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (0);

  return this->describe_i (ACE_TRY_ENV);
}

IR_Contained::Description *
TAO_ProvidesDef_i::describe_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}

IR_InterfaceDef_ptr 
TAO_ProvidesDef_i::interface_type (CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_READ_GUARD_RETURN (IR_InterfaceDef::_nil ());

  return this->interface_type_i (ACE_TRY_ENV);
}

IR_InterfaceDef_ptr 
TAO_ProvidesDef_i::interface_type_i (CORBA::Environment & /* ACE_TRY_ENV */)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  // TODO
  return 0;
}


/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIUVCONTROLLER_H_
#define _NIUVCONTROLLER_H_

#include "NiTimeController.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiUVData;

#include "gen/obj_defines.h"

class NiUVController;
typedef Ref<NiUVController> NiUVControllerRef;

/*!
 * NiUVController - Time controller for texture coordinates.
 */

class NiUVController : public NI_U_V_CONTROLLER_PARENT {
public:
	NiUVController();
	~NiUVController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_U_V_CONTROLLER_MEMBERS
};

#endif

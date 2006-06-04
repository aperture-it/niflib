/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSAGEDEATHMODIFIER_H_
#define _NIPSYSAGEDEATHMODIFIER_H_

#include "NiPSysModifier.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiPSysSpawnModifier;

#include "gen/obj_defines.h"

class NiPSysAgeDeathModifier;
typedef Ref<NiPSysAgeDeathModifier> NiPSysAgeDeathModifierRef;

/*!
 * NiPSysAgeDeathModifier - Unknown particle modifier.
 */

class NiPSysAgeDeathModifier : public NI_P_SYS_AGE_DEATH_MODIFIER_PARENT {
public:
	NiPSysAgeDeathModifier();
	~NiPSysAgeDeathModifier();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS
};

#endif

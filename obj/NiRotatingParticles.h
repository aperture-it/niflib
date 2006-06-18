/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIROTATINGPARTICLES_H_
#define _NIROTATINGPARTICLES_H_

#include "NiParticles.h"
namespace NifLib {

#include "../gen/obj_defines.h"

class NiRotatingParticles;
typedef Ref<NiRotatingParticles> NiRotatingParticlesRef;

/*!
 * NiRotatingParticles - Unknown.
 */

class NIFLIB_API NiRotatingParticles : public NI_ROTATING_PARTICLES_PARENT {
public:
	NiRotatingParticles();
	~NiRotatingParticles();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_ROTATING_PARTICLES_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif

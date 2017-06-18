/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIPHYSXPROPDESC_H_
#define _NIPHYSXPROPDESC_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiObject.h"

// Include structures
#include "../Ref.h"
#include "../gen/physXMaterialRef.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPhysXActorDesc;
class NiPhysXD6JointDesc;
class NiPhysXPropDesc;
typedef Ref<NiPhysXPropDesc> NiPhysXPropDescRef;

/*! Unknown PhysX node. */
class NiPhysXPropDesc : public NiObject {
public:
	/*! Constructor */
	NIFLIB_API NiPhysXPropDesc();

	/*! Destructor */
	NIFLIB_API virtual ~NiPhysXPropDesc();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	/***Begin Example Naive Implementation****

	// Unknown
	// \return The current value.
	vector<Ref<NiPhysXActorDesc > > GetActorDescs() const;

	// Unknown
	// \param[in] value The new value.
	void SetActorDescs( const vector<Ref<NiPhysXActorDesc > >& value );

	// PhysX Joint Descriptions
	// \return The current value.
	vector<Ref<NiPhysXD6JointDesc > > GetJointDescs() const;

	// PhysX Joint Descriptions
	// \param[in] value The new value.
	void SetJointDescs( const vector<Ref<NiPhysXD6JointDesc > >& value );

	// PhysX Material Descriptions
	// \return The current value.
	vector<physXMaterialRef > GetMaterialDescs() const;

	// PhysX Material Descriptions
	// \param[in] value The new value.
	void SetMaterialDescs( const vector<physXMaterialRef >& value );

	****End Example Naive Implementation***/

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Number of NiPhysXActorDesc references */
	mutable int numDests;
	/*! Unknown */
	vector<Ref<NiPhysXActorDesc > > actorDescs;
	/*! Unknown */
	mutable unsigned int numJoints;
	/*! PhysX Joint Descriptions */
	vector<Ref<NiPhysXD6JointDesc > > jointDescs;
	/*! Unknown */
	int unknownInt1;
	/*! Unknown */
	mutable unsigned int numMaterials;
	/*! PhysX Material Descriptions */
	vector<physXMaterialRef > materialDescs;
	/*! Unknown */
	unsigned int unknownInt2;
	/*! Unknown */
	unsigned int unknownInt3;
	/*! Unknown */
	IndexString unknownString4;
	/*! Unknown */
	unsigned int unknownInt5;
	/*! Unknown */
	byte unknownByte6;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif

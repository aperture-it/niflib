/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkCompressedMeshShapeData.h"
#include "../../include/gen/bhkCMSDMaterial.h"
#include "../../include/gen/bhkCMSDTransform.h"
#include "../../include/gen/QuaternionXYZW.h"
#include "../../include/gen/bhkCMSDBigTris.h"
#include "../../include/gen/bhkCMSDChunk.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCompressedMeshShapeData::TYPE("bhkCompressedMeshShapeData", &NiObject::TYPE );

bhkCompressedMeshShapeData::bhkCompressedMeshShapeData() : bitsPerIndex((unsigned int)0), bitsPerWindex((unsigned int)0), windexmask((unsigned int)0), indexmask((unsigned int)0), radius_error_(0.0f), unknownByte1((byte)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownInt5((unsigned int)0), unknownByte2((byte)0), numMaterials((unsigned int)0), unknownInt6((unsigned int)0), numTransforms((unsigned int)0), numBigVerts((unsigned int)0), numBigTris((unsigned int)0), numChunks((unsigned int)0), unknownInt12((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkCompressedMeshShapeData::~bhkCompressedMeshShapeData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkCompressedMeshShapeData::GetType() const {
	return TYPE;
}

NiObject * bhkCompressedMeshShapeData::Create() {
	return new bhkCompressedMeshShapeData;
}

void bhkCompressedMeshShapeData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( bitsPerIndex, in, info );
	NifStream( bitsPerWindex, in, info );
	NifStream( windexmask, in, info );
	NifStream( indexmask, in, info );
	NifStream( radius_error_, in, info );
	NifStream( boundMin, in, info );
	NifStream( boundMax, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( numMaterials, in, info );
	chunkMaterials.resize(numMaterials);
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].material, in, info );
		NifStream( chunkMaterials[i1].unknownInteger, in, info );
	};
	NifStream( unknownInt6, in, info );
	NifStream( numTransforms, in, info );
	if ( (numTransforms >= 1) ) {
		chunkTransforms.resize(numTransforms);
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
			NifStream( chunkTransforms[i2].translation, in, info );
			NifStream( chunkTransforms[i2].rotation.x, in, info );
			NifStream( chunkTransforms[i2].rotation.y, in, info );
			NifStream( chunkTransforms[i2].rotation.z, in, info );
			NifStream( chunkTransforms[i2].rotation.w, in, info );
		};
	};
	NifStream( numBigVerts, in, info );
	if ( (numBigVerts >= 1) ) {
		bigVerts.resize(numBigVerts);
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], in, info );
		};
	};
	NifStream( numBigTris, in, info );
	if ( (numBigTris >= 1) ) {
		bigTris.resize(numBigTris);
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			NifStream( bigTris[i2].triangle1, in, info );
			NifStream( bigTris[i2].triangle2, in, info );
			NifStream( bigTris[i2].triangle3, in, info );
			NifStream( bigTris[i2].unknownInt1, in, info );
			NifStream( bigTris[i2].unknownShort1, in, info );
		};
	};
	NifStream( numChunks, in, info );
	chunks.resize(numChunks);
	for (unsigned int i1 = 0; i1 < chunks.size(); i1++) {
		NifStream( chunks[i1].translation, in, info );
		NifStream( chunks[i1].materialIndex, in, info );
		NifStream( chunks[i1].unknownShort1, in, info );
		NifStream( chunks[i1].transformIndex, in, info );
		NifStream( chunks[i1].numVertices, in, info );
		chunks[i1].vertices.resize(chunks[i1].numVertices);
		for (unsigned int i2 = 0; i2 < chunks[i1].vertices.size(); i2++) {
			NifStream( chunks[i1].vertices[i2], in, info );
		};
		NifStream( chunks[i1].numIndices, in, info );
		chunks[i1].indices.resize(chunks[i1].numIndices);
		for (unsigned int i2 = 0; i2 < chunks[i1].indices.size(); i2++) {
			NifStream( chunks[i1].indices[i2], in, info );
		};
		NifStream( chunks[i1].numStrips, in, info );
		chunks[i1].strips.resize(chunks[i1].numStrips);
		for (unsigned int i2 = 0; i2 < chunks[i1].strips.size(); i2++) {
			NifStream( chunks[i1].strips[i2], in, info );
		};
		NifStream( chunks[i1].numIndices2, in, info );
		chunks[i1].indices2.resize(chunks[i1].numIndices2);
		for (unsigned int i2 = 0; i2 < chunks[i1].indices2.size(); i2++) {
			NifStream( chunks[i1].indices2[i2], in, info );
		};
	};
	NifStream( unknownInt12, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numTransforms = (unsigned int)(chunkTransforms.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	NifStream( bitsPerIndex, out, info );
	NifStream( bitsPerWindex, out, info );
	NifStream( windexmask, out, info );
	NifStream( indexmask, out, info );
	NifStream( radius_error_, out, info );
	NifStream( boundMin, out, info );
	NifStream( boundMax, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( numMaterials, out, info );
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		NifStream( chunkMaterials[i1].material, out, info );
		NifStream( chunkMaterials[i1].unknownInteger, out, info );
	};
	NifStream( unknownInt6, out, info );
	NifStream( numTransforms, out, info );
	if ( (numTransforms >= 1) ) {
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
			NifStream( chunkTransforms[i2].translation, out, info );
			NifStream( chunkTransforms[i2].rotation.x, out, info );
			NifStream( chunkTransforms[i2].rotation.y, out, info );
			NifStream( chunkTransforms[i2].rotation.z, out, info );
			NifStream( chunkTransforms[i2].rotation.w, out, info );
		};
	};
	NifStream( numBigVerts, out, info );
	if ( (numBigVerts >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			NifStream( bigVerts[i2], out, info );
		};
	};
	NifStream( numBigTris, out, info );
	if ( (numBigTris >= 1) ) {
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			NifStream( bigTris[i2].triangle1, out, info );
			NifStream( bigTris[i2].triangle2, out, info );
			NifStream( bigTris[i2].triangle3, out, info );
			NifStream( bigTris[i2].unknownInt1, out, info );
			NifStream( bigTris[i2].unknownShort1, out, info );
		};
	};
	NifStream( numChunks, out, info );
	for (unsigned int i1 = 0; i1 < chunks.size(); i1++) {
		chunks[i1].numIndices2 = (unsigned int)(chunks[i1].indices2.size());
		chunks[i1].numStrips = (unsigned int)(chunks[i1].strips.size());
		chunks[i1].numIndices = (unsigned int)(chunks[i1].indices.size());
		chunks[i1].numVertices = (unsigned int)(chunks[i1].vertices.size());
		NifStream( chunks[i1].translation, out, info );
		NifStream( chunks[i1].materialIndex, out, info );
		NifStream( chunks[i1].unknownShort1, out, info );
		NifStream( chunks[i1].transformIndex, out, info );
		NifStream( chunks[i1].numVertices, out, info );
		for (unsigned int i2 = 0; i2 < chunks[i1].vertices.size(); i2++) {
			NifStream( chunks[i1].vertices[i2], out, info );
		};
		NifStream( chunks[i1].numIndices, out, info );
		for (unsigned int i2 = 0; i2 < chunks[i1].indices.size(); i2++) {
			NifStream( chunks[i1].indices[i2], out, info );
		};
		NifStream( chunks[i1].numStrips, out, info );
		for (unsigned int i2 = 0; i2 < chunks[i1].strips.size(); i2++) {
			NifStream( chunks[i1].strips[i2], out, info );
		};
		NifStream( chunks[i1].numIndices2, out, info );
		for (unsigned int i2 = 0; i2 < chunks[i1].indices2.size(); i2++) {
			NifStream( chunks[i1].indices2[i2], out, info );
		};
	};
	NifStream( unknownInt12, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkCompressedMeshShapeData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numChunks = (unsigned int)(chunks.size());
	numBigTris = (unsigned int)(bigTris.size());
	numBigVerts = (unsigned int)(bigVerts.size());
	numTransforms = (unsigned int)(chunkTransforms.size());
	numMaterials = (unsigned int)(chunkMaterials.size());
	out << "  Bits Per Index:  " << bitsPerIndex << endl;
	out << "  Bits Per WIndex:  " << bitsPerWindex << endl;
	out << "  WIndexMask:  " << windexmask << endl;
	out << "  IndexMask:  " << indexmask << endl;
	out << "  Radius?Error?:  " << radius_error_ << endl;
	out << "  Bound Min:  " << boundMin << endl;
	out << "  Bound Max:  " << boundMax << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Num Materials:  " << numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < chunkMaterials.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Material:  " << chunkMaterials[i1].material << endl;
		out << "    Unknown Integer:  " << chunkMaterials[i1].unknownInteger << endl;
	};
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Num Transforms:  " << numTransforms << endl;
	if ( (numTransforms >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunkTransforms.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Translation:  " << chunkTransforms[i2].translation << endl;
			out << "      x:  " << chunkTransforms[i2].rotation.x << endl;
			out << "      y:  " << chunkTransforms[i2].rotation.y << endl;
			out << "      z:  " << chunkTransforms[i2].rotation.z << endl;
			out << "      w:  " << chunkTransforms[i2].rotation.w << endl;
		};
	};
	out << "  Num Big Verts:  " << numBigVerts << endl;
	if ( (numBigVerts >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigVerts.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Big Verts[" << i2 << "]:  " << bigVerts[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Big Tris:  " << numBigTris << endl;
	if ( (numBigTris >= 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < bigTris.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Triangle 1:  " << bigTris[i2].triangle1 << endl;
			out << "      Triangle 2:  " << bigTris[i2].triangle2 << endl;
			out << "      Triangle 3:  " << bigTris[i2].triangle3 << endl;
			out << "      Unknown Int 1:  " << bigTris[i2].unknownInt1 << endl;
			out << "      Unknown Short 1:  " << bigTris[i2].unknownShort1 << endl;
		};
	};
	out << "  Num Chunks:  " << numChunks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < chunks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		chunks[i1].numIndices2 = (unsigned int)(chunks[i1].indices2.size());
		chunks[i1].numStrips = (unsigned int)(chunks[i1].strips.size());
		chunks[i1].numIndices = (unsigned int)(chunks[i1].indices.size());
		chunks[i1].numVertices = (unsigned int)(chunks[i1].vertices.size());
		out << "    Translation:  " << chunks[i1].translation << endl;
		out << "    Material Index:  " << chunks[i1].materialIndex << endl;
		out << "    Unknown Short 1:  " << chunks[i1].unknownShort1 << endl;
		out << "    Transform Index:  " << chunks[i1].transformIndex << endl;
		out << "    Num Vertices:  " << chunks[i1].numVertices << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks[i1].vertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << chunks[i1].vertices[i2] << endl;
			array_output_count++;
		};
		out << "    Num Indices:  " << chunks[i1].numIndices << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks[i1].indices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Indices[" << i2 << "]:  " << chunks[i1].indices[i2] << endl;
			array_output_count++;
		};
		out << "    Num Strips:  " << chunks[i1].numStrips << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks[i1].strips.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Strips[" << i2 << "]:  " << chunks[i1].strips[i2] << endl;
			array_output_count++;
		};
		out << "    Num Indices 2:  " << chunks[i1].numIndices2 << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < chunks[i1].indices2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Indices 2[" << i2 << "]:  " << chunks[i1].indices2[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Int 12:  " << unknownInt12 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShapeData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCompressedMeshShapeData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> bhkCompressedMeshShapeData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
const unsigned int bhkCompressedMeshShapeData::GetBitsPerIndex() const {
	return bitsPerIndex;
}

void bhkCompressedMeshShapeData::SetBitsPerIndex(unsigned int value) {
	bitsPerIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetBitsPerWIndex() const {
	return bitsPerWIndex;
}

void bhkCompressedMeshShapeData::SetBitsPerWIndex(unsigned int value) {
	bitsPerWIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetMaskWIndex() const {
	return maskWIndex;
}

void bhkCompressedMeshShapeData::SetMaskWIndex(unsigned int value) {
	maskWIndex = value;
}

const unsigned int bhkCompressedMeshShapeData::GetMaskIndex() const {
	return maskIndex;
}

void bhkCompressedMeshShapeData::SetMaskIndex(unsigned int value) {
	maskIndex = value;
}

const float bhkCompressedMeshShapeData::GetError() const {
	return error;
}

void bhkCompressedMeshShapeData::SetError(float value) {
	error = value;
}

const Vector4 bhkCompressedMeshShapeData::GetBoundsMin() const {
	return boundsMin;
}

void bhkCompressedMeshShapeData::SetBoundsMin(Vector4 value) {
	boundsMin = value;
}

const Vector4 bhkCompressedMeshShapeData::GetBoundsMax() const {
	return boundsMax;
}

void bhkCompressedMeshShapeData::SetBoundsMax(Vector4 value) {
	boundsMax = value;
}

unsigned int bhkCompressedMeshShapeData::GetNumMaterials() const {
	return numMaterials;
}

void bhkCompressedMeshShapeData::SetNumMaterials(unsigned int value) {
	numMaterials = value;
}

const vector<bhkCMSDMaterial> & bhkCompressedMeshShapeData::GetChunkMaterials() const {
	return chunkMaterials;
}

unsigned int bhkCompressedMeshShapeData::SetChunkMaterials(vector<bhkCMSDMaterial>& theChunkMaterials)
{
	numMaterials   = theChunkMaterials.size();
	chunkMaterials = theChunkMaterials;
	return numMaterials;
}

unsigned int bhkCompressedMeshShapeData::GetNumTransforms() const {
	return numTransforms;
}

void bhkCompressedMeshShapeData::SetNumTransforms(unsigned int value) {
	numTransforms = value;
}

const vector<bhkCMSDTransform> & bhkCompressedMeshShapeData::GetChunkTransforms() const {
	return chunkTransforms;
}

unsigned int bhkCompressedMeshShapeData::SetChunkTransforms(vector<bhkCMSDTransform>& theChunkTransforms)
{
	numTransforms   = theChunkTransforms.size();
	chunkTransforms = theChunkTransforms;
	return numTransforms;
}

unsigned int bhkCompressedMeshShapeData::GetNumBigVerts() const {
	return numBigVerts;
}

void bhkCompressedMeshShapeData::SetNumBigVerts(unsigned int value) {
	numBigVerts = value;
}

const vector<Vector4> & bhkCompressedMeshShapeData::GetBigVerts() const {
	return bigVerts;
}

unsigned int bhkCompressedMeshShapeData::SetBigVerts(vector<Vector4>& theBigVerts)
{
	numBigVerts = theBigVerts.size();
	bigVerts    = theBigVerts;
	return numBigVerts;
}

unsigned int bhkCompressedMeshShapeData::GetNumBigTris() const {
	return numBigTris;
}

void bhkCompressedMeshShapeData::SetNumBigTris(unsigned int value) {
	numBigTris = value;
}

const vector<bhkCMSDBigTris> & bhkCompressedMeshShapeData::GetBigTris() const {
	return bigTris;
}

unsigned int bhkCompressedMeshShapeData::SetBigTris(vector<bhkCMSDBigTris>& theBigVerts)
{
	numBigTris = theBigVerts.size();
	bigTris    = theBigVerts;
	return numBigTris;
}

unsigned int bhkCompressedMeshShapeData::GetNumChunks() const {
	return numChunks;
}

void bhkCompressedMeshShapeData::SetNumChunks(unsigned int value) {
	numChunks = value;
}

const vector<bhkCMSDChunk> & bhkCompressedMeshShapeData::GetChunks() const {
	return chunks;
}

unsigned int bhkCompressedMeshShapeData::SetChunks(vector<bhkCMSDChunk>& theChunks) {
	numChunks = theChunks.size();
	chunks    = theChunks;
	return numChunks;
}

//--END CUSTOM CODE--//

/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcBoolean.h"
#include "ifcpp/IFC4/include/IfcCartesianPointList3D.h"
#include "ifcpp/IFC4/include/IfcIndexedColourMap.h"
#include "ifcpp/IFC4/include/IfcIndexedTextureMap.h"
#include "ifcpp/IFC4/include/IfcParameterValue.h"
#include "ifcpp/IFC4/include/IfcPositiveInteger.h"
#include "ifcpp/IFC4/include/IfcPresentationLayerAssignment.h"
#include "ifcpp/IFC4/include/IfcStyledItem.h"
#include "ifcpp/IFC4/include/IfcTriangulatedFaceSet.h"

// ENTITY IfcTriangulatedFaceSet 
IfcTriangulatedFaceSet::IfcTriangulatedFaceSet( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcTriangulatedFaceSet::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcTriangulatedFaceSet> copy_self( new IfcTriangulatedFaceSet() );
	if( m_Coordinates ) { copy_self->m_Coordinates = dynamic_pointer_cast<IfcCartesianPointList3D>( m_Coordinates->getDeepCopy(options) ); }
	copy_self->m_Normals.resize( m_Normals.size() );
	for( size_t ii=0; ii<m_Normals.size(); ++ii )
	{
		std::vector<shared_ptr<IfcParameterValue> >& vec_ii = m_Normals[ii];
		std::vector<shared_ptr<IfcParameterValue> >& vec_ii_target = copy_self->m_Normals[ii];
		for( size_t jj=0; jj<vec_ii.size(); ++jj )
		{
			shared_ptr<IfcParameterValue>& item_jj = vec_ii[jj];
			if( item_jj )
			{
				vec_ii_target.emplace_back( dynamic_pointer_cast<IfcParameterValue>( item_jj->getDeepCopy(options) ) );
			}
		}
	}
	if( m_Closed ) { copy_self->m_Closed = dynamic_pointer_cast<IfcBoolean>( m_Closed->getDeepCopy(options) ); }
	copy_self->m_CoordIndex.resize( m_CoordIndex.size() );
	for( size_t ii=0; ii<m_CoordIndex.size(); ++ii )
	{
		std::vector<shared_ptr<IfcPositiveInteger> >& vec_ii = m_CoordIndex[ii];
		std::vector<shared_ptr<IfcPositiveInteger> >& vec_ii_target = copy_self->m_CoordIndex[ii];
		for( size_t jj=0; jj<vec_ii.size(); ++jj )
		{
			shared_ptr<IfcPositiveInteger>& item_jj = vec_ii[jj];
			if( item_jj )
			{
				vec_ii_target.emplace_back( dynamic_pointer_cast<IfcPositiveInteger>( item_jj->getDeepCopy(options) ) );
			}
		}
	}
	for( size_t ii=0; ii<m_PnIndex.size(); ++ii )
	{
		auto item_ii = m_PnIndex[ii];
		if( item_ii )
		{
			copy_self->m_PnIndex.emplace_back( dynamic_pointer_cast<IfcPositiveInteger>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcTriangulatedFaceSet::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCTRIANGULATEDFACESET" << "(";
	if( m_Coordinates ) { stream << "#" << m_Coordinates->m_entity_id; } else { stream << "$"; }
	stream << ",";
	writeTypeOfRealList2D( stream, m_Normals, true );
	stream << ",";
	if( m_Closed ) { m_Closed->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeTypeOfIntList2D( stream, m_CoordIndex, false );
	stream << ",";
	stream << "(";
	for( size_t ii = 0; ii < m_PnIndex.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcPositiveInteger>& type_object = m_PnIndex[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, false );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ");";
}
void IfcTriangulatedFaceSet::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcTriangulatedFaceSet::toString() const { return L"IfcTriangulatedFaceSet"; }
void IfcTriangulatedFaceSet::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 5 ){ std::stringstream err; err << "Wrong parameter count for entity IfcTriangulatedFaceSet, expecting 5, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Coordinates, map );
	readTypeOfRealList2D( args[1], m_Normals );
	m_Closed = IfcBoolean::createObjectFromSTEP( args[2], map );
	readTypeOfIntegerList2D( args[3], m_CoordIndex );
	readTypeOfIntegerList( args[4], m_PnIndex );
}
void IfcTriangulatedFaceSet::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IfcTessellatedFaceSet::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "Closed", m_Closed ) );
	if( !m_PnIndex.empty() )
	{
		shared_ptr<AttributeObjectVector> PnIndex_vec_object( new AttributeObjectVector() );
		std::copy( m_PnIndex.begin(), m_PnIndex.end(), std::back_inserter( PnIndex_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "PnIndex", PnIndex_vec_object ) );
	}
}
void IfcTriangulatedFaceSet::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IfcTessellatedFaceSet::getAttributesInverse( vec_attributes_inverse );
}
void IfcTriangulatedFaceSet::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcTessellatedFaceSet::setInverseCounterparts( ptr_self_entity );
}
void IfcTriangulatedFaceSet::unlinkFromInverseCounterparts()
{
	IfcTessellatedFaceSet::unlinkFromInverseCounterparts();
}

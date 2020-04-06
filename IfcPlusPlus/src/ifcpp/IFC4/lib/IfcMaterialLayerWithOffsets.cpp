/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */
#include <sstream>
#include <limits>

#include "ifcpp/model/AttributeObject.h"
#include "ifcpp/model/BuildingException.h"
#include "ifcpp/model/BuildingGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IFC4/include/IfcExternalReferenceRelationship.h"
#include "ifcpp/IFC4/include/IfcInteger.h"
#include "ifcpp/IFC4/include/IfcLabel.h"
#include "ifcpp/IFC4/include/IfcLayerSetDirectionEnum.h"
#include "ifcpp/IFC4/include/IfcLengthMeasure.h"
#include "ifcpp/IFC4/include/IfcLogical.h"
#include "ifcpp/IFC4/include/IfcMaterial.h"
#include "ifcpp/IFC4/include/IfcMaterialLayerSet.h"
#include "ifcpp/IFC4/include/IfcMaterialLayerWithOffsets.h"
#include "ifcpp/IFC4/include/IfcMaterialProperties.h"
#include "ifcpp/IFC4/include/IfcNonNegativeLengthMeasure.h"
#include "ifcpp/IFC4/include/IfcRelAssociatesMaterial.h"
#include "ifcpp/IFC4/include/IfcText.h"

// ENTITY IfcMaterialLayerWithOffsets 
IfcMaterialLayerWithOffsets::IfcMaterialLayerWithOffsets( int id ) { m_entity_id = id; }
shared_ptr<BuildingObject> IfcMaterialLayerWithOffsets::getDeepCopy( BuildingCopyOptions& options )
{
	shared_ptr<IfcMaterialLayerWithOffsets> copy_self( new IfcMaterialLayerWithOffsets() );
	if( m_Material ) { copy_self->m_Material = dynamic_pointer_cast<IfcMaterial>( m_Material->getDeepCopy(options) ); }
	if( m_LayerThickness ) { copy_self->m_LayerThickness = dynamic_pointer_cast<IfcNonNegativeLengthMeasure>( m_LayerThickness->getDeepCopy(options) ); }
	if( m_IsVentilated ) { copy_self->m_IsVentilated = dynamic_pointer_cast<IfcLogical>( m_IsVentilated->getDeepCopy(options) ); }
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_Category ) { copy_self->m_Category = dynamic_pointer_cast<IfcLabel>( m_Category->getDeepCopy(options) ); }
	if( m_Priority ) { copy_self->m_Priority = dynamic_pointer_cast<IfcInteger>( m_Priority->getDeepCopy(options) ); }
	if( m_OffsetDirection ) { copy_self->m_OffsetDirection = dynamic_pointer_cast<IfcLayerSetDirectionEnum>( m_OffsetDirection->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_OffsetValues.size(); ++ii )
	{
		auto item_ii = m_OffsetValues[ii];
		if( item_ii )
		{
			copy_self->m_OffsetValues.emplace_back( dynamic_pointer_cast<IfcLengthMeasure>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcMaterialLayerWithOffsets::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_entity_id << "= IFCMATERIALLAYERWITHOFFSETS" << "(";
	if( m_Material ) { stream << "#" << m_Material->m_entity_id; } else { stream << "$"; }
	stream << ",";
	if( m_LayerThickness ) { m_LayerThickness->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_IsVentilated ) { m_IsVentilated->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Priority ) { m_Priority->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_OffsetDirection ) { m_OffsetDirection->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeTypeOfRealList( stream, m_OffsetValues, false );
	stream << ");";
}
void IfcMaterialLayerWithOffsets::getStepParameter( std::stringstream& stream, bool /*is_select_type*/ ) const { stream << "#" << m_entity_id; }
const std::wstring IfcMaterialLayerWithOffsets::toString() const { return L"IfcMaterialLayerWithOffsets"; }
void IfcMaterialLayerWithOffsets::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<BuildingEntity> >& map )
{
	const size_t num_args = args.size();
	if( num_args != 9 ){ std::stringstream err; err << "Wrong parameter count for entity IfcMaterialLayerWithOffsets, expecting 9, having " << num_args << ". Entity ID: " << m_entity_id << std::endl; throw BuildingException( err.str().c_str() ); }
	readEntityReference( args[0], m_Material, map );
	m_LayerThickness = IfcNonNegativeLengthMeasure::createObjectFromSTEP( args[1], map );
	m_IsVentilated = IfcLogical::createObjectFromSTEP( args[2], map );
	m_Name = IfcLabel::createObjectFromSTEP( args[3], map );
	m_Description = IfcText::createObjectFromSTEP( args[4], map );
	m_Category = IfcLabel::createObjectFromSTEP( args[5], map );
	m_Priority = IfcInteger::createObjectFromSTEP( args[6], map );
	m_OffsetDirection = IfcLayerSetDirectionEnum::createObjectFromSTEP( args[7], map );
	readTypeOfRealList( args[8], m_OffsetValues );
}
void IfcMaterialLayerWithOffsets::getAttributes( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes ) const
{
	IfcMaterialLayer::getAttributes( vec_attributes );
	vec_attributes.emplace_back( std::make_pair( "OffsetDirection", m_OffsetDirection ) );
	if( !m_OffsetValues.empty() )
	{
		shared_ptr<AttributeObjectVector> OffsetValues_vec_object( new AttributeObjectVector() );
		std::copy( m_OffsetValues.begin(), m_OffsetValues.end(), std::back_inserter( OffsetValues_vec_object->m_vec ) );
		vec_attributes.emplace_back( std::make_pair( "OffsetValues", OffsetValues_vec_object ) );
	}
}
void IfcMaterialLayerWithOffsets::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<BuildingObject> > >& vec_attributes_inverse ) const
{
	IfcMaterialLayer::getAttributesInverse( vec_attributes_inverse );
}
void IfcMaterialLayerWithOffsets::setInverseCounterparts( shared_ptr<BuildingEntity> ptr_self_entity )
{
	IfcMaterialLayer::setInverseCounterparts( ptr_self_entity );
}
void IfcMaterialLayerWithOffsets::unlinkFromInverseCounterparts()
{
	IfcMaterialLayer::unlinkFromInverseCounterparts();
}

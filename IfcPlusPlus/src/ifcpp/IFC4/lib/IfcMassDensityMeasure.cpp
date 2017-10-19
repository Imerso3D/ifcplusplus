/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/IFC4/include/IfcDerivedMeasureValue.h"
#include "ifcpp/IFC4/include/IfcMassDensityMeasure.h"

// TYPE IfcMassDensityMeasure = REAL;
IfcMassDensityMeasure::IfcMassDensityMeasure() {}
IfcMassDensityMeasure::IfcMassDensityMeasure( double value ) { m_value = value; }
IfcMassDensityMeasure::~IfcMassDensityMeasure() {}
shared_ptr<IfcPPObject> IfcMassDensityMeasure::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcMassDensityMeasure> copy_self( new IfcMassDensityMeasure() );
	copy_self->m_value = m_value;
	return copy_self;
}
void IfcMassDensityMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCMASSDENSITYMEASURE("; }
	stream << m_value;
	if( is_select_type ) { stream << ")"; }
}
const std::wstring IfcMassDensityMeasure::toString() const
{
	std::wstringstream strs;
	strs << m_value;
	return strs.str();
}
shared_ptr<IfcMassDensityMeasure> IfcMassDensityMeasure::createObjectFromSTEP( const std::wstring& arg, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcMassDensityMeasure>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcMassDensityMeasure>(); }
	shared_ptr<IfcMassDensityMeasure> type_object( new IfcMassDensityMeasure() );
	readReal( arg, type_object->m_value );
	return type_object;
}
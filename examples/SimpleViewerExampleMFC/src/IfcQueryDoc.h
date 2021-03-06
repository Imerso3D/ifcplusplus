// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// IfcQueryMFCDoc.h : interface of the CIfcQueryMFCDoc class
//


#pragma once

#include <ifcpp/model/BasicTypes.h>
#include <ifcpp/model/StatusCallback.h>
#include <Inventor/SbColor.h>
#include "SceneGraph/SoPtr.h"
#include "SceneGraph/SceneGraphUtils.h"

class SoMaterial;
class SoSeparator;
class SoSelection;
class GeometryConverter;
class ConverterCarve2Coin3D;
class ReaderSTEP;
class WriterSTEP;
class BuildingModel;

class IfcQueryDoc : public CDocument
{
protected: // create from serialization only
	IfcQueryDoc();
	DECLARE_DYNCREATE( IfcQueryDoc )

public:
	// Attributes
	SoPtr<SoSeparator> m_root_node;
	SoPtr<SoSelection> m_model_node;
	shared_ptr<BuildingModel> m_ifc_model;
	shared_ptr<GeometryConverter> m_geometry_converter;
	shared_ptr<ReaderSTEP> m_reader_step;
	shared_ptr<WriterSTEP> m_writer_step;
	shared_ptr<StatusCallback> m_doc_message_target;
	shared_ptr<ConverterCarve2Coin3D> m_converter_coin;
	SoPtr<SoMaterial> m_material_selection;

	// Overrides
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument( LPCTSTR lpszPathName );
	virtual void Serialize(CArchive& ar);
	virtual void AddView( CView* pView );
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// Implementation
	virtual ~IfcQueryDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void loadFile( std::wstring& file );
	
	void OnStatusMessage( const shared_ptr<StatusCallback::Message>& m );
	void initSceneGraph();

	std::vector<shared_ptr<SceneGraphUtils::SelectionContainer> > m_vec_selected_nodes;
	void unselectAllNodes();

// Generated message map functions
protected:
	afx_msg int OnDocumentLoadingDone();
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

};

//
// Copyright (C) undoIt 
// 
// File: pluginMain.cpp
//
// Author: Maya Plug-in Wizard 2.0
//
#include "mergeVtx.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
//
//	Description:
//		this method is called when the plug-in is loaded into Maya.  It 
//		registers all of the services that this plug-in provides with 
//		Maya.
//
//	Arguments:
//		obj - a handle to the plug-in object (use MFnPlugin to access it)
//
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "mergeVtx", "2017", "Any");
	plugin.registerCommand("mergeVtx", mergeVtx::creator,mergeVtx::newSyntax);
	// Add plug-in feature registration here
	//

	return status;
}

MStatus uninitializePlugin( MObject obj )
//
//	Description:
//		this method is called when the plug-in is unloaded from Maya. It 
//		deregisters all of the services that it was providing.
//
//	Arguments:
//		obj - a handle to the plug-in object (use MFnPlugin to access it)
//
{
	MStatus   status;
	MFnPlugin plugin( obj );

	// Add plug-in feature deregistration here
	//
	plugin.deregisterCommand("mergeVtx");
	return status;
}

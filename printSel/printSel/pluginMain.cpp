#include "printSel.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )

{ 
	MStatus   status;
	MFnPlugin plugin( obj, "printSel", "2017", "Any");

	// Add plug-in feature registration here
	//
	plugin.registerCommand("printSel", printSel::creator);
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
	plugin.deregisterCommand("printSel");
	return status;
}

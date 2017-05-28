#include "HelloCmd.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{ 
	MStatus   status;
	MFnPlugin plugin( obj, "HelloCmd", "2017", "Any");
	plugin.registerCommand("HelloCmd",helloCmd::creator);

	return status;
}

MStatus uninitializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj );
	plugin.deregisterCommand("HelloCmd");

	return status;
}

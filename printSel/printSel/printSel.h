#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MSelectionList.h>
#include <maya/MDagPath.h>
#include <maya/MItSelectionList.h>

class printSel: public MPxCommand
{
public:
	printSel();
	virtual ~printSel();
	virtual MStatus doIt(const MArgList &args);
	static void* creator();
};
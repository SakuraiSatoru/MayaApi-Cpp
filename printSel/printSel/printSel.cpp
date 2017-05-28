#include "printSel.h"

printSel :: printSel()
{
	
}

printSel :: ~printSel()
{
	
}

MStatus printSel :: doIt(const MArgList& args)
{
	MStatus status;
	MSelectionList selList;
	MGlobal :: getActiveSelectionList(selList);
	MDagPath path;
	

	//way 1
	MGlobal::displayInfo("using way1");
	for(int i = 0;i < selList.length(); i++){
		selList.getDagPath(i,path);
		MGlobal::displayInfo(path.fullPathName());
	}

	//way2
	MGlobal::displayInfo("using way2");
	MItSelectionList selIter(selList);//can apply filter
	for(; !selIter.isDone();selIter.next()){
		selIter.getDagPath(path);
		MGlobal::displayInfo(path.fullPathName());
	}


	return MS::kSuccess;
}

void* printSel::creator()
{
	return new printSel;
}
#include "HelloCmd.h"

helloCmd::helloCmd(){
	
}

helloCmd::~helloCmd(){
	
}

MStatus helloCmd::doIt(const MArgList &args){
	MStatus status;
	MGlobal::displayInfo("hello world!");
	return MS::kSuccess;
}

void* helloCmd::creator(){
	return new helloCmd();
}
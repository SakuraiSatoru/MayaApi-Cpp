#include "undoIt.h"
const char *toleranceFlag = "d";
const char *toleranceLongFlag = "dist";
commandPrint::commandPrint(){}
commandPrint::~commandPrint(){}

MSyntax commandPrint::newSyntax()
{
	MSyntax syntax;
	syntax.addFlag(toleranceFlag,toleranceLongFlag,MSyntax::kDouble);

	return syntax;
}


MStatus commandPrint::doIt(const MArgList& args)
{
	MStatus status;
	MGlobal::displayInfo("doIt");
	MGlobal :: getActiveSelectionList(selList);
	MArgDatabase argData(syntax(),args);
	disFlag = 0.1;
	if(argData.isFlagSet(toleranceFlag)){
		argData.getFlagArgument(toleranceFlag,0,disFlag);
	}
	
	return redoIt();
}

MStatus commandPrint::redoIt()
{
	MStatus status;
	MGlobal::displayInfo("redoIt");
	
	
	//MFnMesh mesh;
	//std::string length = std::to_string(selList.length());
	MItSelectionList selIter(selList,MFn::kMeshVertComponent);
	
	/*std::string s = std::to_string(selList.length());
	char const *pchar = s.c_str();
	MGlobal::displayInfo(pchar);*/
	
	for(; !selIter.isDone();selIter.next()){
		selIter.getDagPath(path,comp);
		selIter.getDependNode(dNode);
		MFnMesh mesh(path.node());
		if(comp.isNull()){
			std::string str = "no component selected";
			char const *pchar2 = str.c_str();
			MGlobal::displayInfo(pchar2);
		}
		else{
			MItMeshVertex vertIt(path,comp);


			for(int i=0;!vertIt.isDone();vertIt.next(),i++){
				std::string s1 = std::to_string(i);
				std::string s2 = std::to_string(vertIt.count());
				s1 = s1+"/"+s2;
				char const *pchar1 = s1.c_str();
				
				MGlobal::displayInfo(pchar1);


				//vertIt.currentItem()
				MPoint vertPt(vertIt.position());
				oldPt.append(vertPt);
				for (int j=0;j<oldPt.length();j++){
					if(j<i){
						getDist(vertPt,oldPt[j]);
						if(disValue < disFlag){
							vertIt.setPosition(oldPt[j]);
							break;
						}else{continue;}
					}
					
				}
			}
		}
	}


	//commandPrint::undoIt();
	return MS::kSuccess;
}
MStatus commandPrint::undoIt()
{
	MStatus status;
	MGlobal::displayInfo("undoIt");
	MItMeshVertex vertIt(path,comp);
	for (int i = 0;!vertIt.isDone();vertIt.next(),i ++){
		vertIt.setPosition(oldPt[i]);
	}
	return MS::kSuccess;
}

bool commandPrint::isUndoable() const
{
	return true;
}

void* commandPrint::creator()
{
	return new commandPrint;
}

MStatus commandPrint::getDist(MPoint& p1,MPoint&  p2){
	MStatus status;
	MPoint disVector = p2 - p1;
	disValue = sqrt(pow(disVector.x,2)+pow(disVector.y,2)+pow(disVector.z,2));

	return MS::kSuccess;
}
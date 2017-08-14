#include<maya/MPxCommand.h>
#include<maya/MGlobal.h>
#include<maya/MFnMesh.h>
#include <maya/MItSelectionList.h>
#include <maya/MDagPath.h>
#include<string>  
#include<maya/MItMeshVertex.h>
#include<maya/MPointArray.h>
#include<maya/MSyntax.h>
#include<maya/MArgDatabase.h>


class mergeVtx :public MPxCommand
{
public:
	mergeVtx();
	virtual ~mergeVtx();

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual bool isUndoable() const;
	static void* creator();
	static MSyntax newSyntax();
private:
	MSelectionList selList;
	double disValue;
	double disFlag;
	MPointArray oldPt;
	MStatus getDist(MPoint& p1,MPoint&  p2);
	MDagPath path;
	MObject comp;
	MObject dNode;
};
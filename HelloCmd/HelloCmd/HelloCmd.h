#include<maya/MPxCommand.h>
#include<maya/MGlobal.h>
class helloCmd : public MPxCommand
{
public :
	helloCmd();
	virtual ~helloCmd();
	virtual MStatus doIt(const MArgList &args);
	static void* creator();
};

//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/uaf/UAF/src/cdx/cdxmapcell.cpp,v $
// $Author: cocoaspud $
//
// $Log: cdxmapcell.cpp,v $
// Revision 1.4  2001/10/13 15:19:59  cocoaspud
// Updates for MSVC ver 7 and other misc
//
// Revision 1.1.1.1  2000/04/22 16:10:39  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 2.1  1999/05/20 15:29:03  pietro
// Multiple changes:
// * fixed #include bugs in all .cpp and various .h files
// * fixed all rcsid[] bugs
// * added conditional compile variable CDXINCLUDEALL - when defined,
//   all #include files are included in cdx.h to keep backward compatibility
// * All the libraries are created in ..\..\lib\vc\ directory, library names are
//   cdx.lib/cdxd.lib/cdxdx3.lib/cdxdx3d.lib/cdxadx3.lib/cdxadx3d.lib
//
// Revision 2.0  1999/05/01 13:51:16  bsimser
// Updated revision number to 2.0
//
// Revision 1.1.1.1  1999/05/01 04:10:56  bsimser
// Initial revision to cvs
//
// $Revision: 1.4 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static char rcsid[] = "@(#) $Id: cdxmapcell.cpp,v 1.4 2001/10/13 15:19:59 cocoaspud Exp $";
#endif

#include "cdx.h"
#include "cdxmap.h"

//////////////////////////////////////////////////////////////////////////////////
// Default constructor. Just sets the TileNum to 0.
//////////////////////////////////////////////////////////////////////////////////
CDXMapCell::CDXMapCell()
{
	TileNum = 0;
}

//////////////////////////////////////////////////////////////////////////////////
// Default destructor.
//////////////////////////////////////////////////////////////////////////////////
CDXMapCell::~CDXMapCell()
{
}

//////////////////////////////////////////////////////////////////////////////////
// Default method of loading data from a file. Override this when using your
// own class.
//////////////////////////////////////////////////////////////////////////////////
void CDXMapCell::Load(FILE *fp)
{
	fread(&TileNum, sizeof(int), 1, fp);
}

//////////////////////////////////////////////////////////////////////////////////
// Default method of saving data to a file. Override this when using your
// own class.
//////////////////////////////////////////////////////////////////////////////////
void CDXMapCell::Save(FILE *fp)
{
	fwrite(&TileNum, sizeof(int), 1, fp);
}

//////////////////////////////////////////////////////////////////////////////////
// Default method to get the tile number. Override this when using your own class.
//////////////////////////////////////////////////////////////////////////////////
int CDXMapCell::GetTile()
{
	return TileNum;
}

//////////////////////////////////////////////////////////////////////////////////
// Default method to set the tile number. Override this when using your own class.
//////////////////////////////////////////////////////////////////////////////////
void CDXMapCell::SetTile(int Tile)
{
	TileNum = Tile;
}

/******************************************************************************
 Copyright 2012 Victor Yurkovsky

    This file is part of FPGAsm

    FPGAsm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FPGAsm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FPGAsm.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
/******************************************************************************
 A user-defined module
 
  PrimDef is the low-level building block of the FPGA. It exports names of pins
******************************************************************************/
#include "cProto.h"
class cModule;
// The proto has pins and parameter names! also * psubs
class cModule : public cProto{
public:
   cModule( char*name,int size);
  ~cModule();
  cSub* getSub(char*name);
 // virtual cProto** subs(); //return count of subs, see cDyn expansion
  void dump(FILE*f);
  //cCollection pins;  //from cProto
  virtual void verilog(FILE*f);
  void vlogWiring(FILE*f);
  void vlogAssignDest(FILE*fout,U32 pindex,U32 busid);
  void vlogAssignSrc(FILE*fout,U32 pindex,U32 busid);
// Data
};

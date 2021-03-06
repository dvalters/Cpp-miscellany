/* This is part of the netCDF package.
   Copyright 2006 University Corporation for Atmospheric Research/Unidata.
   See COPYRIGHT file for conditions of use.

   This is a very simple example which reads a 2D array of
   sample data produced by simple_xy_wr.cpp.

   This example is part of the netCDF tutorial:
   http://www.unidata.ucar.edu/software/netcdf/docs/netcdf-tutorial

   Full documentation of the netCDF C++ API can be found at:
   http://www.unidata.ucar.edu/software/netcdf/docs/netcdf-cxx

   $Id: simple_xy_rd.cpp,v 1.5 2010/02/11 22:36:43 russ Exp $
*/

#include <iostream>
#include <netcdf>
#include "TNT/tnt.h"

using namespace netCDF;
using namespace netCDF::exceptions;

// Return this in event of a problem.
static const int NC_ERR = 2;

//class LSDNetCDFTools
//{
//public:

/// @brief Reads in a netCDF field and writes it into
/// a TNT array 2D.
/// @return An error code, (0 for success, NC_ERR for failure)
template<typename T>
int read_tnt_array2d(TNT::Array2D<T> *tnt_array);

//};

template<typename T>
int read_tnt_array2d(TNT::Array2D<T> *tnt_array)
{
   int NX = tnt_array->dim1();
   int NY = tnt_array->dim2();

   std::cout << "Rows: " << NX << ", " << "Cols: " << NY << std::endl;

   try
   {
   // This is a C-style array.
   // We tend not to use these in LSDTopoTools
   // but typically used in netCDF.
   // int dataIn[NX][NY];

   // This is a TNT (Template Numerical Toolkit)
   // 2D array (allocated at runtime)
   //tnt_array(NX,NY,0);

   // Open the file for read access
   NcFile dataFile("simple_xy.nc", NcFile::read);

   // Retrieve the variable named "data"
   NcVar data = dataFile.getVar("data");
   if(data.isNull()) return NC_ERR;

   // Ingest the data into the array
   // We pass a reference to the first element of
   // the TNT array [0][0]. getVar writes in the values.
   data.getVar(tnt_array[0][0]);

   // Note: with a C-style array you would do this:
   // data.getVar(dataIn)
   // Since C arrays are already pointers to memory.

   // Check the values. 
//   for (int i = 0; i < NX; i++)
//   {
//      for (int j = 0; j < NY; j++)
//      {
//         // Check that we haven't gone out of bounds...
//         if (*tnt_array[i][j] != i * NY + j) return NC_ERR;
////         else
////         {
////           std::cout << *tnt_array[i][j] << " ";
////         }

//      }
//      //std::cout << std::endl;
//   }
   
   // The netCDF file is automatically closed by the NcFile destructor
   std::cout << "*** SUCCESS reading example file simple_xy.nc!" << std::endl;

   return 0;
   }
   catch(NcException& e)
   {
     e.what();
     std::cout<<"FAILURE*************************************"<< std::endl;
     return NC_ERR;
   }
}

int main()
{
  TNT::Array2D<int> myArray2D(6,12, 0);

  read_tnt_array2d(&myArray2D);

  for (int i = 0; i<6; i++)
  {
    for (int j = 0; j<12; j++)
    {
      //myArray2D[i][j] += 7;
      std::cout << myArray2D[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

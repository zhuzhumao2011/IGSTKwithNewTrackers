/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    igstkCommunication.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) ISIS Georgetown University. All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "igstkCommunication.h"

#include <iostream>

namespace igstk
{

Communication::Communication(void)
{
}

Communication::~Communication(void)
{
}

void Communication::OpenCommunication(const void * )
{
  std::cerr << "Communication::OpenCommunication() method is not implemented yet" << std::endl;
}

void Communication::CloseCommunication(void)
{
  std::cerr << "Communication::CloseCommunication() method is not implemented yet" << std::endl;
}

}


/*=========================================================================

  Program:   Image Guided Surgery Software Toolkit
  Module:    igstkImageSliceViewer.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) ISIS Georgetown University. All rights reserved.
  See IGSTKCopyright.txt or http://www.igstk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __igstk_ImageSliceViewer_h
#define __igstk_ImageSliceViewer_h


#include "vtkCamera.h"
#include "vtkRenderer.h"
#include "vtkImageActor.h"
#include "vtkRenderWindow.h"
#include "vtkCommand.h"
#include "vtkInteractorStyleImage.h"

#include "itkEventObject.h"
#include "itkCommand.h"

#include "igstkStateMachine.h"

namespace igstk
{

/** \class ImageSliceViewer
    \brief Implementation of viewing individual slices of a volume data

    This class implements viewing individual slices of a volume data.
    The input volume data has to be in vtkImageData format.

    Three orientations for viewing the slices are supported: Axial, Coronal
    and Saggital, which are user selectable. 
    
    \warning
	  \sa everyone needs to look at doxygen tags
*/

class ImageSliceViewer
{
private:

  typedef igstk::StateMachine< ImageSliceViewer, 2, 3 >   StateMachineType;

  typedef StateMachineType::TMemberFunctionPointer        ActionType;

  friend StateMachineType;

public:

  /** Type used to represent orientation of volume being viewed. */
  typedef enum
    { 
    Saggital = 0, 
    Coronal, 
    Axial 
    } 
    OrientationType;

  /** Constructor. It initializes vtk objects and forms the visualization 
    * pipeline. */
  ImageSliceViewer( void );

  /** Destructor */
  virtual ~ImageSliceViewer( void );

  // Public methods that DO NOT GENERATE input signals

  virtual void SetInteractor( vtkRenderWindowInteractor * interactor );

  void Render( void );

  unsigned long AddObserver( const itk::EventObject & event, itk::Command *);

  // Public methods that GENERATE INPUT signals

  /** SetInput: This method inputs the image data to the viewer. 
  *   It generates "InputData" input signal, and calls for a State
  *   Transition. */ 
  void SetInput( vtkImageData * image );

  /** SelectSlice: This method inputs the slice number to be viewed
  *   by the viewer. It generates "SetSlice" input signal, and calls 
  *   for a State Transition. */
  void SelectSlice( const int slice );

  /** SetZoomFactor: This method inputs the zoom factor for the viewer.
  *   It generates "SetupCamera" input signal, and calls for a State 
  *   Transition. */
  void SetZoomFactor( const double factor );

  /** SetOrientation: This method inputs the viewing orientation of the 
  *   image. It generates "SetupCamera" input signal, and calls for a State 
  *   Transition. */
  void SetOrientation( const OrientationType orientation );

 /** SelectPoint: This method inputs co-ordinate of the clicked point
  *   in the viewer. It generates "SetPoint" input signal and calls for 
  *   a State Transition. */ 
  virtual void SelectPoint( int x, int y);

protected:

  // Protected methods that DO NOT GENERATE input signals
  vtkRenderer * GetRenderer( void );

  // Protected methods that GENERATE INPUT signals

  virtual void SelectPoint( float x, float y, float z );

  virtual void  GetSelectPoint(float data[3]); 

  // Protected methods that are invoked through State Machine.


  /** SetupCamera: This method is invoked by the State Machine in response  
  *   to the "SetupCamera" input signal. */ 
  void SetupCamera( void );

  /** SetSlice: This method is invoked by the State Machine in response to 
  *   the "SetSlice" input signal. Slice setting is done by setting the  
  *   display extent of the input image data. */ 
  void SetSlice( void );
   



private:

  vtkImageActor     * m_Actor;

  vtkRenderer       * m_Renderer;

  vtkCamera         * m_Camera;

  vtkRenderWindow   * m_RenderWindow;

  OrientationType     m_Orientation;

  int                 m_SliceNum;

  vtkCommand        * m_InteractorObserver;

  itk::Object::Pointer   m_Notifier;

  double              m_NearPlane;

  double              m_FarPlane;

  double              m_ZoomFactor;

  float               m_SelectPoint[3];

  float               m_ImagePixelSpacing[3];

  float               m_ImageOrigin[3];

  int                 m_ImageDimensions[3];

  //int                 m_ImageExtents[6];

  StateMachineType    m_StateMachine;
};


}  // end namespace igstk

#endif




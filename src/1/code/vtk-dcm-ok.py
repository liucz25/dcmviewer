from vtk import *

# reader the dicom file
reader = vtkDICOMImageReader()
reader.SetDataByteOrderToLittleEndian()
reader.SetFileName("3.dcm")
reader.Update()

# show the dicom flie
imageViewer = vtkImageViewer2()
imageViewer.SetInputConnection(reader.GetOutputPort())
renderWindowInteractor = vtkRenderWindowInteractor()
imageViewer.SetupInteractor(renderWindowInteractor)
imageViewer.Render()
imageViewer.GetRenderer().ResetCamera()
imageViewer.Render()
renderWindowInteractor.Start()
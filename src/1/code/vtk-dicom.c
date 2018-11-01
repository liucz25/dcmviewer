int main()
{
    std::string folder = "digest_article";

    vtkSmartPointer<vtkDICOMImageReader> reader =
        vtkSmartPointer<vtkDICOMImageReader>::New();
    reader->SetDirectoryName(folder.c_str());
    reader->Update();

    vtkSmartPointer<vtkImageViewer2> imageViewer =
        vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(reader->GetOutputPort());

    vtkSmartPointer<vtkTextProperty> sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
    sliceTextProp->SetFontFamilyToCourier();
    sliceTextProp->SetFontSize(20);
    sliceTextProp->SetVerticalJustificationToBottom();
    sliceTextProp->SetJustificationToLeft();

    vtkSmartPointer<vtkTextMapper> sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
    std::string msg = StatusMessage::Format(imageViewer->GetSliceMin(), imageViewer->GetSliceMax());
    sliceTextMapper->SetInput(msg.c_str());
    sliceTextMapper->SetTextProperty(sliceTextProp);

    vtkSmartPointer<vtkActor2D> sliceTextActor = vtkSmartPointer<vtkActor2D>::New();
    sliceTextActor->SetMapper(sliceTextMapper);
    sliceTextActor->SetPosition(15, 10);

    vtkSmartPointer<vtkTextProperty> usageTextProp = vtkSmartPointer<vtkTextProperty>::New();
    usageTextProp->SetFontFamilyToCourier();
    usageTextProp->SetFontSize(14);
    usageTextProp->SetVerticalJustificationToTop();
    usageTextProp->SetJustificationToLeft();

    vtkSmartPointer<vtkTextMapper> usageTextMapper = vtkSmartPointer<vtkTextMapper>::New();
    usageTextMapper->SetInput("- Slice with mouse wheel\n  or Up/Down-Key\n- Zoom with pressed right\n  mouse button while dragging");
    usageTextMapper->SetTextProperty(usageTextProp);

    vtkSmartPointer<vtkActor2D> usageTextActor = vtkSmartPointer<vtkActor2D>::New();
    usageTextActor->SetMapper(usageTextMapper);
    usageTextActor->GetPositionCoordinate()->SetCoordinateSystemToNormalizedDisplay();
    usageTextActor->GetPositionCoordinate()->SetValue(0.05, 0.95);

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();

    vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle =
        vtkSmartPointer<myVtkInteractorStyleImage>::New();

    myInteractorStyle->SetImageViewer(imageViewer);
    myInteractorStyle->SetStatusMapper(sliceTextMapper);

    imageViewer->SetupInteractor(renderWindowInteractor);
    renderWindowInteractor->SetInteractorStyle(myInteractorStyle);
    imageViewer->GetRenderer()->AddActor2D(sliceTextActor);
    imageViewer->GetRenderer()->AddActor2D(usageTextActor);

    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();
    renderWindowInteractor->Start();
    return 0;
}
--------------------- 
作者：挥剑段天涯 
来源：CSDN 
原文：https://blog.csdn.net/u012176176/article/details/51259216 
版权声明：本文为博主原创文章，转载请附上博文链接！
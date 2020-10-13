#include "ImageRenderer.h"
#include "dxlib/DxLib.h"

ImageRenderer::ImageRenderer() :
    position(0.0f, 0.0f), rotate(0.0f), scale(0.0f, 0.0f), alpha(1.0f),
    transFlag(TRUE), turnFlag(FALSE), order(0)
{
}

ImageRenderer::~ImageRenderer()
{
}

void ImageRenderer::Draw()
{
    DrawRotaGraph3(0, 0, 0, 0, 1.0, 1.0, 0.0, image.handle, TRUE);
}

bool ImageRenderer::SetImage(const std::string& _filePass)
{
    return image.Load(_filePass);
}

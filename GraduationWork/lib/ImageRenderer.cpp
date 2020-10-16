#include "ImageRenderer.h"
#include "UrLib.h"

ImageRenderer::ImageRenderer() :
    position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f), alpha(1.0f),
    transFlag(TRUE), turnFlag(FALSE), order(0)
{
}

ImageRenderer::~ImageRenderer()
{
}

void ImageRenderer::Draw()
{
    if (image.handle == -1) 
        return;

    LoopClamp(rotation, 0.0f, 360.0f);

    int x = static_cast<int>(transform->position.x + position.x);
    int y = static_cast<int>(transform->position.y + position.y);
    int cx = image.sizeX / 2;
    int cy = image.sizeY / 2;
    float Angle = ToRadian(rotation);

    DrawRotaGraph3(x, y, cx, cy, scale.x, scale.y, Angle, image.handle, transFlag, turnFlag);
}

bool ImageRenderer::SetImage(const std::string& _filePass)
{
    return image.Load(_filePass);
}

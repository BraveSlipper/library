#include "ImageRenderer.h"
#include "UrLib.h"

ImageRenderer::ImageRenderer() :
    position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f), alpha(1.0f),
    transFlag(TRUE), turnFlag(FALSE), order(0), drawNum(0u)
{
}

ImageRenderer::~ImageRenderer()
{
}

void ImageRenderer::Draw()
{
    if (image.imageInfo == nullptr)return;

    LoopClamp(rotation, 0.0f, 360.0f);

    int x = static_cast<int>(transform->position.x + position.x);
    int y = static_cast<int>(transform->position.y + position.y);
    int cx = image.imageInfo->sizeX / 2;
    int cy = image.imageInfo->sizeY / 2;
    float Angle = ToRadian(rotation);

    DrawRotaGraph3(x, y, cx, cy, scale.x, scale.y, Angle, image.imageInfo->handles[drawNum], transFlag, turnFlag);
}

bool ImageRenderer::SetImage(const std::string& _filePass)
{
    return image.Load(_filePass);
}

bool ImageRenderer::SetImageDiv(const std::string& _filePass, unsigned _xdiv, unsigned _ydiv, unsigned _allnum)
{
    return image.LoadDiv(_filePass, _xdiv, _ydiv, _allnum);
}

bool ImageRenderer::SetImageNumber(unsigned _num)
{
    if (image.imageInfo == nullptr)return false;

    if (static_cast<size_t>(_num) < image.imageInfo->handles.size())
    {
        drawNum = _num;
        return true;
    }
    return false;
}

unsigned ImageRenderer::GetDrawMaxNumber() const
{
    return (image.imageInfo == nullptr) ? 0u : static_cast<unsigned>(image.imageInfo->handles.size());
}

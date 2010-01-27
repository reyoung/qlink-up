#include <irrlicht.h>
#include <QtCore>
using namespace irr;
using namespace core;
using namespace video;
using namespace io;
using namespace gui;
int main()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    IrrlichtDevice* device =
            createDevice(video::EDT_OPENGL,dimension2d<u32>(800,600),32,true,false,false,0);
    device->setWindowCaption(QObject::tr("ÄãºÃ£¬ÊÀ½ç").toStdWString().c_str());
    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guiEnv = device->getGUIEnvironment();
    IAnimatedMesh* mesh = smgr->getMesh("sydney.md2");
    if (!mesh)
    {
            device->drop();
            return 1;
    }
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
    if (node)
    {
            node->setMaterialFlag(EMF_LIGHTING, false);
            node->setMD2Animation(scene::EMAT_STAND);
            node->setMaterialTexture( 0, driver->getTexture("sydney.bmp") );
    }

}

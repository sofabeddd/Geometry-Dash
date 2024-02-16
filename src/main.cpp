#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GeometryDash, MenuLayer) {
public:
    void geometryDash(CCObject* sender) {
        if (auto button = typeinfo_cast<CCMenuItemSpriteExtra*>(sender)) {
            FMODAudioEngine::sharedEngine()->playEffect("geometry-dash.ogg"_spr, 1.f, 1.f, 1.f);
        }
    }

    bool init() {
        if (!MenuLayer::init()) return false;

        CCNode* mainTitleNode = getChildByID("main-title");

        removeChildByID("main-title");

        auto titleMenu = CCMenu::create();
        titleMenu->setContentSize(CCSize { 429.f, 52.f });
        titleMenu->setPosition(getChildByID("main-menu")->boundingBox().origin.x, 270 - 26);

        auto titleMenuItem = CCMenuItemSpriteExtra::create(mainTitleNode, this, menu_selector(GeometryDash::geometryDash));
        titleMenuItem->setPosition(214.5, 26.f);

        titleMenu->addChild(titleMenuItem);
        addChild(titleMenu);

        return true;
    }
};

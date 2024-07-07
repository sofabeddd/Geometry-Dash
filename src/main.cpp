#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GeometryDashMenuLayer, MenuLayer) {
public:
    static void onModify(auto& self) {
        (void) self.setHookPriority("MenuLayer::init", -10000);
    }

    void onMainTitle(CCObject* sender) {
        if (typeinfo_cast<CCMenuItemSpriteExtra*>(sender)) {
            FMODAudioEngine::sharedEngine()->playEffect("geometry-dash.ogg"_spr, 1.f, 1.f, 1.f);
        }
    }

    bool init() {
        if (!MenuLayer::init()) return false;

        auto main_title = getChildByID("main-title");
        main_title->removeFromParent();

        auto main_title_menu = CCMenu::create();

        main_title_menu->setID("main-title-menu"_spr);
        main_title_menu->updateLayout();
        main_title_menu->setPosition(main_title->boundingBox().origin);

        auto title_menu_button = CCMenuItemSpriteExtra::create(main_title, this, menu_selector(GeometryDashMenuLayer::onMainTitle));
        title_menu_button->setPosition(main_title->getPosition());
        title_menu_button->setID("main-title");

        main_title_menu->addChild(title_menu_button);
        addChild(main_title_menu);

        return true;
    }
};

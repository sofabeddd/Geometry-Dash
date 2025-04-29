#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GeometryDashMenuLayer, MenuLayer) {
    static void onModify(auto& self) {
        if (Loader::get()->isModLoaded("flingus.geometry_pride")) (void) self.setHookPriorityAfterPost("MenuLayer::init", "flingus.geometry_pride");
        else (void) self.setHookPriority("MenuLayer::init", -3998);
    }

    void onMainTitle(CCObject* sender) {
        if (!sender || !typeinfo_cast<CCMenuItemSpriteExtra*>(sender)) return;
        FMODAudioEngine::sharedEngine()->playEffect("geometry-dash.ogg"_spr, 1.f, 1.f, 1.f);
    }

    bool init() {
        if (!MenuLayer::init()) return false;

        auto main_title = getChildByID("main-title");
        if (!main_title) return true;
        
        main_title->removeFromParent();

        auto main_title_menu = CCMenu::create();

        main_title_menu->setID("main-title-menu"_spr);
        main_title_menu->setPosition(main_title->boundingBox().origin);

        auto title_menu_button = CCMenuItemSpriteExtra::create(main_title, this, menu_selector(GeometryDashMenuLayer::onMainTitle));
        title_menu_button->setPosition(main_title->getPosition());
        title_menu_button->setID("main-title");

        main_title_menu->addChild(title_menu_button);
        addChild(main_title_menu);

        return true;
    }
};
#pragma once

namespace thuw::Scene::Concept {

    template<class SceneClass>
    concept Scene = requires(SceneClass scene) {
        scene.name();
        scene.setup();
        scene.update();
    };

    template<class SceneClass>
    concept ScenePointer = requires(SceneClass* scene) {
        scene->name();
        scene->setup();
        scene->update();
    };

    template<class ...SceneClass>
    concept ScenePack = requires(SceneClass ...scene) {
        (scene.name(), ...);
        (scene.setup(), ...);
        (scene.update(), ...);
    };

    template<class ...SceneClass>
    concept ScenePointerPack = requires(SceneClass* ...scene) {
        (scene->name(), ...);
        (scene->setup(), ...);
        (scene->update(), ...);
    };
}
// #pragma once
// #include "thuw/Scene/Scene.hpp"
// #include <cassert>
// #include <functional>
// #include <initializer_list>
// #include <string>
// #include <utility>
// #include <memory>
// #include <unordered_map>

// namespace thuw::Scene {
//     template<class ...SceneClass>
//     class List;
// }

// // VO
// template<class ...SceneClass>
// class thuw::Scene::List {
// public:
//     const std::unordered_map<std::string, thuw::Scene::Interface*> sceneMap;

//     List(SceneClass&& ...scene) : sceneMap({{scene->Name, scene} ... }) {}

//     template<typename SceneName>
//     [[nodiscard]] auto operator[](SceneName&& name) const {
//         assert(List::sceneMap.contains(name));

//         return List::sceneMap.at(name);
//     }
// };
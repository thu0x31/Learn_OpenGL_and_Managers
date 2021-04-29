// #pragma once

// #include "thuw/Scene/List.hpp"
// #include <memory>

// namespace thuw::Scene {
//     template<SceneConcept ...SceneClass>
//     class Initilizer;
// }

// template<SceneConcept ...SceneClass>
// class thuw::Scene::Initilizer {
// public:
//     Initilizer() {}

//     auto list() const {
//         return thuw::Scene::List<SceneClass...>({
//             std::make_shared<SceneClass>()...
//         });
//     }
// };
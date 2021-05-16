// #pragma once
// #include "Scene.hpp"
// #include "thuw/Signal/Signal.hpp"
// #include <GLFW/glfw3.h>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <memory>
// #include <ostream>
// #include <string>
// #include <unordered_map>

// namespace thuw::Scene {

//     // TODO: multi Window

//     class Transitioner;

//     template<typename SceneName>
//     void Transition(SceneName&& sceneName);
// }

// class thuw::Scene::Transitioner {
// public:
//     using Connection = thuw::Signal<void()>;

//     // Scene from;
//     // Scene to;

//     Transitioner() = default;

//     template<class Function>
//     Connection transitioned() {

//     }

// public:
//     static inline std::string ToSceneName = "";

//     template<typename SceneName>
//     static inline void Transition(SceneName&& sceneName) {
//         // TODO: prototype
//         Scene::Transitioner::ToSceneName = sceneName;
//     }

//     static inline bool WantTransition() {
//         // TODO: prototype
//         return Scene::Transitioner::ToSceneName.empty() == false;
//     }

//     static inline std::string ToName() {
//         return Scene::Transitioner::ToSceneName;
//     }

//     static inline void resetToName() {
//         ToSceneName = "";
//     }
// };

// template<typename SceneName>
// void thuw::Scene::Transition(SceneName&& sceneName) {
//     // TODO: prototype
//     Scene::Transitioner::ToSceneName = sceneName;
// }
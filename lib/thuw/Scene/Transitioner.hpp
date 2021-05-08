#pragma once
#include "Scene.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

namespace thuw::Scene {
    template<class ScenePtr, class SceneList>
    void Transition(ScenePtr scene, SceneList& list, const std::string& name);// slot
}
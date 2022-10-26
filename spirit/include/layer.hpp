#pragma once

#include "core/base.hpp"
#include "events/event.hpp"

namespace Spirit {
       class SPIRIT_API Layer {
       public:
               Layer(const std::string& name = "Layer");
               virtual ~Layer();

               virtual void OnAttach() {}
               virtual void OnDetach() {}
               virtual void OnUpdate() {}
               virtual void OnEvent(Event& event) {}

               inline const std::string& getName() const { return m_DebugName; }
       protected:
               std::string m_DebugName;
       };
}

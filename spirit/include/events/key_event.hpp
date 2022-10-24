#pragma once

#include "events/event.hpp"
#include "core/keycodes.hpp"

namespace Spirit {
	class KeyEvent : public Event {
		public:
			KeyCode getKeyCode() const { return m_KeyCode; }

			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
		protected:
				KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {}
				KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent {
		public:
			KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
				: KeyEvent(keycode), m_isRepeat(isRepeat) {}

			bool isRepeat() const { return m_isRepeat; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_isRepeat << ")";
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyPressed)
		private:
				bool m_isRepeat;
	};

	class KeyReleasedEvent : public KeyEvent {
		public:
			KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "KeyReleasedEvent: " << m_KeyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent {
		public:
			KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "KeyTypedEvent: " << m_KeyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyTyped)
	};
}

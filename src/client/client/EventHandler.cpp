#include "EventHandler.hpp"

namespace client {

    EventHandler::EventHandler() = default;

    EventHandler& EventHandler::getInstance() {
        static EventHandler instance;
        return instance;
    }
}
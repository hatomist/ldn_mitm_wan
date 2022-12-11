#pragma once

#include <switch.h>
#include <stratosphere.hpp>
#include "interfaces/iconfig.hpp"

namespace ams::mitm::ldn {

    class LdnConfig {
        public:
            static bool getEnabled() {
                return LdnEnabled;
            }
            static bool getWANEnabled() {
                return WANEnabled;
            }
            static const char *getHostname() {
                return Hostname;
            }
            static const char *getRoom() {
                return Room;
            }
        protected:
            static std::atomic_bool          LdnEnabled;
            static std::atomic_bool          WANEnabled;
            static std::atomic<const char *> Hostname;
            static std::atomic<const char *> Room;
        public:

            Result GetVersion(sf::Out<LdnMitmVersion> version);
            Result GetLogging(sf::Out<u32> enabled);
            Result SetLogging(u32 enabled);
            Result GetEnabled(sf::Out<u32> enabled);
            Result SetEnabled(u32 enabled);
            Result GetWANEnabled(sf::Out<u32> enabled);
            Result SetWANEnabled(u32 enabled);
            Result GetHostname(sf::Out<LdnWANHostname> hostname);
            Result SetHostname(LdnWANHostname hostname);
            Result GetRoom(sf::Out<LdnWANRoom> room);
            Result SetRoom(LdnWANRoom room);
    };
    static_assert(ams::mitm::ldn::IsILdnConfig<LdnConfig>);

}

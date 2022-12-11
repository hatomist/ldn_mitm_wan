#include <cstring>
#include "ldnmitm_config.hpp"
#include "debug.hpp"

namespace ams::mitm::ldn {
    std::atomic_bool          LdnConfig::LdnEnabled = true;
    std::atomic_bool          LdnConfig::WANEnabled = true;
    std::atomic<const char *> LdnConfig::Hostname   = "ldn.hatomist.pw";
    std::atomic<const char *> LdnConfig::Room       = "general";

    Result LdnConfig::GetVersion(sf::Out<LdnMitmVersion> version) {
        std::strcpy(version.GetPointer()->raw, GITDESCVER);
        
        R_SUCCEED();
    }
    Result LdnConfig::GetLogging(sf::Out<u32> enabled) {
        return ::GetLogging(enabled.GetPointer());
    }
    Result LdnConfig::SetLogging(u32 enabled) {
        return ::SetLogging(enabled);
    }
    Result LdnConfig::GetEnabled(sf::Out<u32> enabled) {
        enabled.SetValue(LdnEnabled);
        
        R_SUCCEED();
    }
    Result LdnConfig::SetEnabled(u32 enabled) {
        LdnEnabled = enabled;
        
        R_SUCCEED();
    }
    Result LdnConfig::GetWANEnabled(sf::Out<u32> enabled) {
        enabled.SetValue(WANEnabled);

        R_SUCCEED();
    }
    Result LdnConfig::SetWANEnabled(u32 enabled) {
        WANEnabled = enabled;

        R_SUCCEED();
    }
    Result LdnConfig::GetHostname(sf::Out<LdnWANHostname> hostname) {
        std::strcpy(hostname.GetPointer()->raw, Hostname);

        R_SUCCEED();
    }
    Result LdnConfig::SetHostname(LdnWANHostname hostname) {
        Hostname = hostname.raw;
        R_SUCCEED();
    }
    Result LdnConfig::GetRoom(sf::Out<LdnWANRoom> room) {
      std::strcpy(room.GetPointer()->raw, Room);

      R_SUCCEED();
    }
    Result LdnConfig::SetRoom(LdnWANRoom room) {
        Room = room.raw;
        R_SUCCEED();
    }
}

#pragma once
#include <stratosphere.hpp>

namespace ams::mitm::ldn {

    struct LdnMitmVersion {
        char raw[32];
    };

    struct LdnWANHostname {
        char raw[256];
    };

    struct LdnWANRoom {
        char raw[256];
    };
}

#define AMS_LDN_CONFIG(C, H)															\
    AMS_SF_METHOD_INFO(C, H, 65001, Result, GetVersion,		(ams::sf::Out<ams::mitm::ldn::LdnMitmVersion> version),		(version))	\
    AMS_SF_METHOD_INFO(C, H, 65002, Result, GetLogging,		(ams::sf::Out<u32> enabled),					(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65003, Result, SetLogging,		(u32 enabled), 							(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65004, Result, GetEnabled,		(ams::sf::Out<u32> enabled),					(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65005, Result, SetEnabled,		(u32 enabled),							(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65101, Result, GetWANEnabled,	(ams::sf::Out<u32> enabled),					(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65102, Result, SetWANEnabled,	(u32 enabled),							(enabled))	\
    AMS_SF_METHOD_INFO(C, H, 65103, Result, GetHostname,	(ams::sf::Out<ams::mitm::ldn::LdnWANHostname> hostname),	(hostname))	\
    AMS_SF_METHOD_INFO(C, H, 65104, Result, SetHostname,	(ams::mitm::ldn::LdnWANHostname hostname),			(hostname))	\
    AMS_SF_METHOD_INFO(C, H, 65105, Result, GetRoom,		(ams::sf::Out<ams::mitm::ldn::LdnWANRoom> room),		(room))		\
    AMS_SF_METHOD_INFO(C, H, 65106, Result, SetRoom,		(ams::mitm::ldn::LdnWANRoom room),				(room))		\

    AMS_SF_DEFINE_INTERFACE(ams::mitm::ldn, ILdnConfig, AMS_LDN_CONFIG, 0x14c8af2c)

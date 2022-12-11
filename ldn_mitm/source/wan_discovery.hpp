#pragma once
#include "lan_discovery.hpp"

namespace ams::mitm::ldn {
    class WANDiscovery: public LANDiscovery {
        public:
        protected:
        public:
            Result initialize(LanEventFunc lanEvent = EmptyFunc, bool listening = true) override;
            Result scan(NetworkInfo *networkInfo, u16 *count, ScanFilter filter) override;
            Result createNetwork(const SecurityConfig *securityConfig, const UserConfig *userConfig, const NetworkConfig *networkConfig) override;
            Result connect(const NetworkInfo *networkInfo, UserConfig *userConfig, u16 localCommunicationVersion) override;
    };
}

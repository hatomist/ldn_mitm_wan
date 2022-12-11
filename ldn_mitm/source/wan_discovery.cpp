#include "wan_discovery.hpp"

namespace ams::mitm::ldn {
    // TODO: instead of creating a listening TCP socket and perform accept() calls on client connect,
    // keep a TCP connection with a WANserver and when it receives a request from a client, server will create a new connection
    // with WANserver and WANserver will act as a bridge between client and server

    // TODO: initUdp would be unnecessary, instead maybe keep a tcp connection with server for discovery/server setup purposes
    Result WANDiscovery::initialize(LanEventFunc lanEvent, bool listening) {
        LogFormat("WANDiscovery::initialize stub called");
        return LANDiscovery::initialize(lanEvent, listening);
    }

    // TODO: CLIENT: instead of sending broadcast with udp and waiting for results,
    // make (blocking curl?) request to the WANserver and gather available servers
    // for given room, server needs to send some kind of ids instead of ip adresses and session id
    Result WANDiscovery::scan(NetworkInfo *networkInfo, u16 *count, ScanFilter filter) {
        LogFormat("WANDiscovery::scan stub called");
        return LANDiscovery::scan(networkInfo, count, filter);
    }

    // TODO: SERVER: connect to WANserver instead of creating a listening socket, and provide it with room ID and info about AP
    Result WANDiscovery::createNetwork(const SecurityConfig *securityConfig, const UserConfig *userConfig, const NetworkConfig *networkConfig) {
        LogFormat("WANDiscovery::createNetwork stub called");
        return LANDiscovery::createNetwork(securityConfig, userConfig, networkConfig);
    }

    // TODO: CLIENT: connect to the WANserver instead of given ip, send initial packet with session id and selected switch, then
    // Connect packet as usual. WANserver will act as a bridge between server and client socket.
    // STUN server can be used in future as an option to reduce latency, as it is now in Ryujinx
    Result WANDiscovery::connect(const NetworkInfo *networkInfo, UserConfig *userConfig, u16 localCommunicationVersion) {
        LogFormat("WANDiscovery::connect stub called");
        return LANDiscovery::connect(networkInfo, userConfig, localCommunicationVersion);
    }

}

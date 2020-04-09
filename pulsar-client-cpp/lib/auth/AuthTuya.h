//
// Created by wenxuwan on 2020/4/3.
//

#ifndef PULSAR_CPP_AUTHTUYA_H
#define PULSAR_CPP_AUTHTUYA_H

#include <pulsar/Authentication.h>
#include <string>
#include <boost/function.hpp>

namespace pulsar {

    const std::string TUYA_PLUGIN_NAME = "tuya";
    const std::string TUYA_JAVA_PLUGIN_NAME = "org.apache.pulsar.client.impl.auth.AuthenticationTuya";

    class AuthTuyaData : public AuthenticationDataProvider {
    public:
        AuthTuyaData(std::string data);
        ~AuthTuyaData();

        bool hasDataForHttp();
        std::string getHttpHeaders();
        bool hasDataFromCommand();
        std::string getCommandData();
    private:
    std::string commandData;
    };
}  // namespace pulsar

#endif //PULSAR_CPP_AUTHTUYA_H

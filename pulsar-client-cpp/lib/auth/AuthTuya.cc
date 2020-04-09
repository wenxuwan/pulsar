//
// Created by wenxuwan on 2020/4/3.
//

#include "AuthTuya.h"
#include <boost/algorithm/string/predicate.hpp>
#include <functional>

#include <sstream>
#include <fstream>

namespace pulsar {

    //AuthTuyaData
    AuthTuyaData::AuthTuyaData(std::string data){
        this->commandData = data;
    }

    AuthTuyaData::~AuthTuyaData() {}

    bool AuthTuyaData::hasDataForHttp() { return false; }

    std::string AuthTuyaData::getHttpHeaders() {return "";}

    bool AuthTuyaData::hasDataFromCommand() { return true; }

    std::string AuthTuyaData::getCommandData() {
        return this->commandData;
    }

    // AuthTuya

    AuthTuya::AuthTuya(AuthenticationDataPtr &authDataTuya) { authDataTuya_ = authDataTuya; }

    AuthTuya::~AuthTuya() {}
    AuthenticationPtr AuthTuya::create(const std::string&  params){
        AuthenticationDataPtr authDataTuya = AuthenticationDataPtr(new AuthTuyaData(params));
        return AuthenticationPtr(new AuthTuya(authDataTuya));
    }
    //TODO: add implementation
    AuthenticationPtr AuthTuya::create(ParamMap& params){
        return NULL;
    }
    const std::string AuthTuya::getAuthMethodName() const { return "auth1"; }

    Result AuthTuya::getAuthData(AuthenticationDataPtr &authDataContent) const {
        authDataContent = authDataTuya_;
        return ResultOk;
    }

}

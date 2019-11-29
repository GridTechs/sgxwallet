/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_
#define JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_

#include <jsonrpccpp/server.h>

class AbstractStubServer : public jsonrpc::AbstractServer<AbstractStubServer>
{
    public:
        AbstractStubServer(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<AbstractStubServer>(conn, type)
        {
          this->bindAndAddMethod(jsonrpc::Procedure("importBLSKeyShare", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,"keyShare",jsonrpc::JSON_STRING,"keyShareName",jsonrpc::JSON_STRING,"t",jsonrpc::JSON_INTEGER,"n",jsonrpc::JSON_INTEGER, "index",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::importBLSKeyShareI);
          this->bindAndAddMethod(jsonrpc::Procedure("blsSignMessageHash", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "keyShareName",jsonrpc::JSON_STRING,"messageHash",jsonrpc::JSON_STRING,"t",jsonrpc::JSON_INTEGER, "n",jsonrpc::JSON_INTEGER, "signerIndex",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::blsSignMessageHashI);

          this->bindAndAddMethod(jsonrpc::Procedure("importECDSAKey", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "key",jsonrpc::JSON_STRING,"keyName",jsonrpc::JSON_STRING, NULL), &AbstractStubServer::importECDSAKeyI);
          this->bindAndAddMethod(jsonrpc::Procedure("generateECDSAKey", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,  NULL), &AbstractStubServer::generateECDSAKeyI);
          this->bindAndAddMethod(jsonrpc::Procedure("renameECDSAKey", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "KeyName",jsonrpc::JSON_STRING,"tempKeyName",jsonrpc::JSON_STRING, NULL), &AbstractStubServer::renameECDSAKeyI);
          this->bindAndAddMethod(jsonrpc::Procedure("getPublicECDSAKey", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "keyName",jsonrpc::JSON_STRING, NULL), &AbstractStubServer::getPublicECDSAKeyI);
          this->bindAndAddMethod(jsonrpc::Procedure("ecdsaSignMessageHash", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "base",jsonrpc::JSON_INTEGER,"keyName",jsonrpc::JSON_STRING,"messageHash",jsonrpc::JSON_STRING, NULL), &AbstractStubServer::ecdsaSignMessageHashI);

          this->bindAndAddMethod(jsonrpc::Procedure("generateDKGPoly", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "polyName",jsonrpc::JSON_STRING,"t",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::generateDKGPolyI);
          this->bindAndAddMethod(jsonrpc::Procedure("getVerificationVector", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT,"polyName",jsonrpc::JSON_STRING, "t",jsonrpc::JSON_INTEGER,"t",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::getVerificationVectorI);
          this->bindAndAddMethod(jsonrpc::Procedure("getSecretShare", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "polyName",jsonrpc::JSON_STRING,"publicKeys",jsonrpc::JSON_ARRAY, "n",jsonrpc::JSON_INTEGER,"t",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::getSecretShareI);
          this->bindAndAddMethod(jsonrpc::Procedure("DKGVerification", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "publicShares",jsonrpc::JSON_STRING, "EthKeyName",jsonrpc::JSON_STRING, "SecretShare",jsonrpc::JSON_STRING,"t",jsonrpc::JSON_INTEGER, "n",jsonrpc::JSON_INTEGER, "index",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::DKGVerificationI);
          this->bindAndAddMethod(jsonrpc::Procedure("CreateBLSPrivateKey", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "BLSKeyName",jsonrpc::JSON_STRING, "EthKeyName",jsonrpc::JSON_STRING, "polyName", jsonrpc::JSON_STRING, "SecretShare",jsonrpc::JSON_STRING,"t", jsonrpc::JSON_INTEGER,"n",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::CreateBLSPrivateKeyI);
          this->bindAndAddMethod(jsonrpc::Procedure("GetBLSPublicKeyShare", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "BLSKeyName",jsonrpc::JSON_STRING, NULL), &AbstractStubServer::GetBLSPublicKeyShareI);
          this->bindAndAddMethod(jsonrpc::Procedure("ComplaintResponse", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "polyName",jsonrpc::JSON_STRING,"ind",jsonrpc::JSON_INTEGER, NULL), &AbstractStubServer::ComplaintResponseI);

        }

        inline virtual void importBLSKeyShareI(const Json::Value &request, Json::Value &response)
        {
            response = this->importBLSKeyShare( request["keyShare"].asString(), request["keyShareName"].asString(), request["t"].asInt(), request["n"].asInt(), request["index"].asInt());
        }
        inline virtual void blsSignMessageHashI(const Json::Value &request, Json::Value &response)
        {
            response = this->blsSignMessageHash(request["keyShareName"].asString(), request["messageHash"].asString(), request["t"].asInt(), request["n"].asInt(), request["signerIndex"].asInt());
        }
        inline virtual void importECDSAKeyI(const Json::Value &request, Json::Value &response)
        {
            response = this->importECDSAKey(request["key"].asString(), request["keyName"].asString());
        }
        inline virtual void generateECDSAKeyI(const Json::Value &request, Json::Value &response)
        {
          (void)request;
          response = this->generateECDSAKey();
        }
        inline virtual void renameECDSAKeyI(const Json::Value &request, Json::Value &response)
        {
          response = this->renameECDSAKey(request["KeyName"].asString(), request["tempKeyName"].asString());
        }
         inline virtual void getPublicECDSAKeyI(const Json::Value &request, Json::Value &response)
        {
            response = this->getPublicECDSAKey(request["keyName"].asString());
        }
        inline virtual void ecdsaSignMessageHashI(const Json::Value &request, Json::Value &response)
        {
            response = this->ecdsaSignMessageHash(request["base"].asInt(), request["keyName"].asString(), request["messageHash"].asString());
        }
        inline virtual void generateDKGPolyI(const Json::Value &request, Json::Value &response)
        {
            response = this->generateDKGPoly(request["polyName"].asString(), request["t"].asInt());
        }
        inline virtual void getVerificationVectorI(const Json::Value &request, Json::Value &response)
        {
            response = this->getVerificationVector(request["polyName"].asString(), request["t"].asInt(), request["n"].asInt());
        }
        inline virtual void getSecretShareI(const Json::Value &request, Json::Value &response)
        {
            response = this->getSecretShare(request["polyName"].asString(), request["publicKeys"], request["t"].asInt(),request["n"].asInt());
        }
        inline virtual void DKGVerificationI(const Json::Value &request, Json::Value &response)
        {
            response = this->DKGVerification(request["publicShares"].asString(), request["EthKeyName"].asString(), request["SecretShare"].asString(), request["t"].asInt(), request["n"].asInt(), request["index"].asInt());
        }
        inline virtual void CreateBLSPrivateKeyI(const Json::Value &request, Json::Value &response)
        {
            response = this->CreateBLSPrivateKey(request["BLSKeyName"].asString(), request["EthKeyName"].asString(), request["polyName"].asString(),request["SecretShare"].asString(),request["t"].asInt(), request["n"].asInt());
        }
        inline virtual void GetBLSPublicKeyShareI(const Json::Value &request, Json::Value &response)
        {
          response = this->GetBLSPublicKeyShare(request["BLSKeyName"].asString());
        }
        inline virtual void ComplaintResponseI(const Json::Value &request, Json::Value &response)
        {
          response = this->ComplaintResponse( request["polyName"].asString(), request["ind"].asInt());
        }

        virtual Json::Value importBLSKeyShare(const std::string& keyShare, const std::string& keyShareName, int t, int n, int index) = 0;
        virtual Json::Value blsSignMessageHash(const std::string& keyShareName, const std::string& messageHash, int t, int n, int signerIndex ) = 0;
        virtual Json::Value importECDSAKey(const std::string& key, const std::string& keyName) = 0;
        virtual Json::Value generateECDSAKey() = 0;
        virtual Json::Value renameECDSAKey(const std::string& KeyName, const std::string& tempKeyName) = 0;
        virtual Json::Value getPublicECDSAKey(const std::string& keyName) = 0;
        virtual Json::Value ecdsaSignMessageHash(int base, const std::string& keyName, const std::string& messageHash) = 0;

        virtual Json::Value generateDKGPoly(const std::string& polyName, int t) = 0;
        virtual Json::Value getVerificationVector(const std::string& polyName, int t, int n) = 0;
        virtual Json::Value getSecretShare(const std::string& polyName, const Json::Value& publicKeys, int t, int n) = 0;
        virtual Json::Value DKGVerification( const std::string& publicShares, const std::string& EthKeyName, const std::string& SecretShare, int t, int n, int index) = 0;
        virtual Json::Value CreateBLSPrivateKey(const std::string & BLSKeyName, const std::string& EthKeyName, const std::string& polyName, const std::string & SecretShare, int t, int n) = 0;
        virtual Json::Value GetBLSPublicKeyShare(const std::string & BLSKeyName) = 0;
        virtual Json::Value ComplaintResponse(const std::string& polyName, int ind) = 0;
};

#endif //JSONRPC_CPP_STUB_ABSTRACTSTUBSERVER_H_

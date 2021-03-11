#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <server/server_configuration_parser.h>

#include <typeinfo>

namespace ni {
namespace tests {
namespace unit {

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAddress_ReturnsDefaultLocalAddressAndPort)
{
  grpc::nidevice::ServerConfigurationParser server_config_parser;

  auto address = server_config_parser.parse_address();

  EXPECT_EQ(address, grpc::nidevice::kDefaultAddressPrefix + std::string("31763"));
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromPathToDefaultConfigFile_ParseAddress_NotEmpty)
{
  std::string config_file_path = grpc::nidevice::ServerConfigurationParser::get_exe_path() + "server_config.json";
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_file_path);

  auto address = server_config_parser.parse_address();

  EXPECT_FALSE(address.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromPathToMutualTlsConfigFile_ParseAllSecurityKeys_NoneEmpty)
{
  std::string config_file_path = grpc::nidevice::ServerConfigurationParser::get_exe_path() + "test_mutual_tls_config.json";
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_file_path);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromMissingConfigFile_ThrowsConfigFileNotFoundException)
{
  std::string missing_file_path = "fake.json";
  try {
    grpc::nidevice::ServerConfigurationParser server_config_parser(missing_file_path);

    FAIL() << "ConfigFileNotFoundException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::ConfigFileNotFoundException& ex) {
    EXPECT_EQ(grpc::nidevice::kConfigFileNotFoundMessage + std::string(missing_file_path), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithNegativePortNumber_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": -1 })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "InvalidPortException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(grpc::nidevice::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortNumberExceedingMax_ParseAddress_ThrowsInvalidPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port": 65536 })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "InvalidPortException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::InvalidPortException& ex) {
    EXPECT_EQ(std::string(grpc::nidevice::kInvalidPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithPortAsString_ParseAddress_ThrowsWrongPortTypeException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "port" : "9090" })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();

    FAIL() << "WrongPortTypeException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::WrongPortTypeException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kWrongPortTypeMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithoutPortKey_ParseAddress_ThrowsUnspecifiedPortException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({ "foo" : "bar" })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_address();
    FAIL() << "UnspecifiedPortException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::UnspecifiedPortException& ex) {
    EXPECT_EQ(std::string(grpc::nidevice::kUnspecifiedPortMessage), ex.what());
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseServerCert_NotEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto server_cert = server_config_parser.parse_server_cert();

  EXPECT_FALSE(server_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseServerKey_NotEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();

  EXPECT_FALSE(server_key.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerSideTls_ParseRootCert_Empty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
  {
    "security" : {
        "server_cert": "test_server_self_signed_crt.pem",
        "server_key": "test_server_privatekey.pem",
        "root_cert": ""
    }
  })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithMutualTls_ParseAllSecurityKeys_NoneEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": "test_server_privatekey.pem",
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_FALSE(server_key.empty());
  EXPECT_FALSE(server_cert.empty());
  EXPECT_FALSE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, CreateConfigurationParserFromDefaultConfigFile_ParseAllSecurityKeys_AllEmpty)
{
  grpc::nidevice::ServerConfigurationParser server_config_parser;

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerCertAsInteger_ParseServerCert_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": 9,
          "server_key": "test_server_privatekey.pem",
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_cert();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithServerKeyAsNull_ParseServerKey_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": null,
          "root_cert": "test_client_self_signed_crt.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_key();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithRootCertAsBoolean_ParseRootCert_ValueTypeNotStringException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "test_server_self_signed_crt.pem",
          "server_key": "test_server_privatekey.pem",
          "root_cert": true
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_root_cert();

    FAIL() << "ValueTypeNotStringException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::ValueTypeNotStringException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kValueTypeNotStringMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithValidPemFilesButWithoutSecurityParentKey_ParseAllSecurityKeys_AllEmpty)
{
  // This JSON configuration is missing the "security" parent key
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "server_cert": "test_server_self_signed_crt.pem",
      "server_key": "test_server_privatekey.pem",
      "root_cert": "test_client_self_signed_crt.pem"
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, EmptyJsonConfig_ParseAllSecurityKeys_AllEmpty)
{
  nlohmann::json config_json = nlohmann::json::parse(R"({})");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  auto server_key = server_config_parser.parse_server_key();
  auto server_cert = server_config_parser.parse_server_cert();
  auto root_cert = server_config_parser.parse_root_cert();

  EXPECT_TRUE(server_key.empty());
  EXPECT_TRUE(server_cert.empty());
  EXPECT_TRUE(root_cert.empty());
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingServerCertFile_ParseServerCert_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_cert": "missing_server_cert.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_cert();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kFileNotFoundMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingServerKeyFile_ParseServerKey_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "server_key": "missing_server_key.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_server_key();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kFileNotFoundMessage));
  }
}

TEST(ServerConfigurationParserTests, JsonConfigWithMissingRootCertFile_ParseRootCert_ThrowsFileNotFoundException)
{
  nlohmann::json config_json = nlohmann::json::parse(R"(
    {
      "security" : {
          "root_cert": "missing_root_cert.pem"
      }
    })");
  grpc::nidevice::ServerConfigurationParser server_config_parser(config_json);

  try {
    auto address = server_config_parser.parse_root_cert();

    FAIL() << "FileNotFoundException not thrown";
  }
  catch (const grpc::nidevice::ServerConfigurationParser::FileNotFoundException& ex) {
    EXPECT_THAT(ex.what(), testing::HasSubstr(grpc::nidevice::kFileNotFoundMessage));
  }
}
}  // namespace unit
}  // namespace tests
}  // namespace ni


//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-MXLCTERMINALADAPTOR-RESTRICTED.
//---------------------------------------------------------------------
#include "nimxlcterminaladaptor_restricted_client.h"

#include <grpcpp/grpcpp.h>

#include <nimxlcterminaladaptor_restricted.grpc.pb.h>

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>

namespace nimxlcterminaladaptor_restricted_grpc::experimental::client {

CreateSessionResponse
create_session(const StubPtr& stub, const pb::string& hostname)
{
  ::grpc::ClientContext context;

  auto request = CreateSessionRequest{};
  request.set_hostname(hostname);

  auto response = CreateSessionResponse{};

  raise_if_error(
      stub->CreateSession(&context, request, &response));

  return response;
}

DestroySessionResponse
destroy_session(const StubPtr& stub, const nidevice_grpc::Session& session)
{
  ::grpc::ClientContext context;

  auto request = DestroySessionRequest{};
  request.mutable_session()->CopyFrom(session);

  auto response = DestroySessionResponse{};

  raise_if_error(
      stub->DestroySession(&context, request, &response));

  return response;
}

RefreshTerminalCacheResponse
refresh_terminal_cache(const StubPtr& stub, const nidevice_grpc::Session& session)
{
  ::grpc::ClientContext context;

  auto request = RefreshTerminalCacheRequest{};
  request.mutable_session()->CopyFrom(session);

  auto response = RefreshTerminalCacheResponse{};

  raise_if_error(
      stub->RefreshTerminalCache(&context, request, &response));

  return response;
}

HasTerminalInformationChangedResponse
has_terminal_information_changed(const StubPtr& stub, const nidevice_grpc::Session& session, const pb::uint32& system_change_number)
{
  ::grpc::ClientContext context;

  auto request = HasTerminalInformationChangedRequest{};
  request.mutable_session()->CopyFrom(session);
  request.set_system_change_number(system_change_number);

  auto response = HasTerminalInformationChangedResponse{};

  raise_if_error(
      stub->HasTerminalInformationChanged(&context, request, &response));

  return response;
}

GetSystemChangeNumberResponse
get_system_change_number(const StubPtr& stub, const nidevice_grpc::Session& session)
{
  ::grpc::ClientContext context;

  auto request = GetSystemChangeNumberRequest{};
  request.mutable_session()->CopyFrom(session);

  auto response = GetSystemChangeNumberResponse{};

  raise_if_error(
      stub->GetSystemChangeNumber(&context, request, &response));

  return response;
}

GetDeviceContainerResponse
get_device_container(const StubPtr& stub, const nidevice_grpc::Session& session)
{
  ::grpc::ClientContext context;

  auto request = GetDeviceContainerRequest{};
  request.mutable_session()->CopyFrom(session);

  auto response = GetDeviceContainerResponse{};

  raise_if_error(
      stub->GetDeviceContainer(&context, request, &response));

  return response;
}


} // namespace nimxlcterminaladaptor_restricted_grpc::experimental::client
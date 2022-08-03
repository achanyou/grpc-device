
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-RFMXINSTR-RESTRICTED Metadata
//---------------------------------------------------------------------
#ifndef NIRFMXINSTR_RESTRICTED_GRPC_SERVICE_H
#define NIRFMXINSTR_RESTRICTED_GRPC_SERVICE_H

#include <nirfmxinstr_restricted.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/converters.h>
#include <server/feature_toggles.h>
#include <server/session_resource_repository.h>
#include <server/shared_library.h>
#include <server/exceptions.h>

#include "nirfmxinstr_restricted_library_interface.h"

namespace nirfmxinstr_restricted_grpc {

struct NiRFmxInstrRestrictedFeatureToggles
{
  using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
  NiRFmxInstrRestrictedFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles = {});

  bool is_enabled;
};

class NiRFmxInstrRestrictedService final : public NiRFmxInstrRestricted::Service {
public:
  using ResourceRepositorySharedPtr = std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>;

  NiRFmxInstrRestrictedService(
    NiRFmxInstrRestrictedLibraryInterface* library,
    ResourceRepositorySharedPtr resource_repository,
    const NiRFmxInstrRestrictedFeatureToggles& feature_toggles = {});
  virtual ~NiRFmxInstrRestrictedService();
  
  ::grpc::Status RegisterSpecialClientSnapshotInterest(::grpc::ServerContext* context, const RegisterSpecialClientSnapshotInterestRequest* request, RegisterSpecialClientSnapshotInterestResponse* response) override;
  ::grpc::Status GetOpenSessionsInformation(::grpc::ServerContext* context, const GetOpenSessionsInformationRequest* request, GetOpenSessionsInformationResponse* response) override;
  ::grpc::Status GetRFmxVersion(::grpc::ServerContext* context, const GetRFmxVersionRequest* request, GetRFmxVersionResponse* response) override;
  ::grpc::Status GetTracesInfoForMonitorSnapshot(::grpc::ServerContext* context, const GetTracesInfoForMonitorSnapshotRequest* request, GetTracesInfoForMonitorSnapshotResponse* response) override;
  ::grpc::Status GetForceAllTracesEnabled(::grpc::ServerContext* context, const GetForceAllTracesEnabledRequest* request, GetForceAllTracesEnabledResponse* response) override;
  ::grpc::Status SetForceAllTracesEnabled(::grpc::ServerContext* context, const SetForceAllTracesEnabledRequest* request, SetForceAllTracesEnabledResponse* response) override;
  ::grpc::Status SaveConfigurationsToJSON(::grpc::ServerContext* context, const SaveConfigurationsToJSONRequest* request, SaveConfigurationsToJSONResponse* response) override;
  ::grpc::Status LoadConfigurationsFromJSON(::grpc::ServerContext* context, const LoadConfigurationsFromJSONRequest* request, LoadConfigurationsFromJSONResponse* response) override;
  ::grpc::Status GetAttributeDesiredF64(::grpc::ServerContext* context, const GetAttributeDesiredF64Request* request, GetAttributeDesiredF64Response* response) override;
  ::grpc::Status GetAttributeDesiredI32(::grpc::ServerContext* context, const GetAttributeDesiredI32Request* request, GetAttributeDesiredI32Response* response) override;
  ::grpc::Status GetAttributeDesiredI64(::grpc::ServerContext* context, const GetAttributeDesiredI64Request* request, GetAttributeDesiredI64Response* response) override;
  ::grpc::Status GetAttributeDesiredString(::grpc::ServerContext* context, const GetAttributeDesiredStringRequest* request, GetAttributeDesiredStringResponse* response) override;
  ::grpc::Status GetAttributeDesiredF64Array(::grpc::ServerContext* context, const GetAttributeDesiredF64ArrayRequest* request, GetAttributeDesiredF64ArrayResponse* response) override;
  ::grpc::Status GetAttributeDesiredF32Array(::grpc::ServerContext* context, const GetAttributeDesiredF32ArrayRequest* request, GetAttributeDesiredF32ArrayResponse* response) override;
  ::grpc::Status GetAttributeDesiredF32(::grpc::ServerContext* context, const GetAttributeDesiredF32Request* request, GetAttributeDesiredF32Response* response) override;
  ::grpc::Status GetAttributeAuthor(::grpc::ServerContext* context, const GetAttributeAuthorRequest* request, GetAttributeAuthorResponse* response) override;
  ::grpc::Status GetPrivilegeLevel(::grpc::ServerContext* context, const GetPrivilegeLevelRequest* request, GetPrivilegeLevelResponse* response) override;
  ::grpc::Status RequestPrivilege(::grpc::ServerContext* context, const RequestPrivilegeRequest* request, RequestPrivilegeResponse* response) override;
  ::grpc::Status SaveAllForRevert(::grpc::ServerContext* context, const SaveAllForRevertRequest* request, SaveAllForRevertResponse* response) override;
  ::grpc::Status LoadAllForRevert(::grpc::ServerContext* context, const LoadAllForRevertRequest* request, LoadAllForRevertResponse* response) override;
  ::grpc::Status GetInitiaitedSnapshotStrings(::grpc::ServerContext* context, const GetInitiaitedSnapshotStringsRequest* request, GetInitiaitedSnapshotStringsResponse* response) override;
  ::grpc::Status GetSnapshotInfoFromCache(::grpc::ServerContext* context, const GetSnapshotInfoFromCacheRequest* request, GetSnapshotInfoFromCacheResponse* response) override;
  ::grpc::Status GetLatestConfigurationSnapshot(::grpc::ServerContext* context, const GetLatestConfigurationSnapshotRequest* request, GetLatestConfigurationSnapshotResponse* response) override;
  ::grpc::Status GetSnapshotState(::grpc::ServerContext* context, const GetSnapshotStateRequest* request, GetSnapshotStateResponse* response) override;
  ::grpc::Status DeleteSnapshot(::grpc::ServerContext* context, const DeleteSnapshotRequest* request, DeleteSnapshotResponse* response) override;
  ::grpc::Status ConvertForPowerUnitsUtility(::grpc::ServerContext* context, const ConvertForPowerUnitsUtilityRequest* request, ConvertForPowerUnitsUtilityResponse* response) override;
  ::grpc::Status UnregisterSpecialClientSnapshotInterest(::grpc::ServerContext* context, const UnregisterSpecialClientSnapshotInterestRequest* request, UnregisterSpecialClientSnapshotInterestResponse* response) override;
  ::grpc::Status GetCalibrationPlaneNames(::grpc::ServerContext* context, const GetCalibrationPlaneNamesRequest* request, GetCalibrationPlaneNamesResponse* response) override;
  ::grpc::Status GetCalibrationPlaneEnabled(::grpc::ServerContext* context, const GetCalibrationPlaneEnabledRequest* request, GetCalibrationPlaneEnabledResponse* response) override;
  ::grpc::Status GetExternalAttenuationTableNames(::grpc::ServerContext* context, const GetExternalAttenuationTableNamesRequest* request, GetExternalAttenuationTableNamesResponse* response) override;
  ::grpc::Status GetActiveTableName(::grpc::ServerContext* context, const GetActiveTableNameRequest* request, GetActiveTableNameResponse* response) override;
  ::grpc::Status GetSParameterExternalAttenuationType(::grpc::ServerContext* context, const GetSParameterExternalAttenuationTypeRequest* request, GetSParameterExternalAttenuationTypeResponse* response) override;
  ::grpc::Status GetSignalConfigurationState64(::grpc::ServerContext* context, const GetSignalConfigurationState64Request* request, GetSignalConfigurationState64Response* response) override;
  ::grpc::Status SetIOTraceStatus(::grpc::ServerContext* context, const SetIOTraceStatusRequest* request, SetIOTraceStatusResponse* response) override;
  ::grpc::Status GetActiveResultName(::grpc::ServerContext* context, const GetActiveResultNameRequest* request, GetActiveResultNameResponse* response) override;
private:
  NiRFmxInstrRestrictedLibraryInterface* library_;
  ResourceRepositorySharedPtr session_repository_;

  NiRFmxInstrRestrictedFeatureToggles feature_toggles_;
};

} // namespace nirfmxinstr_restricted_grpc

#endif  // NIRFMXINSTR_RESTRICTED_GRPC_SERVICE_H

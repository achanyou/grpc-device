//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-XNET
//---------------------------------------------------------------------
#ifndef NIXNET_GRPC_LIBRARY_H
#define NIXNET_GRPC_LIBRARY_H

#include "nixnet_library_interface.h"

#include <server/shared_library.h>

namespace nixnet_grpc {

class NiXnetLibrary : public nixnet_grpc::NiXnetLibraryInterface {
 public:
  NiXnetLibrary();
  virtual ~NiXnetLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  nxStatus_t Blink(nxSessionRef_t interfaceRef, u32 modifier);
  nxStatus_t Clear(nxSessionRef_t session);
  nxStatus_t ConnectTerminals(nxSessionRef_t session, const char source[], const char destination[]);
  nxStatus_t ConvertByteArrayToFramesSinglePoint(nxSessionRef_t session, u8 valueBuffer[], u32 sizeOfValueBuffer, u8 buffer[], u32 sizeOfBuffer, u32* numberOfBytesReturned);
  nxStatus_t ConvertFramesToByteArraySinglePoint(nxSessionRef_t session, u8* frameBuffer, u32 numberOfBytesForFrames, u8 valueBuffer[], u32 sizeOfValueBuffer);
  nxStatus_t ConvertFramesToSignalsSinglePoint(nxSessionRef_t session, u8* frameBuffer, u32 numberOfBytesForFrames, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer);
  nxStatus_t ConvertSignalsToFramesSinglePoint(nxSessionRef_t session, f64 valueBuffer[], u32 sizeOfValueBuffer, u8 buffer[], u32 sizeOfBuffer, u32* numberOfBytesReturned);
  nxStatus_t ConvertTimestamp100nsTo1ns(nxTimestamp100ns_t from_timestamp_100ns, nxTimestamp1ns_t* to_timestamp_1ns);
  nxStatus_t ConvertTimestamp1nsTo100ns(nxTimestamp1ns_t from_timestamp_1ns, nxTimestamp100ns_t* to_timestamp_100ns);
  nxStatus_t CreateSession(const char databaseName[], const char clusterName[], const char list[], const char interfaceParameter[], u32 mode, nxSessionRef_t* session);
  nxStatus_t CreateSessionByRef(u32 numberOfDatabaseRef, nxDatabaseRef_t arrayOfDatabaseRef[], const char interfaceParameter[], u32 mode, nxSessionRef_t* session);
  nxStatus_t DbAddAlias(const char databaseAlias[], const char databaseFilepath[], u32 defaultBaudRate);
  nxStatus_t DbAddAlias64(const char databaseAlias[], const char databaseFilepath[], u64 defaultBaudRate);
  nxStatus_t DbCloseDatabase(nxDatabaseRef_t database, u32 closeAllRefs);
  nxStatus_t DbCreateObject(nxDatabaseRef_t parentObject, u32 objectClass, const char objectName[], nxDatabaseRef_t* dbObject);
  nxStatus_t DbDeleteObject(nxDatabaseRef_t dbObject);
  nxStatus_t DbDeploy(const char ipAddress[], const char databaseAlias[], u32 waitForComplete, u32* percentComplete);
  nxStatus_t DbFindObject(nxDatabaseRef_t parentObject, u32 objectClass, const char objectName[], nxDatabaseRef_t* dbObject);
  nxStatus_t DbGetDBCAttribute(nxDatabaseRef_t dbObject, u32 mode, const char attributeName[], u32 attributeTextSize, char attributeText[], u32* isDefault);
  nxStatus_t DbGetDBCAttributeSize(nxDatabaseRef_t dbObject, u32 mode, const char attributeName[], u32* attributeTextSize);
  nxStatus_t DbGetDatabaseList(const char ipAddress[], u32 sizeofAliasBuffer, char aliasBuffer[], u32 sizeofFilepathBuffer, char filepathBuffer[], u32* numberOfDatabases);
  nxStatus_t DbGetDatabaseListSizes(const char ipAddress[], u32* sizeofAliasBuffer, u32* sizeofFilepathBuffer);
  nxStatus_t DbGetProperty(nxDatabaseRef_t dbObject, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t DbGetPropertySize(nxDatabaseRef_t dbObject, u32 propertyID, u32* propertySize);
  nxStatus_t DbMerge(nxDatabaseRef_t targetCluster, nxDatabaseRef_t sourceObj, u32 copyMode, char prefix[], u32 waitForComplete, u32* percentComplete);
  nxStatus_t DbOpenDatabase(const char databaseName[], nxDatabaseRef_t* database);
  nxStatus_t DbRemoveAlias(const char databaseAlias[]);
  nxStatus_t DbSaveDatabase(nxDatabaseRef_t database, const char dbFilepath[]);
  nxStatus_t DbSetProperty(nxDatabaseRef_t dbObject, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t DbUndeploy(const char ipAddress[], const char databaseAlias[]);
  nxStatus_t DisconnectTerminals(nxSessionRef_t session, const char source[], const char destination[]);
  nxStatus_t Flush(nxSessionRef_t session);
  nxStatus_t FutureTimeTrigger(nxSessionRef_t session, nxTimestamp1ns_t when, u32 timescale);
  nxStatus_t GetProperty(nxSessionRef_t session, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t GetPropertySize(nxSessionRef_t session, u32 propertyID, u32* propertySize);
  nxStatus_t GetSubProperty(nxSessionRef_t session, u32 activeIndex, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t GetSubPropertySize(nxSessionRef_t session, u32 activeIndex, u32 propertyID, u32* propertySize);
  nxStatus_t ReadFrame(nxSessionRef_t session, u8 buffer[], u32 sizeOfBuffer, f64 timeout, u32* numberOfBytesReturned);
  nxStatus_t ReadSignalSinglePoint(nxSessionRef_t session, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer);
  nxStatus_t ReadSignalWaveform(nxSessionRef_t session, f64 timeout, nxTimestamp100ns_t* startTime, f64* deltaTime, f64 valueBuffer[], u32 sizeOfValueBuffer, u32* numberOfValuesReturned);
  nxStatus_t ReadSignalXY(nxSessionRef_t session, nxTimestamp100ns_t* timeLimit, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer, u32 numPairsBuffer[], u32 sizeOfNumPairsBuffer);
  nxStatus_t ReadState(nxSessionRef_t session, u32 stateID, u32 stateSize, void* stateValue, nxStatus_t* fault);
  nxStatus_t ReadStateTimeTrigger(nxSessionRef_t session, f64 timeout, u32 stateSize, _nxTimeLocalNetwork_t* stateValue);
  nxStatus_t SetProperty(nxSessionRef_t session, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t SetSubProperty(nxSessionRef_t session, u32 activeIndex, u32 propertyID, u32 propertySize, void* propertyValue);
  nxStatus_t Start(nxSessionRef_t session, u32 scope);
  void StatusToString(nxStatus_t statusID, u32 sizeofString, char statusDescription[2048]);
  nxStatus_t Stop(nxSessionRef_t session, u32 scope);
  nxStatus_t SystemClose(nxSessionRef_t system);
  nxStatus_t SystemOpen(nxSessionRef_t* system);
  nxStatus_t Wait(nxSessionRef_t session, u32 condition, u32 paramIn, f64 timeout, u32* paramOut);
  nxStatus_t WriteFrame(nxSessionRef_t session, u8* buffer, u32 numberOfBytesForFrames, f64 timeout);
  nxStatus_t WriteSignalSinglePoint(nxSessionRef_t session, f64 valueBuffer[], u32 sizeOfValueBuffer);
  nxStatus_t WriteSignalWaveform(nxSessionRef_t session, f64 timeout, f64 valueBuffer[], u32 sizeOfValueBuffer);
  nxStatus_t WriteSignalXY(nxSessionRef_t session, f64 timeout, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer, u32 numPairsBuffer[], u32 sizeOfNumPairsBuffer);
  nxStatus_t WriteState(nxSessionRef_t session, u32 stateID, u32 stateSize, void* stateValue);

 private:
  using BlinkPtr = decltype(&nxBlink);
  using ClearPtr = decltype(&nxClear);
  using ConnectTerminalsPtr = decltype(&nxConnectTerminals);
  using ConvertByteArrayToFramesSinglePointPtr = decltype(&nxConvertByteArrayToFramesSinglePoint);
  using ConvertFramesToByteArraySinglePointPtr = decltype(&nxConvertFramesToByteArraySinglePoint);
  using ConvertFramesToSignalsSinglePointPtr = decltype(&nxConvertFramesToSignalsSinglePoint);
  using ConvertSignalsToFramesSinglePointPtr = decltype(&nxConvertSignalsToFramesSinglePoint);
  using ConvertTimestamp100nsTo1nsPtr = decltype(&nxConvertTimestamp100nsTo1ns);
  using ConvertTimestamp1nsTo100nsPtr = decltype(&nxConvertTimestamp1nsTo100ns);
  using CreateSessionPtr = decltype(&nxCreateSession);
  using CreateSessionByRefPtr = decltype(&nxCreateSessionByRef);
  using DbAddAliasPtr = decltype(&nxdbAddAlias);
  using DbAddAlias64Ptr = decltype(&nxdbAddAlias64);
  using DbCloseDatabasePtr = decltype(&nxdbCloseDatabase);
  using DbCreateObjectPtr = decltype(&nxdbCreateObject);
  using DbDeleteObjectPtr = decltype(&nxdbDeleteObject);
  using DbDeployPtr = decltype(&nxdbDeploy);
  using DbFindObjectPtr = decltype(&nxdbFindObject);
  using DbGetDBCAttributePtr = decltype(&nxdbGetDBCAttribute);
  using DbGetDBCAttributeSizePtr = decltype(&nxdbGetDBCAttributeSize);
  using DbGetDatabaseListPtr = decltype(&nxdbGetDatabaseList);
  using DbGetDatabaseListSizesPtr = decltype(&nxdbGetDatabaseListSizes);
  using DbGetPropertyPtr = decltype(&nxdbGetProperty);
  using DbGetPropertySizePtr = decltype(&nxdbGetPropertySize);
  using DbMergePtr = decltype(&nxdbMerge);
  using DbOpenDatabasePtr = decltype(&nxdbOpenDatabase);
  using DbRemoveAliasPtr = decltype(&nxdbRemoveAlias);
  using DbSaveDatabasePtr = decltype(&nxdbSaveDatabase);
  using DbSetPropertyPtr = decltype(&nxdbSetProperty);
  using DbUndeployPtr = decltype(&nxdbUndeploy);
  using DisconnectTerminalsPtr = decltype(&nxDisconnectTerminals);
  using FlushPtr = decltype(&nxFlush);
  using FutureTimeTriggerPtr = decltype(&nxFutureTimeTrigger);
  using GetPropertyPtr = decltype(&nxGetProperty);
  using GetPropertySizePtr = decltype(&nxGetPropertySize);
  using GetSubPropertyPtr = decltype(&nxGetSubProperty);
  using GetSubPropertySizePtr = decltype(&nxGetSubPropertySize);
  using ReadFramePtr = decltype(&nxReadFrame);
  using ReadSignalSinglePointPtr = decltype(&nxReadSignalSinglePoint);
  using ReadSignalWaveformPtr = decltype(&nxReadSignalWaveform);
  using ReadSignalXYPtr = decltype(&nxReadSignalXY);
  using ReadStatePtr = decltype(&nxReadState);
  using ReadStateTimeTriggerPtr = decltype(&nxReadStateTimeTrigger);
  using SetPropertyPtr = decltype(&nxSetProperty);
  using SetSubPropertyPtr = decltype(&nxSetSubProperty);
  using StartPtr = decltype(&nxStart);
  using StatusToStringPtr = decltype(&nxStatusToString);
  using StopPtr = decltype(&nxStop);
  using SystemClosePtr = decltype(&nxSystemClose);
  using SystemOpenPtr = decltype(&nxSystemOpen);
  using WaitPtr = decltype(&nxWait);
  using WriteFramePtr = decltype(&nxWriteFrame);
  using WriteSignalSinglePointPtr = decltype(&nxWriteSignalSinglePoint);
  using WriteSignalWaveformPtr = decltype(&nxWriteSignalWaveform);
  using WriteSignalXYPtr = decltype(&nxWriteSignalXY);
  using WriteStatePtr = decltype(&nxWriteState);

  typedef struct FunctionPointers {
    BlinkPtr Blink;
    ClearPtr Clear;
    ConnectTerminalsPtr ConnectTerminals;
    ConvertByteArrayToFramesSinglePointPtr ConvertByteArrayToFramesSinglePoint;
    ConvertFramesToByteArraySinglePointPtr ConvertFramesToByteArraySinglePoint;
    ConvertFramesToSignalsSinglePointPtr ConvertFramesToSignalsSinglePoint;
    ConvertSignalsToFramesSinglePointPtr ConvertSignalsToFramesSinglePoint;
    ConvertTimestamp100nsTo1nsPtr ConvertTimestamp100nsTo1ns;
    ConvertTimestamp1nsTo100nsPtr ConvertTimestamp1nsTo100ns;
    CreateSessionPtr CreateSession;
    CreateSessionByRefPtr CreateSessionByRef;
    DbAddAliasPtr DbAddAlias;
    DbAddAlias64Ptr DbAddAlias64;
    DbCloseDatabasePtr DbCloseDatabase;
    DbCreateObjectPtr DbCreateObject;
    DbDeleteObjectPtr DbDeleteObject;
    DbDeployPtr DbDeploy;
    DbFindObjectPtr DbFindObject;
    DbGetDBCAttributePtr DbGetDBCAttribute;
    DbGetDBCAttributeSizePtr DbGetDBCAttributeSize;
    DbGetDatabaseListPtr DbGetDatabaseList;
    DbGetDatabaseListSizesPtr DbGetDatabaseListSizes;
    DbGetPropertyPtr DbGetProperty;
    DbGetPropertySizePtr DbGetPropertySize;
    DbMergePtr DbMerge;
    DbOpenDatabasePtr DbOpenDatabase;
    DbRemoveAliasPtr DbRemoveAlias;
    DbSaveDatabasePtr DbSaveDatabase;
    DbSetPropertyPtr DbSetProperty;
    DbUndeployPtr DbUndeploy;
    DisconnectTerminalsPtr DisconnectTerminals;
    FlushPtr Flush;
    FutureTimeTriggerPtr FutureTimeTrigger;
    GetPropertyPtr GetProperty;
    GetPropertySizePtr GetPropertySize;
    GetSubPropertyPtr GetSubProperty;
    GetSubPropertySizePtr GetSubPropertySize;
    ReadFramePtr ReadFrame;
    ReadSignalSinglePointPtr ReadSignalSinglePoint;
    ReadSignalWaveformPtr ReadSignalWaveform;
    ReadSignalXYPtr ReadSignalXY;
    ReadStatePtr ReadState;
    ReadStateTimeTriggerPtr ReadStateTimeTrigger;
    SetPropertyPtr SetProperty;
    SetSubPropertyPtr SetSubProperty;
    StartPtr Start;
    StatusToStringPtr StatusToString;
    StopPtr Stop;
    SystemClosePtr SystemClose;
    SystemOpenPtr SystemOpen;
    WaitPtr Wait;
    WriteFramePtr WriteFrame;
    WriteSignalSinglePointPtr WriteSignalSinglePoint;
    WriteSignalWaveformPtr WriteSignalWaveform;
    WriteSignalXYPtr WriteSignalXY;
    WriteStatePtr WriteState;
  } FunctionLoadStatus;

  nidevice_grpc::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace nixnet_grpc

#endif  // NIXNET_GRPC_LIBRARY_H

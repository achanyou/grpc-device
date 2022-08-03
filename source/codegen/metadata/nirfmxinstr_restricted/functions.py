functions = {
    'RegisterSpecialClientSnapshotInterest': {
        #'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetOpenSessionsInformation': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'infoJsonSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'infoJson',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'infoJsonSize'
                },
                'type': 'char[]'
            }            
        ],
        'returns': 'int32'
    },
    'GetRFmxVersion': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'RFmxVersion',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetTracesInfoForMonitorSnapshot': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'allTracesEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetForceAllTracesEnabled': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SetForceAllTracesEnabled': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'SaveConfigurationsToJSON': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalNames',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'jsonStringOut',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'LoadConfigurationsFromJSON': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'jsonString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF64': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredI32': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredI64': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int64'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredString': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF64Array': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float64[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF32Array': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'arraySize',
                    'value_twist': 'actualArraySize'
                },
                'type': 'float32[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'actualArraySize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeDesiredF32': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'channelName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'float32'
            }
        ],
        'returns': 'int32'
    },
    'GetAttributeAuthor': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'attributeID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'attrVal',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetPrivilegeLevel': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'isConnectionAlive',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'privilegeLevel',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'RequestPrivilege': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'privilegeLevel',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'SaveAllForRevert': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'LoadAllForRevert': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'filePath',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetInitiaitedSnapshotStrings': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'personalityIDArraySize',
                    'value_twist': 'personalityIDArrayActualSize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'personalityIDArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArrayActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'signalNamesSize',
                    'value_twist': 'signalNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultNamesSize',
                    'value_twist': 'resultNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotIdentifierSize',
                    'value_twist': 'snapshotIdentifierActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifiersSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiersActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotTimestampArraySize',
                    'value_twist': 'snapshotTimestampArrayActualSize'
                },
                'type': 'uInt64[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotTimestampArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArrayActualSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetSnapshotInfoFromCache': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'personalityIDArraySize',
                    'value_twist': 'personalityIDArrayActualSize'
                },
                'type': 'int32[]'
            },
            {
                'direction': 'in',
                'name': 'personalityIDArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'personalityIDArrayActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'signalNamesSize',
                    'value_twist': 'signalNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNames',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultNamesSize',
                    'value_twist': 'resultNamesActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'resultNamesSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultNamesActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiers',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotIdentifiersSize',
                    'value_twist': 'snapshotIdentifiersActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifiersSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifiersActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArray',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotTimestampArraySize',
                    'value_twist': 'snapshotTimestampArrayActualSize'
                },
                'type': 'uInt64[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotTimestampArraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotTimestampArrayActualSize',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetLatestConfigurationSnapshot': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'out',
                'name': 'snapshotInfoCacheIndex',
                'type': 'uInt64'
            },
            {
                'direction': 'out',
                'name': 'personalityID',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalName',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'signalNameSize',
                    'value_twist': 'signalNameActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalNameSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalNameActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifier',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'snapshotIdentifierSize',
                    'value_twist': 'snapshotIdentifierActualSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'snapshotIdentifierSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'snapshotIdentifierActualSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalConfigurationState',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'signalTimestamp',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'GetSnapshotState': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'personality',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'snapshotState',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'DeleteSnapshot': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'personality',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'ConvertForPowerUnitsUtility': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'referenceOrTriggerLevelIn',
                'type': 'float64'
            },
            {
                'direction': 'in',
                'name': 'inputPowerUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'outputPowerUnits',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'terminalConfiguration',
                'type': 'int32'
            },
            {
                'direction': 'in',
                'name': 'bandwidth',
                'type': 'float64'
            },
            {
                'direction': 'out',
                'name': 'referenceOrTriggerLevelOut',
                'type': 'float64'
            }
        ],
        'returns': 'int32'
    },
    'UnregisterSpecialClientSnapshotInterest': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'name': 'resourceName',
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetCalibrationPlaneNames': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'calibrationPlaneNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetCalibrationPlaneEnabled': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'calibrationPlaneEnabled',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    },
    'GetExternalAttenuationTableNames': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'externalAttenuationTableNames',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetActiveTableName': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'arraySize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'activeTableName',
                'size': {
                    'mechanism': 'ivi-dance',
                    'value': 'arraySize'
                },
                'type': 'char[]'
            }
        ],
        'returns': 'int32'
    },
    'GetSParameterExternalAttenuationType': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'selectorString',
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'sParameterType',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetSignalConfigurationState64': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalType',
                'type': 'uInt32'
            },
            {
                'direction': 'out',
                'name': 'signalState',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'timeStamp',
                'type': 'uInt64'
            }
        ],
        'returns': 'int32'
    },
    'SetIOTraceStatus': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'IOTraceStatus',
                'type': 'int32'
            },
        ],
        'returns': 'int32'
    },
    'GetActiveResultName': {
        'codegen_method': 'private',
        'parameters': [
            {
                'direction': 'in',
                'grpc_name': 'instrument',
                'name': 'instrumentHandle',
                'type': 'niRFmxInstrHandle'
            },
            {
                'direction': 'in',
                'name': 'signalName',
                'type': 'char[]'
            },
            {
                'direction': 'in',
                'name': 'signalType',
                'type': 'uInt32'
            },
            {
                'direction': 'in',
                'name': 'resultSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultName',
                'size': {
                    'mechanism': 'ivi-dance-with-a-twist',
                    'value': 'resultSize',
                    'value_twist': 'actualResultSize'
                },
                'type': 'char[]'
            },
            {
                'direction': 'out',
                'name': 'actualResultSize',
                'type': 'int32'
            },
            {
                'direction': 'out',
                'name': 'resultState',
                'type': 'int32'
            }
        ],
        'returns': 'int32'
    }
}

using Cxx = import "./include/c++.capnp";
$Cxx.namespace("cereal");

using Java = import "./include/java.capnp";
$Java.package("ai.comma.openpilot.cereal");
$Java.outerClassname("dp");

@0xbfa7e645486440c7;

# dp.capnp: a home for deprecated structs

struct ThermalData {
  freeSpace @0 :Float32;
}

struct DragonConf {
  dpThermalStarted @0 :Bool;
  dpThermalOverheat @1 :Bool;
  dpAtl @2 :Bool;
  dpAutoShutdown @3 :Bool;
  dpAthenad @4 :Bool;
  dpUploader @5 :Bool;
  dpSteeringOnSignal @6 :Bool;
  dpSignalOffDelay @7 :UInt8;
  dpAssistedLcMinMph @8 :Float32;
  dpAutoLc @9 :Bool;
  dpAutoLcCont @10 :Bool;
  dpAutoLcMinMph @11 :Float32;
  dpAutoLcDelay @12 :Float32;
  dpSlowOnCurve @13 :Bool;
  dpAllowGas @14 :Bool;
  dpFollowingProfile @15 :UInt8;
  dpAccelProfile @16 :UInt8;
  dpDriverMonitor @17 :Bool;
  dpSteeringMonitor @18 :Bool;
  dpSteeringMonitorTimer @19 :UInt8;
  dpGearCheck @20 :Bool;
  dpSpeedCheck @21 :Bool;
  dpUiScreenOffReversing @22 :Bool;
  dpUiSpeed @23 :Bool;
  dpUiEvent @24 :Bool;
  dpUiMaxSpeed @25 :Bool;
  dpUiFace @26 :Bool;
  dpUiLane @27 :Bool;
  dpUiLead @28 :Bool;
  dpUiDev @29 :Bool;
  dpUiDevMini @30 :Bool;
  dpUiBlinker @31 :Bool;
  dpAppExtGps @32 :Bool;
  dpAppTomtom @33 :Bool;
  dpAppTomtomAuto @34 :Bool;
  dpAppTomtomManual @35 :Int8;
  dpAppMixplorer @36 :Bool;
  dpAppMixplorerManual @37 :Int8;
  dpCarDetected @38 :Text;
  dpToyotaLdw @39 :Bool;
  dpToyotaSng @40 :Bool;
  dpVwPanda @41 :Bool;
  dpVwTimebombAssist @42 :Bool;
  dpIpAddr @43 :Text;
  dpLocale @44 :Text;
  dpIsUpdating @45 :Bool;
  dpDebug @46 :Bool;
}
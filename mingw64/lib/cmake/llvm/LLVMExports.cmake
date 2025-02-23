# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.19)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget LLVMDemangle LLVMSupport LLVMTableGen llvm-tblgen LLVMCore LLVMFuzzMutate LLVMFileCheck LLVMInterfaceStub LLVMIRReader LLVMCodeGen LLVMSelectionDAG LLVMAsmPrinter LLVMMIRParser LLVMGlobalISel LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMBitstreamReader LLVMDWARFLinker LLVMExtensions LLVMFrontendOpenACC LLVMFrontendOpenMP LLVMTransformUtils LLVMInstrumentation LLVMAggressiveInstCombine LLVMInstCombine LLVMScalarOpts LLVMipo LLVMVectorize LLVMHelloNew LLVMObjCARCOpts LLVMCoroutines LLVMCFGuard LLVMLinker LLVMAnalysis LLVMLTO LLVMMC LLVMMCParser LLVMMCDisassembler LLVMMCA LLVMObject LLVMObjectYAML LLVMOption LLVMRemarks LLVMDebugInfoDWARF LLVMDebugInfoGSYM LLVMDebugInfoMSF LLVMDebugInfoCodeView LLVMDebugInfoPDB LLVMSymbolize LLVMExecutionEngine LLVMInterpreter LLVMJITLink LLVMMCJIT LLVMOrcJIT LLVMOrcShared LLVMOrcTargetProcess LLVMRuntimeDyld LLVMTarget LLVMX86CodeGen LLVMX86AsmParser LLVMX86Disassembler LLVMX86Desc LLVMX86Info LLVMNVPTXCodeGen LLVMNVPTXDesc LLVMNVPTXInfo LLVMAMDGPUCodeGen LLVMAMDGPUAsmParser LLVMAMDGPUDisassembler LLVMAMDGPUDesc LLVMAMDGPUInfo LLVMAMDGPUUtils LLVMARMCodeGen LLVMARMAsmParser LLVMARMDisassembler LLVMARMDesc LLVMARMInfo LLVMARMUtils LLVMAArch64CodeGen LLVMAArch64AsmParser LLVMAArch64Disassembler LLVMAArch64Desc LLVMAArch64Info LLVMAArch64Utils LLVMAsmParser LLVMLineEditor LLVMProfileData LLVMCoverage LLVMPasses LLVMTextAPI LLVMDlltoolDriver LLVMLibDriver LLVMXRay LLVMWindowsManifest FileCheck llvm-PerfectShuffle count not yaml-bench LTO llvm-ar llvm-config llvm-lto llvm-profdata bugpoint dsymutil llc lli-child-target lli llvm-as llvm-bcanalyzer llvm-cat llvm-cfi-verify llvm-cov llvm-cvtres llvm-cxxdump llvm-cxxfilt llvm-cxxmap llvm-diff llvm-dis llvm-dwarfdump llvm-dwp llvm-elfabi llvm-exegesis llvm-extract llvm-gsymutil llvm-ifs llvm-jitlink-executor llvm-jitlink llvm-libtool-darwin llvm-link llvm-lipo llvm-lto2 llvm-mc llvm-mca llvm-ml llvm-modextract llvm-mt llvm-nm llvm-objcopy llvm-objdump llvm-opt-report llvm-pdbutil llvm-profgen llvm-rc llvm-readobj llvm-reduce llvm-rtdyld llvm-size llvm-split llvm-stress llvm-strings llvm-symbolizer llvm-undname llvm-xray obj2yaml opt Remarks sancov sanstats split-file verify-uselistorder yaml2obj)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target LLVMDemangle
add_library(LLVMDemangle SHARED IMPORTED)

# Create imported target LLVMSupport
add_library(LLVMSupport SHARED IMPORTED)

# Create imported target LLVMTableGen
add_library(LLVMTableGen SHARED IMPORTED)

# Create imported target llvm-tblgen
add_executable(llvm-tblgen IMPORTED)

# Create imported target LLVMCore
add_library(LLVMCore SHARED IMPORTED)

# Create imported target LLVMFuzzMutate
add_library(LLVMFuzzMutate SHARED IMPORTED)

# Create imported target LLVMFileCheck
add_library(LLVMFileCheck SHARED IMPORTED)

set_target_properties(LLVMFileCheck PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMInterfaceStub
add_library(LLVMInterfaceStub SHARED IMPORTED)

# Create imported target LLVMIRReader
add_library(LLVMIRReader SHARED IMPORTED)

# Create imported target LLVMCodeGen
add_library(LLVMCodeGen SHARED IMPORTED)

# Create imported target LLVMSelectionDAG
add_library(LLVMSelectionDAG SHARED IMPORTED)

# Create imported target LLVMAsmPrinter
add_library(LLVMAsmPrinter SHARED IMPORTED)

# Create imported target LLVMMIRParser
add_library(LLVMMIRParser SHARED IMPORTED)

# Create imported target LLVMGlobalISel
add_library(LLVMGlobalISel SHARED IMPORTED)

# Create imported target LLVMBinaryFormat
add_library(LLVMBinaryFormat SHARED IMPORTED)

# Create imported target LLVMBitReader
add_library(LLVMBitReader SHARED IMPORTED)

# Create imported target LLVMBitWriter
add_library(LLVMBitWriter SHARED IMPORTED)

# Create imported target LLVMBitstreamReader
add_library(LLVMBitstreamReader SHARED IMPORTED)

# Create imported target LLVMDWARFLinker
add_library(LLVMDWARFLinker SHARED IMPORTED)

# Create imported target LLVMExtensions
add_library(LLVMExtensions SHARED IMPORTED)

# Create imported target LLVMFrontendOpenACC
add_library(LLVMFrontendOpenACC SHARED IMPORTED)

set_target_properties(LLVMFrontendOpenACC PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMSupport"
)

# Create imported target LLVMFrontendOpenMP
add_library(LLVMFrontendOpenMP SHARED IMPORTED)

# Create imported target LLVMTransformUtils
add_library(LLVMTransformUtils SHARED IMPORTED)

# Create imported target LLVMInstrumentation
add_library(LLVMInstrumentation SHARED IMPORTED)

# Create imported target LLVMAggressiveInstCombine
add_library(LLVMAggressiveInstCombine SHARED IMPORTED)

# Create imported target LLVMInstCombine
add_library(LLVMInstCombine SHARED IMPORTED)

# Create imported target LLVMScalarOpts
add_library(LLVMScalarOpts SHARED IMPORTED)

# Create imported target LLVMipo
add_library(LLVMipo SHARED IMPORTED)

# Create imported target LLVMVectorize
add_library(LLVMVectorize SHARED IMPORTED)

# Create imported target LLVMHelloNew
add_library(LLVMHelloNew SHARED IMPORTED)

# Create imported target LLVMObjCARCOpts
add_library(LLVMObjCARCOpts SHARED IMPORTED)

# Create imported target LLVMCoroutines
add_library(LLVMCoroutines SHARED IMPORTED)

# Create imported target LLVMCFGuard
add_library(LLVMCFGuard SHARED IMPORTED)

# Create imported target LLVMLinker
add_library(LLVMLinker SHARED IMPORTED)

# Create imported target LLVMAnalysis
add_library(LLVMAnalysis SHARED IMPORTED)

# Create imported target LLVMLTO
add_library(LLVMLTO SHARED IMPORTED)

# Create imported target LLVMMC
add_library(LLVMMC SHARED IMPORTED)

# Create imported target LLVMMCParser
add_library(LLVMMCParser SHARED IMPORTED)

# Create imported target LLVMMCDisassembler
add_library(LLVMMCDisassembler SHARED IMPORTED)

# Create imported target LLVMMCA
add_library(LLVMMCA SHARED IMPORTED)

# Create imported target LLVMObject
add_library(LLVMObject SHARED IMPORTED)

# Create imported target LLVMObjectYAML
add_library(LLVMObjectYAML SHARED IMPORTED)

# Create imported target LLVMOption
add_library(LLVMOption SHARED IMPORTED)

# Create imported target LLVMRemarks
add_library(LLVMRemarks SHARED IMPORTED)

# Create imported target LLVMDebugInfoDWARF
add_library(LLVMDebugInfoDWARF SHARED IMPORTED)

# Create imported target LLVMDebugInfoGSYM
add_library(LLVMDebugInfoGSYM SHARED IMPORTED)

# Create imported target LLVMDebugInfoMSF
add_library(LLVMDebugInfoMSF SHARED IMPORTED)

# Create imported target LLVMDebugInfoCodeView
add_library(LLVMDebugInfoCodeView SHARED IMPORTED)

# Create imported target LLVMDebugInfoPDB
add_library(LLVMDebugInfoPDB SHARED IMPORTED)

# Create imported target LLVMSymbolize
add_library(LLVMSymbolize SHARED IMPORTED)

# Create imported target LLVMExecutionEngine
add_library(LLVMExecutionEngine SHARED IMPORTED)

set_target_properties(LLVMExecutionEngine PROPERTIES
  INTERFACE_LINK_LIBRARIES "LLVMRuntimeDyld"
)

# Create imported target LLVMInterpreter
add_library(LLVMInterpreter SHARED IMPORTED)

# Create imported target LLVMJITLink
add_library(LLVMJITLink SHARED IMPORTED)

# Create imported target LLVMMCJIT
add_library(LLVMMCJIT SHARED IMPORTED)

# Create imported target LLVMOrcJIT
add_library(LLVMOrcJIT SHARED IMPORTED)

# Create imported target LLVMOrcShared
add_library(LLVMOrcShared SHARED IMPORTED)

# Create imported target LLVMOrcTargetProcess
add_library(LLVMOrcTargetProcess SHARED IMPORTED)

# Create imported target LLVMRuntimeDyld
add_library(LLVMRuntimeDyld SHARED IMPORTED)

# Create imported target LLVMTarget
add_library(LLVMTarget SHARED IMPORTED)

# Create imported target LLVMX86CodeGen
add_library(LLVMX86CodeGen SHARED IMPORTED)

# Create imported target LLVMX86AsmParser
add_library(LLVMX86AsmParser SHARED IMPORTED)

# Create imported target LLVMX86Disassembler
add_library(LLVMX86Disassembler SHARED IMPORTED)

# Create imported target LLVMX86Desc
add_library(LLVMX86Desc SHARED IMPORTED)

# Create imported target LLVMX86Info
add_library(LLVMX86Info SHARED IMPORTED)

# Create imported target LLVMNVPTXCodeGen
add_library(LLVMNVPTXCodeGen SHARED IMPORTED)

# Create imported target LLVMNVPTXDesc
add_library(LLVMNVPTXDesc SHARED IMPORTED)

# Create imported target LLVMNVPTXInfo
add_library(LLVMNVPTXInfo SHARED IMPORTED)

# Create imported target LLVMAMDGPUCodeGen
add_library(LLVMAMDGPUCodeGen SHARED IMPORTED)

# Create imported target LLVMAMDGPUAsmParser
add_library(LLVMAMDGPUAsmParser SHARED IMPORTED)

# Create imported target LLVMAMDGPUDisassembler
add_library(LLVMAMDGPUDisassembler SHARED IMPORTED)

# Create imported target LLVMAMDGPUDesc
add_library(LLVMAMDGPUDesc SHARED IMPORTED)

# Create imported target LLVMAMDGPUInfo
add_library(LLVMAMDGPUInfo SHARED IMPORTED)

# Create imported target LLVMAMDGPUUtils
add_library(LLVMAMDGPUUtils SHARED IMPORTED)

# Create imported target LLVMARMCodeGen
add_library(LLVMARMCodeGen SHARED IMPORTED)

# Create imported target LLVMARMAsmParser
add_library(LLVMARMAsmParser SHARED IMPORTED)

# Create imported target LLVMARMDisassembler
add_library(LLVMARMDisassembler SHARED IMPORTED)

# Create imported target LLVMARMDesc
add_library(LLVMARMDesc SHARED IMPORTED)

# Create imported target LLVMARMInfo
add_library(LLVMARMInfo SHARED IMPORTED)

# Create imported target LLVMARMUtils
add_library(LLVMARMUtils SHARED IMPORTED)

# Create imported target LLVMAArch64CodeGen
add_library(LLVMAArch64CodeGen SHARED IMPORTED)

# Create imported target LLVMAArch64AsmParser
add_library(LLVMAArch64AsmParser SHARED IMPORTED)

# Create imported target LLVMAArch64Disassembler
add_library(LLVMAArch64Disassembler SHARED IMPORTED)

# Create imported target LLVMAArch64Desc
add_library(LLVMAArch64Desc SHARED IMPORTED)

# Create imported target LLVMAArch64Info
add_library(LLVMAArch64Info SHARED IMPORTED)

# Create imported target LLVMAArch64Utils
add_library(LLVMAArch64Utils SHARED IMPORTED)

# Create imported target LLVMAsmParser
add_library(LLVMAsmParser SHARED IMPORTED)

# Create imported target LLVMLineEditor
add_library(LLVMLineEditor SHARED IMPORTED)

# Create imported target LLVMProfileData
add_library(LLVMProfileData SHARED IMPORTED)

# Create imported target LLVMCoverage
add_library(LLVMCoverage SHARED IMPORTED)

# Create imported target LLVMPasses
add_library(LLVMPasses SHARED IMPORTED)

# Create imported target LLVMTextAPI
add_library(LLVMTextAPI SHARED IMPORTED)

# Create imported target LLVMDlltoolDriver
add_library(LLVMDlltoolDriver SHARED IMPORTED)

# Create imported target LLVMLibDriver
add_library(LLVMLibDriver SHARED IMPORTED)

# Create imported target LLVMXRay
add_library(LLVMXRay SHARED IMPORTED)

# Create imported target LLVMWindowsManifest
add_library(LLVMWindowsManifest SHARED IMPORTED)

# Create imported target FileCheck
add_executable(FileCheck IMPORTED)

# Create imported target llvm-PerfectShuffle
add_executable(llvm-PerfectShuffle IMPORTED)

# Create imported target count
add_executable(count IMPORTED)

# Create imported target not
add_executable(not IMPORTED)

# Create imported target yaml-bench
add_executable(yaml-bench IMPORTED)

# Create imported target LTO
add_library(LTO SHARED IMPORTED)

# Create imported target llvm-ar
add_executable(llvm-ar IMPORTED)

# Create imported target llvm-config
add_executable(llvm-config IMPORTED)

# Create imported target llvm-lto
add_executable(llvm-lto IMPORTED)

# Create imported target llvm-profdata
add_executable(llvm-profdata IMPORTED)

# Create imported target bugpoint
add_executable(bugpoint IMPORTED)

# Create imported target dsymutil
add_executable(dsymutil IMPORTED)

# Create imported target llc
add_executable(llc IMPORTED)

# Create imported target lli-child-target
add_executable(lli-child-target IMPORTED)

# Create imported target lli
add_executable(lli IMPORTED)

# Create imported target llvm-as
add_executable(llvm-as IMPORTED)

# Create imported target llvm-bcanalyzer
add_executable(llvm-bcanalyzer IMPORTED)

# Create imported target llvm-cat
add_executable(llvm-cat IMPORTED)

# Create imported target llvm-cfi-verify
add_executable(llvm-cfi-verify IMPORTED)

# Create imported target llvm-cov
add_executable(llvm-cov IMPORTED)

# Create imported target llvm-cvtres
add_executable(llvm-cvtres IMPORTED)

# Create imported target llvm-cxxdump
add_executable(llvm-cxxdump IMPORTED)

# Create imported target llvm-cxxfilt
add_executable(llvm-cxxfilt IMPORTED)

# Create imported target llvm-cxxmap
add_executable(llvm-cxxmap IMPORTED)

# Create imported target llvm-diff
add_executable(llvm-diff IMPORTED)

# Create imported target llvm-dis
add_executable(llvm-dis IMPORTED)

# Create imported target llvm-dwarfdump
add_executable(llvm-dwarfdump IMPORTED)

# Create imported target llvm-dwp
add_executable(llvm-dwp IMPORTED)

# Create imported target llvm-elfabi
add_executable(llvm-elfabi IMPORTED)

# Create imported target llvm-exegesis
add_executable(llvm-exegesis IMPORTED)

# Create imported target llvm-extract
add_executable(llvm-extract IMPORTED)

# Create imported target llvm-gsymutil
add_executable(llvm-gsymutil IMPORTED)

# Create imported target llvm-ifs
add_executable(llvm-ifs IMPORTED)

# Create imported target llvm-jitlink-executor
add_executable(llvm-jitlink-executor IMPORTED)

# Create imported target llvm-jitlink
add_executable(llvm-jitlink IMPORTED)

# Create imported target llvm-libtool-darwin
add_executable(llvm-libtool-darwin IMPORTED)

# Create imported target llvm-link
add_executable(llvm-link IMPORTED)

# Create imported target llvm-lipo
add_executable(llvm-lipo IMPORTED)

# Create imported target llvm-lto2
add_executable(llvm-lto2 IMPORTED)

# Create imported target llvm-mc
add_executable(llvm-mc IMPORTED)

# Create imported target llvm-mca
add_executable(llvm-mca IMPORTED)

# Create imported target llvm-ml
add_executable(llvm-ml IMPORTED)

# Create imported target llvm-modextract
add_executable(llvm-modextract IMPORTED)

# Create imported target llvm-mt
add_executable(llvm-mt IMPORTED)

# Create imported target llvm-nm
add_executable(llvm-nm IMPORTED)

# Create imported target llvm-objcopy
add_executable(llvm-objcopy IMPORTED)

# Create imported target llvm-objdump
add_executable(llvm-objdump IMPORTED)

# Create imported target llvm-opt-report
add_executable(llvm-opt-report IMPORTED)

# Create imported target llvm-pdbutil
add_executable(llvm-pdbutil IMPORTED)

# Create imported target llvm-profgen
add_executable(llvm-profgen IMPORTED)

# Create imported target llvm-rc
add_executable(llvm-rc IMPORTED)

# Create imported target llvm-readobj
add_executable(llvm-readobj IMPORTED)

# Create imported target llvm-reduce
add_executable(llvm-reduce IMPORTED)

# Create imported target llvm-rtdyld
add_executable(llvm-rtdyld IMPORTED)

# Create imported target llvm-size
add_executable(llvm-size IMPORTED)

# Create imported target llvm-split
add_executable(llvm-split IMPORTED)

# Create imported target llvm-stress
add_executable(llvm-stress IMPORTED)

# Create imported target llvm-strings
add_executable(llvm-strings IMPORTED)

# Create imported target llvm-symbolizer
add_executable(llvm-symbolizer IMPORTED)

# Create imported target llvm-undname
add_executable(llvm-undname IMPORTED)

# Create imported target llvm-xray
add_executable(llvm-xray IMPORTED)

# Create imported target obj2yaml
add_executable(obj2yaml IMPORTED)

# Create imported target opt
add_executable(opt IMPORTED)

# Create imported target Remarks
add_library(Remarks SHARED IMPORTED)

# Create imported target sancov
add_executable(sancov IMPORTED)

# Create imported target sanstats
add_executable(sanstats IMPORTED)

# Create imported target split-file
add_executable(split-file IMPORTED)

# Create imported target verify-uselistorder
add_executable(verify-uselistorder IMPORTED)

# Create imported target yaml2obj
add_executable(yaml2obj IMPORTED)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/LLVMExports-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)

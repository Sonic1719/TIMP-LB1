##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lb
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/user/Documents/Timp
ProjectPath            :=/home/user/Documents/TIMP-LB1/Lb
IntermediateDirectory  :=../../Timp/build-$(WorkspaceConfiguration)/__/TIMP-LB1/Lb
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=user
Date                   :=07/10/26
CodeLitePath           :=/home/user/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/home/user/Documents/Timp/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../../Timp/build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/up_TableCipher_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_TableCipher_main.cpp$(ObjectSuffix): ../TableCipher/main.cpp $(IntermediateDirectory)/up_TableCipher_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Documents/TIMP-LB1/TableCipher/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_TableCipher_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_TableCipher_main.cpp$(DependSuffix): ../TableCipher/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_TableCipher_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_TableCipher_main.cpp$(DependSuffix) -MM ../TableCipher/main.cpp

$(IntermediateDirectory)/up_TableCipher_main.cpp$(PreprocessSuffix): ../TableCipher/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_TableCipher_main.cpp$(PreprocessSuffix) ../TableCipher/main.cpp

$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(ObjectSuffix): ../TableCipher/TableCipher.cpp $(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Documents/TIMP-LB1/TableCipher/TableCipher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(DependSuffix): ../TableCipher/TableCipher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(DependSuffix) -MM ../TableCipher/TableCipher.cpp

$(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(PreprocessSuffix): ../TableCipher/TableCipher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_TableCipher_TableCipher.cpp$(PreprocessSuffix) ../TableCipher/TableCipher.cpp

$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(ObjectSuffix): ../modAlphaCipher/modAlphaCipher.cpp $(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/Documents/TIMP-LB1/modAlphaCipher/modAlphaCipher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(DependSuffix): ../modAlphaCipher/modAlphaCipher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(DependSuffix) -MM ../modAlphaCipher/modAlphaCipher.cpp

$(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(PreprocessSuffix): ../modAlphaCipher/modAlphaCipher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_modAlphaCipher_modAlphaCipher.cpp$(PreprocessSuffix) ../modAlphaCipher/modAlphaCipher.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)



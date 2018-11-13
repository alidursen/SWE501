##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=inh
ConfigurationName      :=Debug
WorkspacePath          := "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance"
ProjectPath            := "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=AliKutlu
Date                   :=16/06/17
CodeLitePath           :="/home/alikutlu/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="inh.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Task.cpp$(ObjectSuffix) $(IntermediateDirectory)/Tag.cpp$(ObjectSuffix) $(IntermediateDirectory)/Worker.cpp$(ObjectSuffix) $(IntermediateDirectory)/Setting.cpp$(ObjectSuffix) $(IntermediateDirectory)/ObjArray.cpp$(ObjectSuffix) $(IntermediateDirectory)/Prequeue.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Task.cpp$(ObjectSuffix): Task.cpp $(IntermediateDirectory)/Task.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/Task.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Task.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Task.cpp$(DependSuffix): Task.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Task.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Task.cpp$(DependSuffix) -MM "Task.cpp"

$(IntermediateDirectory)/Task.cpp$(PreprocessSuffix): Task.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Task.cpp$(PreprocessSuffix) "Task.cpp"

$(IntermediateDirectory)/Tag.cpp$(ObjectSuffix): Tag.cpp $(IntermediateDirectory)/Tag.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/Tag.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Tag.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Tag.cpp$(DependSuffix): Tag.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Tag.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Tag.cpp$(DependSuffix) -MM "Tag.cpp"

$(IntermediateDirectory)/Tag.cpp$(PreprocessSuffix): Tag.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Tag.cpp$(PreprocessSuffix) "Tag.cpp"

$(IntermediateDirectory)/Worker.cpp$(ObjectSuffix): Worker.cpp $(IntermediateDirectory)/Worker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/Worker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Worker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Worker.cpp$(DependSuffix): Worker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Worker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Worker.cpp$(DependSuffix) -MM "Worker.cpp"

$(IntermediateDirectory)/Worker.cpp$(PreprocessSuffix): Worker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Worker.cpp$(PreprocessSuffix) "Worker.cpp"

$(IntermediateDirectory)/Setting.cpp$(ObjectSuffix): Setting.cpp $(IntermediateDirectory)/Setting.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/Setting.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Setting.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Setting.cpp$(DependSuffix): Setting.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Setting.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Setting.cpp$(DependSuffix) -MM "Setting.cpp"

$(IntermediateDirectory)/Setting.cpp$(PreprocessSuffix): Setting.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Setting.cpp$(PreprocessSuffix) "Setting.cpp"

$(IntermediateDirectory)/ObjArray.cpp$(ObjectSuffix): ObjArray.cpp $(IntermediateDirectory)/ObjArray.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/ObjArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ObjArray.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ObjArray.cpp$(DependSuffix): ObjArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ObjArray.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ObjArray.cpp$(DependSuffix) -MM "ObjArray.cpp"

$(IntermediateDirectory)/ObjArray.cpp$(PreprocessSuffix): ObjArray.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ObjArray.cpp$(PreprocessSuffix) "ObjArray.cpp"

$(IntermediateDirectory)/Prequeue.cpp$(ObjectSuffix): Prequeue.cpp $(IntermediateDirectory)/Prequeue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/alikutlu/Belgeler/SWE/2017.2/501 c++/finalProjWithInheritance/Prequeue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Prequeue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Prequeue.cpp$(DependSuffix): Prequeue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Prequeue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Prequeue.cpp$(DependSuffix) -MM "Prequeue.cpp"

$(IntermediateDirectory)/Prequeue.cpp$(PreprocessSuffix): Prequeue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Prequeue.cpp$(PreprocessSuffix) "Prequeue.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



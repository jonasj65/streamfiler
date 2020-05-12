#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/clientsocket.o \
	${OBJECTDIR}/filenamegenerator.o \
	${OBJECTDIR}/filewriter.o \
	${OBJECTDIR}/iparameters.o \
	${OBJECTDIR}/itimerexec.o \
	${OBJECTDIR}/log.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/parameters.o \
	${OBJECTDIR}/path.o \
	${OBJECTDIR}/receiver.o \
	${OBJECTDIR}/serversocket.o \
	${OBJECTDIR}/stringtool.o \
	${OBJECTDIR}/timedexecutor.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/FileNameGeneratorTest.o \
	${TESTDIR}/tests/ParametersTest.o \
	${TESTDIR}/tests/PathTest.o \
	${TESTDIR}/tests/StringToolTest.o \
	${TESTDIR}/tests/streamfilertestrunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread
CXXFLAGS=-pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/usr/lib/x86_64-linux-gnu/libcppunit.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/streamfiler

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/streamfiler: /usr/lib/x86_64-linux-gnu/libcppunit.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/streamfiler: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/streamfiler ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/clientsocket.o: clientsocket.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clientsocket.o clientsocket.cpp

${OBJECTDIR}/filenamegenerator.o: filenamegenerator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filenamegenerator.o filenamegenerator.cpp

${OBJECTDIR}/filewriter.o: filewriter.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filewriter.o filewriter.cpp

${OBJECTDIR}/iparameters.o: iparameters.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iparameters.o iparameters.cpp

${OBJECTDIR}/itimerexec.o: itimerexec.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/itimerexec.o itimerexec.cpp

${OBJECTDIR}/log.o: log.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/log.o log.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/parameters.o: parameters.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parameters.o parameters.cpp

${OBJECTDIR}/path.o: path.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/path.o path.cpp

${OBJECTDIR}/receiver.o: receiver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/receiver.o receiver.cpp

${OBJECTDIR}/serversocket.o: serversocket.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/serversocket.o serversocket.cpp

${OBJECTDIR}/stringtool.o: stringtool.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stringtool.o stringtool.cpp

${OBJECTDIR}/timedexecutor.o: timedexecutor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/timedexecutor.o timedexecutor.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/FileNameGeneratorTest.o ${TESTDIR}/tests/ParametersTest.o ${TESTDIR}/tests/PathTest.o ${TESTDIR}/tests/StringToolTest.o ${TESTDIR}/tests/streamfilertestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lcppunit `cppunit-config --libs`   


${TESTDIR}/tests/FileNameGeneratorTest.o: tests/FileNameGeneratorTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -DUNITTEST -I/usr/include/cppunit -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/FileNameGeneratorTest.o tests/FileNameGeneratorTest.cpp


${TESTDIR}/tests/ParametersTest.o: tests/ParametersTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -DUNITTEST -I/usr/include/cppunit -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ParametersTest.o tests/ParametersTest.cpp


${TESTDIR}/tests/PathTest.o: tests/PathTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -DUNITTEST -I/usr/include/cppunit -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/PathTest.o tests/PathTest.cpp


${TESTDIR}/tests/StringToolTest.o: tests/StringToolTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -DUNITTEST -I/usr/include/cppunit -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/StringToolTest.o tests/StringToolTest.cpp


${TESTDIR}/tests/streamfilertestrunner.o: tests/streamfilertestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -DUNITTEST -I/usr/include/cppunit -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/streamfilertestrunner.o tests/streamfilertestrunner.cpp


${OBJECTDIR}/clientsocket_nomain.o: ${OBJECTDIR}/clientsocket.o clientsocket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/clientsocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/clientsocket_nomain.o clientsocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/clientsocket.o ${OBJECTDIR}/clientsocket_nomain.o;\
	fi

${OBJECTDIR}/filenamegenerator_nomain.o: ${OBJECTDIR}/filenamegenerator.o filenamegenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filenamegenerator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filenamegenerator_nomain.o filenamegenerator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filenamegenerator.o ${OBJECTDIR}/filenamegenerator_nomain.o;\
	fi

${OBJECTDIR}/filewriter_nomain.o: ${OBJECTDIR}/filewriter.o filewriter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filewriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/filewriter_nomain.o filewriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filewriter.o ${OBJECTDIR}/filewriter_nomain.o;\
	fi

${OBJECTDIR}/iparameters_nomain.o: ${OBJECTDIR}/iparameters.o iparameters.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/iparameters.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/iparameters_nomain.o iparameters.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/iparameters.o ${OBJECTDIR}/iparameters_nomain.o;\
	fi

${OBJECTDIR}/itimerexec_nomain.o: ${OBJECTDIR}/itimerexec.o itimerexec.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/itimerexec.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/itimerexec_nomain.o itimerexec.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/itimerexec.o ${OBJECTDIR}/itimerexec_nomain.o;\
	fi

${OBJECTDIR}/log_nomain.o: ${OBJECTDIR}/log.o log.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/log.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/log_nomain.o log.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/log.o ${OBJECTDIR}/log_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/parameters_nomain.o: ${OBJECTDIR}/parameters.o parameters.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/parameters.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/parameters_nomain.o parameters.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/parameters.o ${OBJECTDIR}/parameters_nomain.o;\
	fi

${OBJECTDIR}/path_nomain.o: ${OBJECTDIR}/path.o path.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/path.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/path_nomain.o path.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/path.o ${OBJECTDIR}/path_nomain.o;\
	fi

${OBJECTDIR}/receiver_nomain.o: ${OBJECTDIR}/receiver.o receiver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/receiver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/receiver_nomain.o receiver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/receiver.o ${OBJECTDIR}/receiver_nomain.o;\
	fi

${OBJECTDIR}/serversocket_nomain.o: ${OBJECTDIR}/serversocket.o serversocket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/serversocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/serversocket_nomain.o serversocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/serversocket.o ${OBJECTDIR}/serversocket_nomain.o;\
	fi

${OBJECTDIR}/stringtool_nomain.o: ${OBJECTDIR}/stringtool.o stringtool.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/stringtool.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/stringtool_nomain.o stringtool.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/stringtool.o ${OBJECTDIR}/stringtool_nomain.o;\
	fi

${OBJECTDIR}/timedexecutor_nomain.o: ${OBJECTDIR}/timedexecutor.o timedexecutor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/timedexecutor.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I/usr/include/cppunit -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/timedexecutor_nomain.o timedexecutor.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/timedexecutor.o ${OBJECTDIR}/timedexecutor_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

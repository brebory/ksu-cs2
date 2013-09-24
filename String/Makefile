#============================================================================
#  string class makefile
#
#  Notes:
#
#===========================================================================

CXX           = g++
#INCLUDE_OPT   = -I. -I-
INCLUDE_OPT   = -iquote .
DOPT          = -a

CXX_FLAGS   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow 
#CXX_FLAGS   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow -Wreorder -Weffc++ -pedantic 

ECHO = /bin/echo

STRING_O = string.o
STRING_H = string.h

#DEF = -DSTD_STRING   # No longer needed

#VOPT = -v

#-------------------------------------------------------------------------------
TEST_PROG_01 = test_ctor_c_string_equals
TEST_PROG_02 = test_size
TEST_PROG_03 = test_index
TEST_PROG_04 = test_ctor_default
TEST_PROG_05 = test_ctor_copy
TEST_PROG_06 = test_ctor_int_char
TEST_PROG_07 = test_c_str
TEST_PROG_08 = test_capacity
TEST_PROG_09 = test_swap
TEST_PROG_10 = test_assign
TEST_PROG_11 = test_add_assign_char
TEST_PROG_12 = test_add_char
TEST_PROG_13 = test_add_assign_string
TEST_PROG_14 = test_add_string
TEST_PROG_15 = test_resize
TEST_PROG_16 = test_clear
TEST_PROG_17 = test_less_than
TEST_PROG_18 = test_less_than_or_equal
TEST_PROG_19 = test_greater_than
TEST_PROG_20 = test_greater_than_or_equal
TEST_PROG_21 = test_not_equals
TEST_PROG_22 = test_substr
TEST_PROG_23 = test_find
TEST_PROG_24 = test_output
TEST_PROG_25 = test_input
TEST_PROG_26 = test_getline
TEST_PROG_27 = test_add_assign2

#-------------------------------------------------------------------------------
TEST_PROG_DIR   = ../../cs23001_instructor/String/Test_Progs/
DRIVER_PROG_DIR = ../../cs23001_instructor/String/Drivers/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   t1  or ${TEST_PROG_01}'
	@echo '   t2  or ${TEST_PROG_02}'
	@echo '   t3  or ${TEST_PROG_03}'
	@echo '   t4  or ${TEST_PROG_04}'
	@echo '   t5  or ${TEST_PROG_05}'
	@echo '   t6  or ${TEST_PROG_06}'
	@echo '   t7  or ${TEST_PROG_07}'
	@echo '   t8  or ${TEST_PROG_08}'
	@echo '   t9  or ${TEST_PROG_09}'
	@echo '   t10 or ${TEST_PROG_10}'
	@echo '   t11 or ${TEST_PROG_11}'
	@echo '   t12 or ${TEST_PROG_12}'
	@echo '   t13 or ${TEST_PROG_13}'
	@echo '   t14 or ${TEST_PROG_14}'
	@echo '   t15 or ${TEST_PROG_15}'
	@echo '   t16 or ${TEST_PROG_16}'
	@echo '   t17 or ${TEST_PROG_17}'
	@echo '   t18 or ${TEST_PROG_18}'
	@echo '   t19 or ${TEST_PROG_19}'
	@echo '   t20 or ${TEST_PROG_20}'
	@echo '   t21 or ${TEST_PROG_21}'
	@echo '   t22 or ${TEST_PROG_22}'
	@echo '   t23 or ${TEST_PROG_23}'
	@echo '   t24 or ${TEST_PROG_24}'
	@echo '   t25 or ${TEST_PROG_25}'
	@echo '   t26 or ${TEST_PROG_26}'
	@echo '   t27 or ${TEST_PROG_27}'
	@echo '   tests  - runs t1, t2, ...'
	@echo 'Note: each test depends on the previous tests.'
	@echo 'Targets for compiling individual test programs:'
	@echo '   p1, p2, etc.'
	@echo '   progs'
	@echo 'Other Targets:'
	@echo '   driver      - Compile current directory file driver.cpp'
	@echo '   tm1 tm2 ... tm27   - Memory leak tests'
	@echo '   tm                 - All memory leak tests'
	@echo '   testall            - Runs t1, t2, ... and memory leak tests'
	@echo '   clean'
	@echo 'Note: To have make ignore errors use the options "-ik", ex:'
	@echo '   make -ik t6'

#===========================================================================
# Compile using std::string
# If std::string is used the local string.cpp is compiled but not used.
# This is because in the test_% rule STRING_O is replaced when the file is
# parsed, I couldn't see an easy to eliminate this dependency.
std_string: DEF = -DSTD_STRING
std_string: STRING_O = 
std_string: STRING_H = 
std_string: tests
	@echo 'std::string used.'

#===========================================================================
# Compile string.o
string.o:	string.h  string.cpp
	${CXX} ${CXX_FLAGS} ${INCLUDE_OPT} -c string.cpp  ${COMPILER_OUT_2}

err: COMPILER_OUTFILE = compiler_output.txt
err: COMPILER_OUT_1 = >& ${COMPILER_OUTFILE}
err: COMPILER_OUT_2 = >> ${COMPILER_OUTFILE} 2>&1
err: compiler_note string.o p27
	@${ECHO} ''

#===========================================================================
# Compile local driver file
driver.o:	string.h  driver.cpp
	${CXX} ${CXX_FLAGS} ${DEF} -c driver.cpp

driver:	driver.o  string.o
	${CXX} ${CXX_FLAGS} ${DEF} driver.o string.o -o driver

#===========================================================================
# Compile test programs

#----------------------------------------------------------------------------
test_%: ${STRING_O} test_%.o
	${CXX} ${STRING_O} test_$*.o -o test_$*  ${COMPILER_OUT_2}

test_%.o:	${STRING_H}  ${TEST_PROG_DIR}test_%.cpp
	${CXX} ${CXX_FLAGS} ${DEF} ${INCLUDE_OPT} -c ${TEST_PROG_DIR}test_$*.cpp  ${COMPILER_OUT_2}

#===========================================================================
.PRECIOUS: test_%.o driver_%.o

#===========================================================================
# Compile test programs

p1:  ${TEST_PROG_01}
p2:  ${TEST_PROG_02} p1
p3:  ${TEST_PROG_03} p2
p4:  ${TEST_PROG_04} p3
p5:  ${TEST_PROG_05} p4
p6:  ${TEST_PROG_06} p5
p7:  ${TEST_PROG_07} p6
p8:  ${TEST_PROG_08} p7
p9:  ${TEST_PROG_09} p8
p10: ${TEST_PROG_10} p9
p11: ${TEST_PROG_11} p10
p12: ${TEST_PROG_12} p11
p13: ${TEST_PROG_13} p12
p14: ${TEST_PROG_14} p13
p15: ${TEST_PROG_15} p14
p16: ${TEST_PROG_16} p15
p17: ${TEST_PROG_17} p16
p18: ${TEST_PROG_18} p17
p19: ${TEST_PROG_19} p18
p20: ${TEST_PROG_20} p19
p21: ${TEST_PROG_21} p20
p22: ${TEST_PROG_22} p21
p23: ${TEST_PROG_23} p22
p24: ${TEST_PROG_24} p23
p25: ${TEST_PROG_25} p24
p26: ${TEST_PROG_26} p25
p27: ${TEST_PROG_27} p26
p99: p27

progs: COMPILER_OUTFILE = compiler_output.txt
progs: COMPILER_OUT_1 = >& ${COMPILER_OUTFILE}
progs: COMPILER_OUT_2 = >> ${COMPILER_OUTFILE} 2>&1
progs: compiler_note p99
	@${ECHO} '-----------------------------------------------------------------' ${COMPILER_OUT_2}
	@${ECHO} 'Done compiling.'

compiler_note:
	@${ECHO} 'Any output from the compiler is between the dashed lines.'         ${COMPILER_OUT_1}
	@${ECHO} 'There should not be any output from the compiler.'                 ${COMPILER_OUT_2}
	@${ECHO} 'Warnings should not be ignored, they indicate potential problems.' ${COMPILER_OUT_2}
	@${ECHO} '-----------------------------------------------------------------' ${COMPILER_OUT_2}

testprogs:  p99
	@${ECHO} "Test programs done compiling."

#===========================================================================
# Run test programs

testall:  tests tm
	@echo "All test programs done running."

tests: t0 t27
	@echo "Main test programs done running."

t0: 
	@echo "Test programs running ..."

t1: p1 ${TEST_PROG_01}
	${Q}./${TEST_PROG_01}                    ${PROG_OUT_2}

t2: p2 t1
	${Q}./${TEST_PROG_02}                    ${PROG_OUT_2}

t3: p3 t2
	${Q}./${TEST_PROG_03}                    ${PROG_OUT_2}

t4: p4 t3
	${Q}./${TEST_PROG_04}                    ${PROG_OUT_2}

t5: p5 t4
	${Q}./${TEST_PROG_05}                    ${PROG_OUT_2}

t6: p6 t5
	${Q}./${TEST_PROG_06}                    ${PROG_OUT_2}

t7: p7 t6
	${Q}./${TEST_PROG_07}                    ${PROG_OUT_2}

t8: p8 t7
	${Q}./${TEST_PROG_08}                    ${PROG_OUT_2}

t9: p9 t8
	${Q}./${TEST_PROG_09}                    ${PROG_OUT_2}

t10: p10 t9
	${Q}./${TEST_PROG_10}                    ${PROG_OUT_2}

t11: p11 t10
	${Q}./${TEST_PROG_11}                    ${PROG_OUT_2}

t12: p12 t11
	${Q}./${TEST_PROG_12}                    ${PROG_OUT_2}

t13: p13 t12
	${Q}./${TEST_PROG_13}                    ${PROG_OUT_2}

t14: p14 t13
	${Q}./${TEST_PROG_14}                    ${PROG_OUT_2}

t15: p15 t14
	${Q}./${TEST_PROG_15}                    ${PROG_OUT_2}

t16: p16 t15
	${Q}./${TEST_PROG_16}                    ${PROG_OUT_2}

t17: p17 t16
	${Q}./${TEST_PROG_17}                    ${PROG_OUT_2}

t18: p18 t17
	${Q}./${TEST_PROG_18}                    ${PROG_OUT_2}

t19: p19 t18
	${Q}./${TEST_PROG_19}                    ${PROG_OUT_2}

t20: p20 t19
	${Q}./${TEST_PROG_20}                    ${PROG_OUT_2}

t21: p21 t20
	${Q}./${TEST_PROG_21}                    ${PROG_OUT_2}

t22: p22 t21
	${Q}./${TEST_PROG_22}                    ${PROG_OUT_2}

t23: p23 t22
	${Q}./${TEST_PROG_23}                    ${PROG_OUT_2}

t24: p24 t23
	${Q}./${TEST_PROG_24}                    ${PROG_OUT_2}

t25: p25 t24
	${Q}./${TEST_PROG_25}                    ${PROG_OUT_2}

t26: p26 t25
	${Q}./${TEST_PROG_26}                    ${PROG_OUT_2}

t27: p27 t26
	${Q}./${TEST_PROG_27}                    ${PROG_OUT_2}

tm1: p1
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_01}      ${PROG_OUT_2}

tm2: p2
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_02}      ${PROG_OUT_2}

tm3: p3
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_03}      ${PROG_OUT_2}

tm4: p4
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_04}      ${PROG_OUT_2}

tm5: p5
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_05}      ${PROG_OUT_2}

tm6: p6
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_06}      ${PROG_OUT_2}

tm7: p7
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_07}      ${PROG_OUT_2}

tm8: p8
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_08}      ${PROG_OUT_2}

tm9: p9
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_09}      ${PROG_OUT_2}

tm10: p10
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_10}      ${PROG_OUT_2}

tm11: p11
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_11}      ${PROG_OUT_2}

tm12: p12
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_12}      ${PROG_OUT_2}

tm13: p13
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_13}      ${PROG_OUT_2}

tm14: p14
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_14}      ${PROG_OUT_2}

tm15: p15
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_15}      ${PROG_OUT_2}

tm16: p16
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_16}      ${PROG_OUT_2}

tm17: p17
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_17}      ${PROG_OUT_2}

tm18: p18
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_18}      ${PROG_OUT_2}

tm19: p19
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_19}      ${PROG_OUT_2}

tm20: p20
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_20}      ${PROG_OUT_2}

tm21: p21
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_21}      ${PROG_OUT_2}

tm22: p22
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_22}      ${PROG_OUT_2}

tm23: p23
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_23}      ${PROG_OUT_2}

tm24: p24
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_24}      ${PROG_OUT_2}

tm25: p25
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_25}      ${PROG_OUT_2}

tm26: p26
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_26}      ${PROG_OUT_2}

tm27: p27 
	/usr/bin/valgrind  ${VOPT} ./${TEST_PROG_27}      ${PROG_OUT_2}

tm: tm1 tm2 tm3 tm4 tm5 tm6 tm7 tm8 tm9  tm10 tm11 tm12 tm13 tm14 tm15 tm16 tm17 tm18 tm19 tm20 tm21 tm22 tm23 tm24 tm25 tm26 tm27
	@echo "Done running memory tests"

#===========================================================================
# Run, output to a file

runo: PROGRAM_OUTFILE  = program_output.txt
runo: PROG_OUT_1 = >& ${PROGRAM_OUTFILE}
runo: PROG_OUT_2 = >> ${PROGRAM_OUTFILE} 2>&1
runo: run
	@${ECHO} ''

runom: PROGRAM_OUTFILE  = memory_test_output.txt
runom: PROG_OUT_1 = >& ${PROGRAM_OUTFILE}
runom: PROG_OUT_2 = >> ${PROGRAM_OUTFILE} 2>&1
runom: tm
	@${ECHO} ''

#run: runmsg t27 tm1 tm2 tm3
run: runmsg t27
	@${ECHO} ''

runmsg:
	@${ECHO} '===============================================================' ${PROG_OUT_1}
	@${ECHO} Program: String                                                   ${PROG_OUT_2}
	@${ECHO} '---------------------------------------------------------------' ${PROG_OUT_2}
	@${ECHO} 'This file contains the output from running your programs.'       ${PROG_OUT_2}
	@${ECHO} 'There will be an error message if a program did not compile.'    ${PROG_OUT_2}
	@${ECHO} 'There is a message output before each test is run.'              ${PROG_OUT_2}
	@${ECHO} 'There will not be any output from tests that pass.'              ${PROG_OUT_2}
	@${ECHO} '---------------------------------------------------------------' ${PROG_OUT_2}
	@${ECHO} ''                                                                ${PROG_OUT_2}

#============================================================================
clean:
	rm -f test_*
	rm -f driver
	rm -f *.o a.out
	rm -f core*

veryclean: clean
	rm -f *out.txt
	rm -f compiler_output.txt
	rm -f program_output.txt memory_test_output.txt
	rm -f testing_output.txt


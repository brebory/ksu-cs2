#############################################################################
#  Log assignment makefile
#===========================================================================

DATA_DIR  = ~dhaverst/public_html/CS2_Data/Log/
OUT_DIR   = ./

GXX           = g++
COMPILE_OPT   = -g -O -Wall -W -Wunused -Wuninitialized -Wshadow 

PROG_1        = log_view
PROG_2        = test_split
PROG_3        = split
PROGS         = ${PROG_1} ${PROG_2} ${PROG_3}

PROGS_RUN1  = r1a r2a r3a r4a r5a
PROGS_RUN2  = r1h r2h r3h r4h r5h
PROGS_RUN3  = r1c r2c r3c r4c r5c

PROGRAM_OUTFILE  = program_output.txt
COMPILER_OUTFILE = compiler_output.txt

#===========================================================================
msg:
	@ echo 'Compile targets:'
	@ echo '    ' ${PROGS} 
	@ echo '    '
	@ echo 'Run targets:'
	@ echo '    ' tests
	@ echo '    ' ${PROGS_RUN1}
	@ echo '    ' ${PROGS_RUN2}
	@ echo '    ' ${PROGS_RUN3}
	@ echo '    '
	@ echo 'Other targets:'
	@ echo '    ' 'clean'

#===========================================================================
log_view: log_view.o log_view_main.o
	${GXX} ${COMPILE_OPT} log_view.o log_view_main.o -o log_view    ${COMPILER_OUT_2}

log_view_main.o: log_view.h  log_view_main.cpp                          ${COMPILER_OUT_2}
	${GXX} ${COMPILE_OPT}  -c log_view_main.cpp                     ${COMPILER_OUT_2}

log_view.o: log_view.h  log_view.cpp
	${GXX} ${COMPILE_OPT} ${DEF}  -c log_view.cpp                   ${COMPILER_OUT_2}

test_split: test_split.o log_view.o
	${GXX} ${COMPILE_OPT} test_split.o log_view.o -o test_split     ${COMPILER_OUT_2}
	
test_split.o: test_split.cpp
	${GXX} ${COMPILE_OPT} ${DEF}  -c test_split.cpp                 ${COMPILER_OUT_2}

split: split.o log_view.o
	${GXX} ${COMPILE_OPT} split.o log_view.o -o split               ${COMPILER_OUT_2}
	
split.o: split.cpp
	${GXX} ${COMPILE_OPT} ${DEF}  -c split.cpp                       ${COMPILER_OUT_2}

#===========================================================================
progs: COMPILER_OUT_1 = >&${COMPILER_OUTFILE}
progs: COMPILER_OUT_2 = >>${COMPILER_OUTFILE} 2>&1
progs: compiler_note ${PROGS}
	@echo '-----------------------------------------------------------------' ${COMPILER_OUT_2}
	@echo 'Done compiling: ' ${PROGS}

compiler_note:
	@echo 'Any output from the compiler is between the dashed lines.'         ${COMPILER_OUT_1}
	@echo 'There should not be any output from the compiler.'                 ${COMPILER_OUT_2}
	@echo 'Warnings should not be ignored, they indicate potential problems.' ${COMPILER_OUT_2}
	@echo '-----------------------------------------------------------------' ${COMPILER_OUT_2}

all: ${PROGS}
	@echo 'Done compiling: ' ${PROGS}

#===========================================================================
# Run programs

tests: test_split
	./test_split

r1a: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -a log_1_tiny.txt

r1h: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -h log_1_tiny.txt

r1c: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -c log_1_tiny.txt

r2a: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -a log_2_small.txt

r2h: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -h log_2_small.txt

r2c: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -c log_2_small.txt

r3a: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -a log_3_medium.txt

r3h: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -h log_3_medium.txt

r3c: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -c log_3_medium.txt

r4a: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -a ${DATA_DIR}log_4_large.txt

r4h: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -h ${DATA_DIR}log_4_large.txt

r4c: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -c ${DATA_DIR}log_4_large.txt

r5a: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -a ${DATA_DIR}log_5_huge.txt

r5h: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -h ${DATA_DIR}log_5_huge.txt

r5c: ${PROG_1}
	@echo '==============================================='
	./${PROG_1} -c ${DATA_DIR}log_5_huge.txt

#===========================================================================
#run: runmsg ${PROG_1} ${PROG_2} run1 run2 run3
run: clean progs runmsg ${PROG_1} ${PROG_2} run1 run2 run3
	@echo ''

runmsg: PROG_OUT_1 = >&${PROGRAM_OUTFILE}
runmsg: PROG_OUT_2 = >>${PROGRAM_OUTFILE} 2>&1
runmsg:
	@echo -n 'Start running ...  '
	@echo 'This file contains the output from running your programs.'       ${PROG_OUT_1}
	@echo ''                                                                ${PROG_OUT_2}
	@echo 'There will be an error message if a program did not compile.'    ${PROG_OUT_2}

runsplit: PROG_OUT_1 = >&${PROGRAM_OUTFILE}
runsplit: PROG_OUT_2 = >>${PROGRAM_OUTFILE} 2>&1
runsplit: split
	@echo '===============================================================' ${PROG_OUT_2}
	@echo ./${PROG_2}                                                       ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}

run1: PROG_OUT_1 = >&${PROGRAM_OUTFILE}
run1: PROG_OUT_2 = >>${PROGRAM_OUTFILE} 2>&1
run1: ${PROG_1}
	@echo ''                                                                ${PROG_OUT_2}
	@echo '===============================================================' ${PROG_OUT_2}
	@echo Program: ${PROG_1}                                                ${PROG_OUT_2}
	@echo '---------------------------------------------------------------' ${PROG_OUT_2}
	@echo ./${PROG_1} -a ${DATA_DIR}log_2_small.txt                   ${PROG_OUT_2}
	@./${PROG_1} -a ${DATA_DIR}log_2_small.txt                        ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}
	@echo '---------------------------------------------------------------' ${PROG_OUT_2}
	@echo ./${PROG_1} -h ${DATA_DIR}log_2_small.txt                   ${PROG_OUT_2}
	@./${PROG_1} -h ${DATA_DIR}log_2_small.txt                        ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}
	@echo '---------------------------------------------------------------' ${PROG_OUT_2}
	@echo ./${PROG_1} -c ${DATA_DIR}log_2_small.txt                   ${PROG_OUT_2}
	@./${PROG_1} -c ${DATA_DIR}log_2_small.txt                        ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}

run2: PROG_OUT_1 = >&${PROGRAM_OUTFILE}
run2: PROG_OUT_2 = >>${PROGRAM_OUTFILE} 2>&1
run2: ${PROG_1}
	@echo '---------------------------------------------------------------' ${PROG_OUT_2}
	@echo ./${PROG_1} -h ${DATA_DIR}log_4_large.txt                   ${PROG_OUT_2}
	@./${PROG_1} -h ${DATA_DIR}log_4_large.txt                        ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}

run3: PROG_OUT_1 = >&${PROGRAM_OUTFILE}
run3: PROG_OUT_2 = >>${PROGRAM_OUTFILE} 2>&1
run3: ${PROG_1}
	@echo '---------------------------------------------------------------' ${PROG_OUT_2}
	@echo ./${PROG_1} -c ${DATA_DIR}log_5_huge.txt                    ${PROG_OUT_2}
	@./${PROG_1} -c ${DATA_DIR}log_5_huge.txt                         ${PROG_OUT_2}
	@echo ''                                                                ${PROG_OUT_2}

#===========================================================================
clean:
	rm -f $(PROGS)
	rm -f *.o a.out
	rm -f core*

veryclean: clean
	rm -f $(PROGRAM_OUTFILE)
	rm -f $(COMPILER_OUTFILE)


CC = gcc -Wall -Werror -Wextra

FLAGS = -lcheck
NAME=3D_viewer.app


DIST_PATH := ../archive
DOC_PATH := ../documentation/
ARCHIVENAME=3DViewerArchive
REPORTNAME=Report
OUTTESTSNAME=a.out
OUTDIRPATH=build
SRC_DIR= ./3d_viewer/
CFLAGS_NEW=-Wall -Wextra -Werror -std=c11
GCOV_NEW=-fprofile-arcs -ftest-coverage -fPIC
FILES_NEW=c.c
CMAKE = cmake

OS=$(shell uname)
ifeq ($(OS), Linux)
QMAKE = /home/fbillye/Qt/6.2.4/gcc_64/bin/qmake
FLAGS += -lm -lpthread -lrt -lsubunit
OPEN = open ./report
NAME = untitled
endif

all: install gcov_report


gcov_report: test
	lcov -t "3dViewer" -o 3dviewer.info -c -d .
	genhtml -o report 3dviewer.info
ifeq (${OS}, Linux)
		cd report && firefox index.html
else
		cd report && open index.html
endif

test:
	gcc test.c -c
	gcc ${GCOV_NEW} ${CFLAGS_NEW} -lcheck -pthread -lm -L. ${FILES_NEW} test.o
	./a.out

test.a: test.o
	ar rc libtest.a *.o
	ranlib libtest.a
	cp libtest.a test.a

test.o: ${FILES_NEW}
	gcc ${CFLAGS_NEW} -c ${FILES_NEW}

rebuild: clean all

install: 
# mkdir build_new
# mkdir $(HOME)/Desktop/viewer
# mkdir $(HOME)/Desktop/viewer/models
# tar -xvf ../Архив.zip
# cp -rf heart.obj $(HOME)/Desktop/viewer/models
# cp -rf FullSword.obj $(HOME)/Desktop/viewer/models
# cp -rf Ball.obj $(HOME)/Desktop/viewer/models
# cd build_new && cmake ./../3d_viewer/CMakeLists.txt && make
# cp -rf build_new/3dView.app $(HOME)/Desktop/viewer/3DViewer.app
# rm -rf heart.obj FullSword.obj Ball.obj
	@mkdir -p $(OUTDIRPATH)
	cd $(OUTDIRPATH); $(CMAKE) ../3d_viewer; $(CMAKE) --build . --target all

run:
	build/Viewer/3d_viewer.app/Contents/MacOS/3d_viewer

uninstall:
	@rm -rf build

# gcov_report: test_build
# 	lcov -t "test" -o test.info -c -d .
# 	genhtml -o report test.info
# 	open report/index.html


clean:
	@rm -rf *.o *.a a.out $(REPORTNAME) $(OUTTESTSNAME) a.out.dSYM
	@rm -rf *.gcno *.gcda 
	@rm -rf $(OUTFILENAME) $(ARCHIVENAME).tar.gz
	@rm -rf $(ARCHIVENAME) .qtc_clangd *.gch *.pro.user .vscode
	@rm -rf html


dist: install
	@tar -czf ../$(ARCHIVENAME).tar.gz ./$(TESTFILE) ./Makefile 3d_viewer/*.pro 3d_viewer/*.cpp ./*.c ./*.h ./test.c

dvi:
	doxygen Doxyfile
	open ./html/index.html
# open ./documentation/html/index.html


# install_new:
# 	qmake CONFIG+=release -o Makefile $(SRC_DIR)/3d_viewer.pro && make


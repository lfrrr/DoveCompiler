env/conan_profile:
	conan profile update settings.compiler.libcxx=libstdc++11 default
	

env/conan:
	pip3 install conan

env/antlr:
	mkdir -p res/antlr
	cd res/antlr && curl -O https://www.antlr.org/download/antlr-4.12.0-complete.jar

env/compiler:
	sudo apt-get install arm-linux-gnueabihf-gcc arm-linux-gnueabihf-ld

includes/runtime: res/conan/conanfile.txt
	mkdir -p $@
	cd $@ && conan install ../../res/conan


includes/generated: res/antlr/SysY.g4 res/antlr/CommonLex.g4 res/antlr/antlr-4.12.0-complete.jar
	mkdir -p $@
	cd res/antlr && java -Xmx500M -cp "antlr-4.12.0-complete.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -visitor -no-listener -package front SysY.g4 -o ../../includes/generated
	touch $@

allres = includes/runtime includes/generated

build/bin/DoveCompiler:
	mkdir -p build
	cd build && cmake .. -G "Unix Makefiles" && make DoveCompiler

.PHONY: env/conan env/antlr includes/runtime include/generated all clean build test
.DEFAULT_GOAL := all

all: ${allres}

clean:
	rm -rf build

build: build/bin/DoveCompiler
		@build/bin/DoveCompiler --help
		cp build/bin/DoveCompiler compiler 

include tests/config.mk
testFileBase ?= main

test:	
	mkdir -p build && cd build && cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Build && make
	build/bin/DoveCompiler tests/${testFileBase}.sysy -o tests/${testFileBase}.S ${options}
	cp build/bin/DoveCompiler compiler 

test_show_ast: res/antlr/SysY.g4 res/antlr/CommonLex.g4
	antlr4-parse res/antlr/SysY.g4 res/antlr/CommonLex.g4 compUnit tests/${testFileBase}.sysy -gui

test_cat_asm: 
	cp tests/${testFileBase}.sysy tests/a.cc || g++ -S -O0 -o tests/a.s tests/a.cc
	cat tests/a.s

include tests/raspi.mk

test_remote:
	mkdir -p build && cd build && cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Build && make
	build/bin/DoveCompiler tests/${testFileBase}.sysy -o build/bin/${testFileBase}.S ${options}
	cp build/bin/DoveCompiler compiler 
	arm-linux-gnueabihf-gcc build/bin/${testFileBase}.S -c -o build/bin/${testFileBase}.o
	arm-linux-gnueabihf-ld build/bin/${testFileBase}.o -lc -o build/bin/${testFileBase}
	scp build/bin/${testFileBase} ${user}@${ip}:${path}
	ssh ${user}@${ip} "cd ${path} && ${path}/${testFileBase}"

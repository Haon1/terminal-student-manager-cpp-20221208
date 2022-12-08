#!/bin/bash

declare -r NONE="\033[m"
declare -r LIGHT_RED="\033[1;31m"
declare -r LIGHT_GREEN="\033[1;32m"
declare -r YELLOW="\033[1;33m"
declare -r LIGHT_BLUE="\033[1;34m"
declare -r PURPLE="\033[1;35m"
declare -r WHITE="\033[1;37m"
declare -r RED="\033[2;31m"

SRC_DIR=./src
INC_DIR=./include
OUT_DIR=./out
BIN_DIR=${OUT_DIR}/bin
DEST=${BIN_DIR}/stuMgr



#Create Output Directory
function create_out_dir()
{
    mkdir -p ${BIN_DIR}
}


function Red_Msg()
{
    echo -e "$LIGHT_RED $@ $NONE"
}

function Green_Msg()
{
    echo -e "$LIGHT_GREEN $@ $NONE"
}


function Blue_Msg()
{
    echo -e "$LIGHT_BLUE $@ $NONE"
}

function Purple_Msg()
{
    echo -e "$PURPLE $@ $NONE"
}


function Do_Make()
{
    g++ ${SRC_DIR}/*.cpp -I${INC_DIR} -o ${DEST}       
}


#Create Output Directory
if [ ! -e ${OUT_DIR} ]; then
    Blue_Msg "###  Create Output Directory  ###"
    create_out_dir
fi

###  begin to compile
Purple_Msg "###  Start Compile  ###"
Do_Make
if [ "$?" == "0" ];then
Green_Msg "\n###  make completed successfully  ###\n"
else
Red_Msg "\n###  make Error  ###\n"
fi
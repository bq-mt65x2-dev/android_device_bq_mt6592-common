#!/bin/sh

echo $1
rootdirectory="$PWD"
# ---------------------------------

dirs="external/icu external/wpa_supplicant_8 frameworks/av frameworks/base frameworks/opt/telephony packages/apps/Snap system/bt system/core system/netd"

# red + nocolor
RED='\033[0;31m'
NC='\033[0m'

for dir in $dirs ; do
	cd $rootdirectory
	cd $dir
    echo -e "\n${RED}Applying ${NC}$dir ${RED}patches...${NC}\n"
	git apply -v $rootdirectory/device/bq/mt6592-common/patches/$dir/*.patch
done

# -----------------------------------
echo -e "Done !\n"
cd $rootdirectory
